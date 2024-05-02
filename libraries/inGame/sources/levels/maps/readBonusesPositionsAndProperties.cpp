#include "levels/maps/readBonusesPositionsAndProperties.h"
#include "levels/maps/bonusesMap.h"
#include "exceptions/readErrorExcept.h"
#include "levels/textures/texturesConsts.h"
#include <fstream>

void openBonusesDataFile(BonusesMap& bonusesMap, const fs::path& dataFilePath, const std::string& filePurpose)
{
	if( std::ifstream applesFile{ dataFilePath } )
	{
		std::string fileLine;
		std::size_t fileLineNum{1};
		while( std::getline( applesFile, fileLine ) )
		{
			std::istringstream lineStream{ fileLine };
			readBonusesData(bonusesMap, dataFilePath, filePurpose, lineStream, fileLineNum);
			fileLineNum++;
		}
	}
	else{
		throw ReadError{"Opening '" + dataFilePath.string() + "' data file for " + filePurpose + " in order to load its starting position impossible."};
	}
}

void readBonusesData(BonusesMap& bonusesMap, const fs::path& dataFilePath, const std::string& filePurpose, std::istringstream& lineStream, std::size_t fileLineNum)
{
	BonusElement bonusElement;
	Coord2D coordinates;
	if( lineStream >> bonusElement.bonusIndex >> coordinates.width >> coordinates.height >> bonusElement.bonusProperty )
	{
		if( bonusesMap.areCoordinatesInsideBoundaries(coordinates) )
		{
			bonusesMap.getElement(coordinates) = bonusElement;
			bonusesMap.getElement(coordinates).bonusProperty = 0;
			bonusesMap.getElement(coordinates).isPresent = true;
		}
		else{
			throw ReadError{"The file for " + filePurpose + "'" + dataFilePath.string() + "' was open with success but bonus coordinates are wrong at line number " 
						+ std::to_string( fileLineNum ) + ".\n"};
		}
	}
	else{
		throw ReadError{"The file for " + filePurpose + "'" + dataFilePath.string() + "' was open with success but reading data failed at line number " 
						+ std::to_string( fileLineNum ) + ".\n"};
	}
}