#ifndef MAKE_PARAGRAPHS_TEXTURES_H
#define MAKE_PARAGRAPHS_TEXTURES_H

//Functions that create blocks of texts ready for displaying

#include "texturing/texturesCombo.h"
#include <vector>
#include <string>
#include <iosfwd>

struct AppLogFiles;
namespace sdl2{ class RendererWindow; }
struct TextureCombo;
struct ParagraphData;
struct ParagraphMakeComponents;

namespace makeText{
	
	void openFileForReading(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, ParagraphData& paragraphData, std::vector< TextureCombo >& textTextures);

	void loadFont(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, ParagraphData& paragraphData, std::vector< TextureCombo >& textTextures, std::ifstream& inputFile);

	void readFileWords(std::ifstream& inputFile, ParagraphData& paragraphData);

	void createTextTextures(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, ParagraphData& paragraphData, std::vector< TextureCombo >& textTextures);

	void testWordsLineWidth(ParagraphData& paragraphData, ParagraphMakeComponents& pComp);

	void actWithTestedWords(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, ParagraphData& paragraphData, std::vector< TextureCombo >& textTextures, ParagraphMakeComponents& pComp);

	void creatingLineImpossible(AppLogFiles& logs, const std::vector<std::string>& wordsStock, std::size_t i);
}

#endif //MAKE_PARAGRAPHS_TEXTURES_H