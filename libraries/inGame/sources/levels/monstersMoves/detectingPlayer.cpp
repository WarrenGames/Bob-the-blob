#include "levels/monstersMoves/detectingPlayer.h"
#include "levels/maps/gameMap.h"
#include "levels/monstersMoves/pathElement.h"
#include "levels/textures/texturesConsts.h"
#include "levels/monstersMoves/monstersMovesConsts.h"

bool hasPlayerBeenDetected(const GameMap& gameMap, const Coord2D& destination, const Coord2D& origin, int rangeBeforeDetection, std::vector< IdealPathChunk >& idealPath)
{
	return hasPlayerBeenDetectedOnBobbysLeft(gameMap, destination, origin, rangeBeforeDetection, idealPath) 
		|| hasPlayerBeenDetectedOnBobbysRight(gameMap, destination, origin, rangeBeforeDetection, idealPath)
		|| hasPlayerBeenDetectedOnBobbysTop(gameMap, destination, origin, rangeBeforeDetection, idealPath)
		|| hasPlayerBeenDetectedOnBobbysBottom(gameMap, destination, origin, rangeBeforeDetection, idealPath);
}

bool hasPlayerBeenDetectedOnBobbysLeft(const GameMap& gameMap, const Coord2D& destination, const Coord2D& origin, int rangeBeforeDetection, std::vector< IdealPathChunk >& idealPath)
{
	for( int i{0} ; i < rangeBeforeDetection ; ++i )
	{
		if( gameMap.matrix.isSignedInsideBoundaries(static_cast<int>(origin.width) - i, static_cast<int>(origin.height) ) )
		{
			if( isSquareAWall(static_cast<int>(origin.width) - i, static_cast<int>(origin.height), gameMap ) )
			{
				return false;
			}
			else if( static_cast<int>(destination.width) == static_cast<int>(origin.width) - i
					&& destination.height == origin.height )
			{
				fillWesternDetection(destination, origin, rangeBeforeDetection, idealPath);
				return true;
			}
		}
	}
	return false;
}

bool hasPlayerBeenDetectedOnBobbysRight(const GameMap& gameMap, const Coord2D& destination, const Coord2D& origin, int rangeBeforeDetection, std::vector< IdealPathChunk >& idealPath)
{
	for( int i{0} ; i < rangeBeforeDetection ; ++i )
	{
		if( gameMap.matrix.isSignedInsideBoundaries(static_cast<int>(origin.width) + i, static_cast<int>(origin.height) ) )
		{
			if( isSquareAWall(static_cast<int>(origin.width) + i, static_cast<int>(origin.height), gameMap ) )
			{
				return false;
			}
			else if( static_cast<int>(destination.width) == static_cast<int>(origin.width) + i
				&& destination.height == origin.height )
			{
				fillEasternDetection(destination, origin, rangeBeforeDetection, idealPath, gameMap);
				return true;
			}
			
		}
	}
	return false;
}

bool hasPlayerBeenDetectedOnBobbysTop(const GameMap& gameMap, const Coord2D& destination, const Coord2D& origin, int rangeBeforeDetection, std::vector< IdealPathChunk >& idealPath)
{
	for( int i{0} ; i < rangeBeforeDetection ; ++i )
	{
		if( gameMap.matrix.isSignedInsideBoundaries(static_cast<int>(origin.width), static_cast<int>(origin.height) - i ) )
		{
			if( isSquareAWall(static_cast<int>(origin.width), static_cast<int>(origin.height) - i, gameMap ) )
			{
				return false;
			}
			else if( static_cast<int>(destination.height) == static_cast<int>(origin.height) - i
				&& destination.width == origin.width )
			{
				fillNorthernDetection(destination, origin, rangeBeforeDetection, idealPath);
				return true;
			}
		}
	}
	return false;
}

bool hasPlayerBeenDetectedOnBobbysBottom(const GameMap& gameMap, const Coord2D& destination, const Coord2D& origin, int rangeBeforeDetection, std::vector< IdealPathChunk >& idealPath)
{
	for( int i{0} ; i < rangeBeforeDetection ; ++i )
	{
		if( gameMap.matrix.isSignedInsideBoundaries(static_cast<int>(origin.width), static_cast<int>(origin.height) + i ) )
		{
			if( isSquareAWall(static_cast<int>(origin.width), static_cast<int>(origin.height) + i, gameMap ) )
			{
				return false;
			}
			else if( static_cast<int>(destination.height) == static_cast<int>(origin.height) + i
				&& destination.width == origin.width )
			{
				fillSouthernDetection(destination, origin, rangeBeforeDetection, idealPath, gameMap);
				return true;
			}
		}
	}
	return false;
}

bool isSquareAWall(int width, int height, const GameMap& gameMap)
{
	if( gameMap.matrix.isSignedInsideBoundaries(width, height) )
	{
		return gameMap.matrix(width, height).mapIndex > 0;
	}
	else{
		return true;
	}
}

void fillWesternDetection(const Coord2D& destination, const Coord2D& origin, int rangeBeforeDetection, std::vector< IdealPathChunk >& idealPath)
{
	for( int i{0} ; i < rangeBeforeDetection && destination.width <= origin.width - i ; ++i )
	{
		if( static_cast<int>(origin.width) >= i )
		{
			fillIdealPathChunk(origin.height, idealPath[i].coords.height, origin.width - i, idealPath[i].coords.width);
			fillOtherInfos(RoadToWest, idealPath[i]);
		}
	}
}

void fillEasternDetection(const Coord2D& destination, const Coord2D& origin, int rangeBeforeDetection, std::vector< IdealPathChunk >& idealPath, const GameMap& gameMap)
{
	for( int i{0} ; i < rangeBeforeDetection && destination.width >= origin.width + i ; ++i )
	{
		if( origin.width + i < gameMap.matrix.width() )
		{
			fillIdealPathChunk(origin.height, idealPath[i].coords.height, origin.width + i, idealPath[i].coords.width);
			fillOtherInfos(RoadToEast, idealPath[i]);
		}
	}
}

void fillNorthernDetection(const Coord2D& destination, const Coord2D& origin, int rangeBeforeDetection, std::vector< IdealPathChunk >& idealPath)
{
	for( int i{0} ; i < rangeBeforeDetection && destination.height <= origin.height - i ; ++i )
	{
		if( static_cast<int>(origin.height) >= i )
		{
			fillIdealPathChunk(origin.width, idealPath[i].coords.width, origin.height - i, idealPath[i].coords.height);
			fillOtherInfos(RoadToNorth, idealPath[i]);
		}
	}
}

void fillSouthernDetection(const Coord2D& destination, const Coord2D& origin, int rangeBeforeDetection, std::vector< IdealPathChunk >& idealPath, const GameMap& gameMap)
{
	for( int i{0} ; i < rangeBeforeDetection && destination.height >= origin.height + i ; ++i )
	{
		if( origin.height + i < gameMap.matrix.height() )
		{
			fillIdealPathChunk(origin.width, idealPath[i].coords.width, origin.height + i, idealPath[i].coords.height);
			fillOtherInfos(RoadToSouth, idealPath[i]);
		}
	}
}

void fillIdealPathChunk(std::size_t constantValue, std::size_t& constantAxisValue, std::size_t changingAxisValue, std::size_t& changingAxisCoordValue)
{
	constantAxisValue = constantValue;
	changingAxisCoordValue = changingAxisValue;
}

void fillOtherInfos(unsigned directionEnumValue, IdealPathChunk& idealPathChunk)
{
	idealPathChunk.setEffectiveDirection( directionEnumValue );
	idealPathChunk.isRelevant = true;
}