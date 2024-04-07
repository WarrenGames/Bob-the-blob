#include "levels/mapSubDivisions/loadSubdivisionData.h"
#include "levels/global/levelMandatoryData.h"
#include "pathsFunctions/pathsFunctions.h"
#include "exceptions/readErrorExcept.h"
#include "levels/mapSubDivisions/subdivisionsConsts.h"
#include <string>
#include <fstream>

void loadLevelSubdivision(SubDivisionFileData& subDivisionFileData, const fs::path& subDivFilePath)
{
	if( std::ifstream subDivFile{ subDivFilePath } )
	{
		int index{0};
		std::size_t fileLineNumber{1};
		std::string fileLine;
		while( std::getline( subDivFile, fileLine ) )
		{
			std::istringstream lineStream{ fileLine };
			if( lineStream >> index )
			{
				actAccordingToIndex(subDivisionFileData, lineStream, index, subDivFilePath, fileLineNumber );
			}
			fileLineNumber++;
		}
	}
	else{
		subDivisionFileData.isLoadingPerfect = false;
		throw ReadError{"Error: couldn't open '" + subDivFilePath.string() + "' file in order to load level spawn sub divisions.\n"};
	}
}

void actAccordingToIndex(SubDivisionFileData& subDivisionFileData, std::istringstream& lineStream, int readIndex, const fs::path& dataFilePath, std::size_t fileLineNumber)
{
	switch( readIndex )
	{
		case subDiv::SubdivisionsNumberIndex:
			loadSubDivisionPartsNumber(subDivisionFileData, lineStream, dataFilePath, fileLineNumber);
			break;
		case subDiv::SubDivisionsLinksIndex:
			loadSubDivisionLinksCoords(subDivisionFileData, lineStream, dataFilePath, fileLineNumber);
			break;
		default:
			throw ReadError{"Error: bad index in '" + dataFilePath.string() + "' file: " + std::to_string(readIndex) + " .\n"};
			break;
	}
}

void loadSubDivisionPartsNumber(SubDivisionFileData& subDivisionFileData, std::istringstream& lineStream, const fs::path& dataFilePath, std::size_t fileLineNumber)
{
	Coord2D coords;
	if( lineStream >> coords.width >> coords.height )
	{
		subDivisionFileData.zonesNumber = coords;
	}
	else{
		throw ReadError{"Error: couldn't read subdivisions number in '" + dataFilePath.string() + "' file at line number " + std::to_string(fileLineNumber) + " .\n"};
	}
}

void loadSubDivisionLinksCoords(SubDivisionFileData& subDivisionFileData, std::istringstream& lineStream, const fs::path& dataFilePath, std::size_t fileLineNumber)
{
	std::pair< Coord2D, Coord2D > pairs;
	if( lineStream >> pairs.first.width >> pairs.first.height >> pairs.second.width >> pairs.second.height )
	{
		subDivisionFileData.loadLinkData(pairs, fileLineNumber, dataFilePath);
	}
	else{
		throw ReadError{"Error: couldn't read subdivisions 'links' in '" + dataFilePath.string() + "' file at line number " + std::to_string(fileLineNumber) + " .\n"};
	}
}
