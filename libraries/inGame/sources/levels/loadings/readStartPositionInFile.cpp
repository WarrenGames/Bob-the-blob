#include "levels/loadings/readStartPositionInFile.h"
#include "levels/gameActors/bobThings/bobsPackage.h"
#include "exceptions/readErrorExcept.h"
#include "consts/skillLevelsConsts.h"
#include "matrices/matrixStructs.h"
#include <fstream>
#include <bitset>
#include <cassert>

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

void loadBobsDataFromFile(BobsPackage& bobsPackage, const fs::path& dataFilePath, const std::string& filePurpose, unsigned skillLevel)
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
				loadSingleBobData(bobsPackage, dataFilePath, filePurpose, lineStream, fileLineNum, skillLevel);
			}
			fileLineNum++;
		}
	}
	else{
		throw ReadError{"Opening '" + dataFilePath.string() + "' data file for " + filePurpose + " in order to load its data impossible."};
	}
}

void loadSingleBobData(BobsPackage& bobsPackage, const fs::path& dataFilePath, const std::string& filePurpose, std::istringstream& lineStream, std::size_t fileLineNum,
						unsigned skillLevel)
{
	assert( skillLevel < SkillLevelMax );
	Coord2D coordinates;
	std::size_t colorIndex{0};
	unsigned readCombinedSkillLevel{ SkillLevelMax };
	
	if( lineStream >> coordinates.width >> coordinates.height >> colorIndex >> readCombinedSkillLevel )
	{
		std::bitset< SkillLevelMax > combinedSkillData{ readCombinedSkillLevel };
		if( combinedSkillData[skillLevel] )
		{
			bobsPackage.emplaceBackBob( coordinates, colorIndex );
		}
	}
	else{
		throw ReadError{"The file for " + filePurpose + " '" + dataFilePath.string() + "' was open with success but reading data failed at line number " 
						+ std::to_string( fileLineNum ) + ".\n"};
	}
}