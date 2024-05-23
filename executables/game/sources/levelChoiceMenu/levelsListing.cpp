#include "levelChoiceMenu/levelsListing.h"
#include "package/essentials.h"
#include "pathsFunctions/pathsFunctions.h"
#include "levelInfos/getGridSize.h"
#include "texturing/texturePosition.h"
#include "texts/textLoader.h"
#include "levelChoiceMenu/levelChoiceMenuConsts.h"
#include "consts/screenConsts.h"
#include "consts/levelsTypesConsts.h"
#include "consts/filesAndPaths.h"
#include <fstream>
#include <cassert>

LevelChunk::LevelChunk(Essentials& essentials, const sdl2::Font& font, const std::string buttonText, const std::string& levelName_, const TexturePosition& position, unsigned levelType_):
	textButton{ essentials.logs, essentials.rndWnd, font, buttonText, levelChoice::SelectedButtonColor, levelChoice::OffButtonColor, position },
	levelName{ levelName_ },
	levelType{ levelType_ }
{
	
}

LevelChunk::LevelChunk(Essentials& essentials, const sdl2::Font& font, const std::string& levelName_, const TexturePosition& position, unsigned levelType_):
	textButton{ essentials.logs, essentials.rndWnd, font, levelName_, levelChoice::SelectedButtonColor, levelChoice::OffButtonColor, position },
	levelName{ levelName_ },
	levelType{ levelType_ }
{
	
}

LevelsListing::LevelsListing(Essentials& essentials, const sdl2::Font& listFont, const fs::path& path, unsigned listGoal):
	listCurrentPage{ 0 }
{
	if( fs::is_regular_file( path ) && listGoal == ListOfLevels )
	{
		//In case of list file
		populateList(essentials, listFont, path);
	}
	else if( fs::is_directory( path ) && listGoal == ListOfDemosFilesInDir )
	{
		//In case of directory (browsing it)
		readDirectoryFiles(essentials, listFont, path);
	}
}

void LevelsListing::drawCurrentPage(Essentials& essentials) const
{
	if( levelsList.empty() == false )
	{
		if( listCurrentPage < levelsList.size() )
		{
			for( auto const &chunk : levelsList[listCurrentPage] )
			{
				chunk.textButton.drawButton(essentials.rndWnd);
			}
		}
	}
}

void LevelsListing::seeNextPageIfAny()
{
	if( listCurrentPage + 1 < levelsList.size() )
	{
		listCurrentPage++;
	}
}

void LevelsListing::seePrecedentPageIfAny()
{
	if( listCurrentPage > 0 )
	{
		listCurrentPage--;
	}
}

void LevelsListing::updateCurrentPageButtons(Essentials& essentials)
{
	if( levelsList.empty() == false )
	{
		if( listCurrentPage < levelsList.size() )
		{
			for( auto &chunk : levelsList[listCurrentPage] )
			{
				chunk.textButton.updateButton(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
			}
		}
	}
}

std::size_t LevelsListing::size() const
{
	return levelsList.size();
}

std::vector< LevelChunk >::const_iterator LevelsListing::begin() const
{
	return levelsList[listCurrentPage].cbegin();
}

std::vector< LevelChunk >::const_iterator LevelsListing::end() const
{
	return levelsList[listCurrentPage].cend();
}

void LevelsListing::populateList(Essentials& essentials, const sdl2::Font& listFont, const fs::path& filesList)
{
	if( std::ifstream levelListFile{ filesList } )
	{
		int levelsNumber{0};
		std::size_t fileLineNumber{1};
		std::string fileLine;
		while( std::getline( levelListFile, fileLine ) )
		{
			std::istringstream lineStream{ fileLine };
			createLevelChunk(essentials, listFont, lineStream, levelsNumber, fileLineNumber);
			fileLineNumber++;
		}
	}
	else{
		essentials.logs.error << "Error: couldn't open '" << levelChoice::LevelsListFilePath << "' file in order to load levels list.\n";
	}
}

void LevelsListing::createLevelChunk(Essentials& essentials, const sdl2::Font& listFont, std::istringstream& lineStream, int& levelsNumber, std::size_t fileLineNumber)
{
	const TextsBlocks languagesTexts{ essentials.logs.error, path::getLanguageFile(essentials.chosenLanguage, LanguageFile), TxtMax };
	std::string levelName;
	unsigned levelType{ LevelMax };
	if( lineStream >> levelName >> levelType )
	{
		if( levelsNumber % levelChoice::LevelsPerPage == 0 )
		{
			levelsList.emplace_back( std::vector<LevelChunk>() );
		}
		levelsList.back().emplace_back( LevelChunk{essentials, listFont, levelName 
			+ getLevelGridSizeText(languagesTexts[TxtGridSize], getLevelGridSize(essentials.logs, path::getGameConfigFilePath(levelName, files::DefaultMapsExtension) ) ), 
			levelName,
			TexturePosition{GameScreenWidth / 2, (levelsNumber % levelChoice::LevelsPerPage) * SQR_SIZE + SQR_SIZE * 2, true, true}, levelType } );
		levelsNumber++;
	}
	else{
		essentials.logs.error << "Error: couldn't read level info in '" << levelChoice::LevelsListFilePath << "' file at line number " << fileLineNumber << " .\n";
	}
}

void LevelsListing::readDirectoryFiles(Essentials& essentials, const sdl2::Font& listFont, const fs::path& initialDirectory)
{
	assert( fs::is_directory(initialDirectory) );
	int levelsNumber{0};
	
	for( auto const& dir_entry : std::filesystem::directory_iterator{initialDirectory} )
	{
		if( fs::is_regular_file(dir_entry) )
		{
			if( levelsNumber % levelChoice::LevelsPerPage == 0 )
			{
				levelsList.emplace_back( std::vector< LevelChunk >() );
			}
			levelsList.back().emplace_back( LevelChunk{ essentials, listFont, dir_entry.path().string(), 
								TexturePosition{GameScreenWidth / 2, (levelsNumber % levelChoice::LevelsPerPage) * SQR_SIZE + SQR_SIZE * 2, true, true}, 0 } );
			levelsNumber++;
		}
	}
}