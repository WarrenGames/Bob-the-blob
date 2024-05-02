#include "levels/gameActors/bobThings/bobTheBlob.h"
#include "levels/maps/gameMap.h"
#include "levels/monstersMoves/monstersMovesConsts.h"
#include "consts/includeOptions.h"
#include <cassert>

BobTheBlob::BobTheBlob(const Coord2D& startingPos):
	startingPosition{ startingPos },
	inMatrixPosition{ startingPos },
	currentDirection{ RoadMax },
	hasMovedSince{false}
{
	setRealPosition();
}

const Coord2D& BobTheBlob::getMatrixPosition() const
{
	return inMatrixPosition;
}

const Coord2D& BobTheBlob::getStartingPosition() const
{
	return startingPosition;
}

const Offset& BobTheBlob::getRealPosition() const
{
	return realPosition;
}

void BobTheBlob::setCurrentDirection(unsigned newDirection)
{
	currentDirection = newDirection;
}

unsigned BobTheBlob::getCurrentDirection() const
{
	return currentDirection;
}

unsigned& BobTheBlob::getCurrentDirection()
{
	return currentDirection;
}

bool BobTheBlob::getHasMoveSince() const
{
	return hasMovedSince;
}

void BobTheBlob::setRealPosition()
{
	realPosition.x = static_cast<int>(startingPosition.width) * SQR_SIZE + SQR_SIZE / 2;
	realPosition.y = static_cast<int>(startingPosition.height) * SQR_SIZE + SQR_SIZE / 2;
}

bool BobTheBlob::hasReachCenterOfSquare() const
{
	return realPosition.x % SQR_SIZE == SQR_SIZE / 2 && realPosition.y % SQR_SIZE == SQR_SIZE / 2;
}

void BobTheBlob::checkMoveDelay()
{
	moveBob();
	hasMovedSince = true;
}

void BobTheBlob::moveBob()
{
	switch( currentDirection )
	{
		case RoadToEast:
			realPosition.x += 1;
			break;
		case RoadToNorth:
			realPosition.y -= 1;
			break;
		case RoadToWest:
			realPosition.x -= 1;
			break;
		case RoadToSouth:
			realPosition.y += 1;
			break;
	}
}

void BobTheBlob::setMatrixPosition()
{
	inMatrixPosition.width = realPosition.x / SQR_SIZE;
	inMatrixPosition.height = realPosition.y / SQR_SIZE;
}

void BobTheBlob::resetBobbyPosition()
{
	inMatrixPosition = startingPosition;
	setRealPosition();
}

void BobTheBlob::avoidMapLeaving(const GameMap& gameMap)
{
	avoidMapLeavingFromLeft();
	avoidMapLeavingFromRight(gameMap);
	avoidMapLeavingFromTop();
	avoidMapLeavingFromBottom(gameMap);
}

void BobTheBlob::avoidMapLeavingFromLeft()
{
	if( currentDirection == RoadToWest && inMatrixPosition.width == 0 )
	{
		currentDirection = RoadToEast;
	}
}

void BobTheBlob::avoidMapLeavingFromRight(const GameMap& gameMap)
{
	if( currentDirection == RoadToEast && inMatrixPosition.width + 1 == gameMap.matrix.width() )
	{
		currentDirection = RoadToWest;
	}
}

void BobTheBlob::avoidMapLeavingFromTop()
{
	if( currentDirection == RoadToNorth && inMatrixPosition.height == 0 )
	{
		currentDirection = RoadToSouth;
	}
}

void BobTheBlob::avoidMapLeavingFromBottom(const GameMap& gameMap)
{
	if( currentDirection == RoadToSouth && inMatrixPosition.height + 1 == gameMap.matrix.height() )
	{
		currentDirection = RoadToNorth;
	}
}

void BobTheBlob::setFlagOffHasMovedSince()
{
	hasMovedSince = false;
}

void BobTheBlob::changeCurrentDirection(unsigned newDirection)
{
	currentDirection = newDirection;
}

void BobTheBlob::setPosition(const Coord2D& newCoords)
{
	inMatrixPosition = newCoords;
	realPosition.x = static_cast<int>(inMatrixPosition.width) * SQR_SIZE + SQR_SIZE / 2;
	realPosition.y = static_cast<int>(inMatrixPosition.height) * SQR_SIZE + SQR_SIZE / 2;
}