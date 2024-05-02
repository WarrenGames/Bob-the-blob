#include "levels/balloons/balloonsPositionsData.h"
#include "exceptions/readErrorExcept.h"
#include "levels/textures/balloonsConsts.h"
#include <string>
#include <fstream>
#include <cassert>

BalloonsPositions::BalloonsPositions():
	positions{ BalloonsMax, PerZoneBalloons }
{
	loadBalloonDataFromFile(positions);
}

std::size_t BalloonsPositions::getScreenEnumMax() const
{
	return positions.width();
}

std::size_t BalloonsPositions::getPerZoneNumber() const
{
	return positions.height();
}

const BalloonInfos& BalloonsPositions::getElement(std::size_t screenPositionEnum, std::size_t balloonNumber) const
{
	assert( screenPositionEnum < positions.width() );
	assert( balloonNumber < positions.height() );
	return positions(screenPositionEnum, balloonNumber);
}

bool BalloonsPositions::activateNewBalloonIfPossible(std::size_t screenPositionEnum, unsigned contentType, unsigned typeSubValue)
{
	if( screenPositionEnum != BalloonsMax )
	{
		assert( screenPositionEnum < positions.width() );
		for( std::size_t i{0} ; i < positions.height() ; ++i )
		{
			if( positions(screenPositionEnum, i).isOccupied == false )
			{
				positions(screenPositionEnum, i).contentType = contentType;
				positions(screenPositionEnum, i).typeSubValue = typeSubValue;
				positions(screenPositionEnum, i).isOccupied = true;
				return true;
			}
		}
	}
	return false;
}

std::vector< BalloonInfos >::const_iterator BalloonsPositions::begin() const
{
	return positions.begin();
}

std::vector< BalloonInfos >::const_iterator BalloonsPositions::end() const
{
	return positions.end();
}

void BalloonsPositions::resetAllBalloons()
{
	for( auto &balloon : positions )
	{
		balloon.isOccupied = false;
	}
}

void loadBalloonDataFromFile(MatrixTemp2D< BalloonInfos >& balloons)
{
	if( std::ifstream balloonPositionFile{ BalloonsPositionsFile } )
	{
		std::string fileLine;
		for( std::size_t i{0} ; i < BalloonsMax ; ++i )
		{
			if( std::getline( balloonPositionFile, fileLine ) )			
			{
				std::istringstream lineStream{ fileLine };
				readBalloonPositionLine(balloons, lineStream, i);
			}
			else{
				throw ReadError{"couldn't read line number " + std::to_string(i) + " in '" + std::string{ BalloonsPositionsFile }
									+ "' file in order to load balloons screen positions.\n"};
			}
		}
	}
	else{
		 throw ReadError{"couldn't open '" + std::string{BalloonsPositionsFile} + "' file in order to load balloons positions.\n"};
	}
}

void readBalloonPositionLine(MatrixTemp2D< BalloonInfos >& balloons, std::istringstream& lineStream, std::size_t screenPositionEnum)
{
	Coord2D coords;
	for( std::size_t i{0} ; i < PerZoneBalloons ; ++i )
	{
		if( lineStream >> coords.width >> coords.height )
		{
			balloons(screenPositionEnum, i) = BalloonInfos{coords};
		}
		else{
			throw ReadError{"couldn't read data ( iteration number " + std::to_string(i) + " ) in '" 
							+ std::string{BalloonsPositionsFile} + "' file in order to load balloons positions.\n"};
		}
	}
}