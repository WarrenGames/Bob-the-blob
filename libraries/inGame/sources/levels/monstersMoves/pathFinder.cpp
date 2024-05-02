#include "levels/monstersMoves/pathFinder.h"
#include "levels/gameActors/playerThings/playerMoving.h"
#include "levels/gameActors/bobThings/bobTheBlob.h"
#include "levels/maps/gameMap.h"
#include "levels/monstersMoves/detectingPlayer.h"
#include "levels/gameActors/playerActorsConsts.h"
#include "levels/textures/texturesConsts.h"
#include "levels/monstersMoves/monstersMovesConsts.h"
#include <cassert>
#include <algorithm>

PathFinder::PathFinder(int detectionRange_):
	idealPath( actors::PlayerDetectionRange * 2 ),
	currentNextPosition{ idealPath.begin() },
	oldPosition{ idealPath.begin() },
	detectionRange{ detectionRange_ }
{
	
}

std::size_t PathFinder::size() const
{
	return idealPath.size();
}

const IdealPathChunk& PathFinder::operator[](std::size_t index) const
{
	return idealPath[index];
}

IdealPathChunk& PathFinder::operator[](std::size_t index)
{
	return idealPath[index];
}

void PathFinder::updatePathToPlayer(const GameMap& gameMap, const Coord2D& origin, const Coord2D& destination, bool& canSeekPlayer, unsigned& currentDirection)
{
	if( false == canSeekPlayer )
		tryToDetectPresence(gameMap, origin, destination, canSeekPlayer, currentDirection);
}

void PathFinder::tryToDetectPresence(const GameMap& gameMap, const Coord2D& origin, const Coord2D& destination, bool& canSeekPlayer, unsigned& currentDirection)
{
	if( hasPlayerBeenDetectedOnBobbysLeft(gameMap, destination, origin, detectionRange, idealPath) )
	{
		currentDirection = RoadToWest;
		actWhenFound(canSeekPlayer);
	}
	if( hasPlayerBeenDetectedOnBobbysRight(gameMap, destination, origin, detectionRange, idealPath) )
	{
		currentDirection = RoadToEast;
		actWhenFound(canSeekPlayer);
	}
	if( hasPlayerBeenDetectedOnBobbysTop(gameMap, destination, origin, detectionRange, idealPath) )
	{
		currentDirection = RoadToNorth;
		actWhenFound(canSeekPlayer);
	}
	if( hasPlayerBeenDetectedOnBobbysBottom(gameMap, destination, origin, detectionRange, idealPath) )
	{
		currentDirection = RoadToSouth;
		actWhenFound(canSeekPlayer);
	}
}

std::vector< IdealPathChunk >::const_iterator PathFinder::begin() const
{
	return idealPath.begin();
}

std::vector< IdealPathChunk >::const_iterator PathFinder::end() const
{
	return idealPath.end();
}

const IdealPathChunk& PathFinder::getMostRecentChunk() const
{
	return *currentNextPosition;
}

const IdealPathChunk& PathFinder::getOldChunk() const
{
	return *oldPosition;
}

IdealPathChunk& PathFinder::getOldChunk()
{
	return *oldPosition;
}

void PathFinder::addNewCoordinatesToFollow(const GameMap& gameMap, const Coord2D& playerCoordinates)
{
	if( gameMap.matrix.isInsideBoundaries(playerCoordinates) )
	{
		if( false == coords::are2DCoordsTheSame(playerCoordinates, currentNextPosition->coords) )
		{
			const auto oldNextIterator{ currentNextPosition };
			advanceNewCoordPosition();
			currentNextPosition->isRelevant = true;
			currentNextPosition->coords = playerCoordinates;
			setResultingNewDirection(oldNextIterator);
		}
	}
}

void PathFinder::advanceOldPosition()
{
	advanceGivenPosition(oldPosition);
}

void PathFinder::advanceNewCoordPosition()
{
	advanceGivenPosition(currentNextPosition);
}

void PathFinder::forgetFollowing()
{
	for( auto &square : idealPath )
	{
		square.coords.width = 0;
		square.coords.height = 0;
		square.setFlagOff();
	}
	oldPosition = idealPath.begin();
	currentNextPosition = idealPath.begin();
}

void PathFinder::setResultingNewDirection(const std::vector< IdealPathChunk >::iterator& oldNextIterator)
{
	if( coords::isNewCoordOnTopFromSecond(currentNextPosition->coords, oldNextIterator->coords) )
	{
		oldNextIterator->setEffectiveDirection( RoadToNorth );
	}
	else if( coords::isNewCoordToLeftFromSecond(currentNextPosition->coords, oldNextIterator->coords) )
	{
		oldNextIterator->setEffectiveDirection( RoadToWest );
	}
	else if( coords::isNewCoordToBottomFromSecond(currentNextPosition->coords, oldNextIterator->coords) )
	{
		oldNextIterator->setEffectiveDirection( RoadToSouth );
	}
	else if( coords::isNewCoordToRightFromSecond(currentNextPosition->coords, oldNextIterator->coords) )
	{
		oldNextIterator->setEffectiveDirection( RoadToEast );
	}
	else{
		assert( false && "Error: bad direction value to set." );
	}
}

void PathFinder::actWhenFound(bool& canSeekPlayer)
{
	setCurrentNextPositionIterator();
	oldPosition = idealPath.begin();
	canSeekPlayer = true;
}

void PathFinder::advanceGivenPosition(std::vector< IdealPathChunk >::iterator& position)
{
	assert( position != idealPath.end() );
	position++;
	if( position == idealPath.end() )
	{
		position = idealPath.begin();
	}
}

void PathFinder::setCurrentNextPositionIterator()
{
	currentNextPosition = std::find_if( std::begin( idealPath ), std::end( idealPath ), [](auto const& chunk){ return chunk.isRelevant == false; } );
	
	if( currentNextPosition != idealPath.begin() )
	{
		currentNextPosition--;
	}
	else{
		currentNextPosition = idealPath.end() - 1;
	}
}