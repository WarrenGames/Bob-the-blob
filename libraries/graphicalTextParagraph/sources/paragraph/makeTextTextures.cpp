#include "paragraph/makeTextTextures.h"
#include "paragraph/paragraphData.h"
#include "logging/logsStruct.h"
#include "text/sdl2ttf_font.h"
#include "texturing/texturePosition.h"

void makeText::openFileForReading(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, ParagraphData& paragraphData, std::vector<TextureCombo>& textTextures)
{
	if( std::ifstream inputFile{ paragraphData.inputFilePath.string() } )
	{
		makeText::loadFont(logs, rndWnd, paragraphData, textTextures, inputFile);
	}
	else{
		logs.error << "Error: couldn't open '" << paragraphData.inputFilePath.string() << "' file to create textures from text.\n";
	}
}

void makeText::loadFont(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, ParagraphData& paragraphData, std::vector<TextureCombo>& textTextures, std::ifstream& inputFile)
{
	makeText::readFileWords(inputFile, paragraphData);
	makeText::createTextTextures(logs, rndWnd, paragraphData, textTextures);
}

void makeText::readFileWords(std::ifstream& inputFile, ParagraphData& paragraphData)
{
	std::string singleWord;
	
	while( inputFile >> singleWord )
	{
		paragraphData.paragraphWords.push_back(singleWord);
	}
}

void makeText::createTextTextures(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, ParagraphData& paragraphData, std::vector<TextureCombo>& textTextures)
{
	if( false == paragraphData.paragraphWords.empty() )
	{
		ParagraphMakeComponents pComp{};
		do
		{
			pComp.initializeData(paragraphData.font, paragraphData.paragraphWords);
			makeText::testWordsLineWidth(paragraphData, pComp);
			makeText::actWithTestedWords(logs, rndWnd, paragraphData, textTextures, pComp);
		}while( pComp.wordsIndex < paragraphData.paragraphWords.size() );
	}
	else{
		logs.error << "Error: couldn't create text textures, because word stock is empty.\n";
	}
}

void makeText::testWordsLineWidth(ParagraphData& paragraphData, ParagraphMakeComponents& pComp)
{
	while( pComp.currentWidth < paragraphData.textWidth && pComp.wordsIndex < paragraphData.paragraphWords.size() )
	{
		pComp.canCreateLine = true;
		pComp.wordsIndex++;
		pComp.correctWords += ( paragraphData.paragraphWords[pComp.wordsIndex - 1] + " " );
		if( pComp.wordsIndex < paragraphData.paragraphWords.size() )
		{
			pComp.overflowWords += ( " " + paragraphData.paragraphWords[pComp.wordsIndex] );
		}
		TTF_SizeUTF8(paragraphData.font.get(), pComp.overflowWords.c_str(), &pComp.currentWidth, &pComp.currentHeight);
	}
}
void makeText::actWithTestedWords(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, ParagraphData& paragraphData, std::vector<TextureCombo>& textTextures, ParagraphMakeComponents& pComp)
{
	if( pComp.canCreateLine )
	{
		textTextures.emplace_back( TextureCombo{logs, rndWnd, paragraphData.font, pComp.correctWords, paragraphData.textColor, TexturePosition{ } } );
	}
	else{
		makeText::creatingLineImpossible(logs, paragraphData.paragraphWords, pComp.wordsIndex);
	}
}

void makeText::creatingLineImpossible(AppLogFiles& logs, const std::vector<std::string>& wordsStock, std::size_t i)
{
	logs.error << "Error: couldn't create text textures because the word " << wordsStock[i] << " is to large.\n";
}