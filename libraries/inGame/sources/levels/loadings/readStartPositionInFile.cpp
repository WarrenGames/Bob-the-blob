#include "levels/loadings/readStartPositionInFile.h"
#include "levels/gameActors/bobThings/bobsPackage.h"
#include "exceptions/readErrorExcept.h"
#include "matrices/matrixStructs.h"
#include <fstream>

void loadPositionFromFile(Coord2D& coordinates, const fs::path& dataFilePath, const std::string& filePurpose)
{
	if( std::ifstream positionFile{ dataFilePath } )
	{
		if( !( positionFile >> coordinates.width >> coordinates.height ) )
		{
			throw ReadError{"Opening '" + dataFilePath.string() + "' data file for " + filePurpose + " was done with success, but reading in file failed."};
		}
	}
	else{
		throw ReadError{"Opening '" + dataFilePath.string() + "' data file for " + filePurpose + " in order to load its starting position impossible."};
	}
}

void loadBobsDataFromFile(BobsPackage& bobsPackage, const fs::path& dataFilePath, const std::string& filePurpose)
{
	if( std::ifstream bobsDataFile{ dataFilePath } )
	{
		std::string fileLine;
		std::size_t fileLineNum{1};
		while( std::getline( bobsDataFile, fileLine ) )
		{
			if( fileLine[0] != '#' )
			{
				std::istringstream lineStream{ fileLine };
				loadSingleBobData(bobsPackage, dataFilePath, filePurpose, lineStream, fileLineNum);
			}
			fileLineNum++;
		}
	}
	else{
		throw ReadError{"Opening '" + dataFilePath.string() + "' data file for " + filePurpose + " in order to load its data impossible."};
	}
}

void loadSingleBobData(BobsPackage& bobsPackage, const fs::path& dataFilePath, const std::string& filePurpose, std::istringstream& lineStream, std::size_t fileLineNum)
{
	Coord2D coordinates;
	std::size_t colorIndex{0};
	if( lineStream >> coordinates.width >> coordinates.height >> colorIndex )
	{
		bobsPackage.emplaceBackBob( coordinates, colorIndex );
	}
	else{
		throw ReadError{"The file for " + filePurpose + "'" + dataFilePath.string() + "' was open with success but reading data failed at line number " 
						+ std::to_string( fileLineNum ) + ".\n"};
	}
}