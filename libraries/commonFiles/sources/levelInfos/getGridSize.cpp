#include "levelInfos/getGridSize.h"
#include "pathsFunctions/pathsFunctions.h"
#include "logging/logsStruct.h"
#include <sstream>
#include <cstdlib>

Offset getLevelGridSize(AppLogFiles& logs, const fs::path& levelGridPath)
{
	Offset gridSize{ -1, -1 };
	if( std::ifstream gridFile{ levelGridPath } )
	{
		std::string fileLine;
		if( std::getline( gridFile, fileLine ) )
		{
			int sizeIndex{0};
			std::istringstream lineStream{ fileLine };
			if( lineStream >> sizeIndex >> gridSize.y >> gridSize.x && sizeIndex == -1 )
			{
				logs.warning << "The level grid size of '" << levelGridPath.string() << "' has been read with success, it is (width x height): " 
							<< gridSize.x << " x " << gridSize.y << ".\n";
				return gridSize;
			}
			else{
				logs.error << "Error: couldn't extract data of read first line of '" << levelGridPath.string() << "' level grid file.\n";
				return gridSize;
			}
		}
		else{
			logs.error << "Error: couldn't read first line of '" << levelGridPath.string() << "' level grid file.\n";
			return gridSize;
		}
	}
	else{
		logs.error.wrFileOpeningError( levelGridPath, "load size of the level grid" );
		return gridSize;
	}
}

std::string getLevelGridSizeText(const std::string& languageText, const Offset& levelSize)
{
	return std::string{ languageText + std::to_string( levelSize.x ) + " x " + std::to_string( levelSize.y ) };
}