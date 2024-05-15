#include "levels/gameActors/playerThings/playerMoving.h"
#include "levels/maps/gameMap.h"
#include "levels/loadings/gameConfigurationData.h"
#include "levels/textures/texturesConsts.h"
#include "levels/maps/mapsConsts.h"
#include "consts/playerInputsConsts.h"
#include "levels/gameActors/playerActorsConsts.h"
#include "consts/includeOptions.h"
#include "consts/filesAndPaths.h"

PlayerMoving::PlayerMoving(const GameConfigData& gameConfigData):
	textureDirection{ textures::PlayerDirectionWest },
	wantedNextDirection{ MoveStop },
	currentDirection{ MoveStop },
	moveState{ actors::PlayerIsStopped },
	moveDelay{ gameConfigData.bobMoveDelay },
	canChangeDirection{ true }
{
	
}

const Coord2D& PlayerMoving::getMatrixPosition() const
{
	return inMatrixPosition;
}

const Offset& PlayerMoving::getRealPosition() const
{
	return realPosition;
}

Offset& PlayerMoving::getRealPosition()
{
	return realPosition;
}

unsigned PlayerMoving::getCurrentDirection() const
{
	return currentDirection;
}

bool PlayerMoving::getDirectionChangeAbility() const
{
	return canChangeDirection;
}

void PlayerMoving::setDirectionChangeAbility(bool newValue)
{
	canChangeDirection = newValue;
}

void PlayerMoving::changeWantedDirection(unsigned newDirection)
{
	assert( newDirection < MoveMax );
	wantedNextDirection = newDirection;
}

void PlayerMoving::setCurrentDirection(unsigned newCurrentDirection)
{
	assert( newCurrentDirection < MoveMax );
	currentDirection = newCurrentDirection;
}

bool PlayerMoving::isPlayerStopped() const
{
	return moveState == actors::PlayerIsStopped;
}

void PlayerMoving::resetInMatrixPosition(const Coord2D& newCoord)
{
	inMatrixPosition = newCoord;
}

bool PlayerMoving::hasReachCenterOfSquare() const
{
	return realPosition.x % SQR_SIZE == SQR_SIZE / 2 && realPosition.y % SQR_SIZE == SQR_SIZE / 2;
}

bool PlayerMoving::hasReachOutsideOfMap(const GameMap& gameMap)
{
	return realPosition.x <= 0 
		|| realPosition.x >= static_cast<int>(gameMap.matrix.width() ) * SQR_SIZE
		|| realPosition.y <= 0
		|| realPosition.y >= static_cast<int>(gameMap.matrix.height() ) * SQR_SIZE;
}

void PlayerMoving::setNewMatrixPosition()
{
	if( hasReachCenterOfSquare() )
	{
		inMatrixPosition.width = realPosition.x / SQR_SIZE;
		inMatrixPosition.height = realPosition.y / SQR_SIZE;
	}
}

void PlayerMoving::checkMoveDelayToMove()
{
	if( moveState == actors::PlayerIsMoving && moveTime.hasTimeElapsed(moveDelay) )
	{
		moveTime.joinTimePoints();
		move();
	}
}

void PlayerMoving::move()
{
	switch( currentDirection )
	{
		case MoveEast:
			realPosition.x += 1;
			break;
		case MoveUp:
			realPosition.y -= 1;
			break;
		case MoveWest:
			realPosition.x -= 1;
			break;
		case MoveDown:
			realPosition.y += 1;
			break;
	}
}

void PlayerMoving::resetPositionWhileRestarting(const Coord2D& startingPosition)
{
	realPosition.x = static_cast<int>( startingPosition.width ) * SQR_SIZE + SQR_SIZE / 2 ;
	realPosition.y = static_cast<int>( startingPosition.height ) * SQR_SIZE + SQR_SIZE / 2 ;
}

void PlayerMoving::updateRealPositionWithNewCoord2D()
{
	resetPositionWhileRestarting(inMatrixPosition);
}

void PlayerMoving::stopPlayer()
{
	setMoveState(actors::PlayerIsStopped);
	changeWantedDirection(MoveStop);
	setCurrentDirection(MoveStop);
}

void PlayerMoving::setNewMoveWithDemoStack(unsigned newDirection)
{
	//setMoveState(actors::PlayerIsMoving);
	setCurrentDirection(newDirection);
	changeWantedDirection(newDirection);
}

void PlayerMoving::changePlayerDirection(const GameMap& gameMap)
{
	if( hasReachOutsideOfMap(gameMap) == false &&
		hasReachCenterOfSquare() &&
		gameMap.matrix.isInsideBoundaries(inMatrixPosition) )
	{
		switch( wantedNextDirection )
		{
			case MoveEast:
				setNewDirectionIfAny(gameMap, 1, 0);
				break;
			case MoveUp:
				setNewDirectionIfAny(gameMap, 0, -1);
				break;
			case MoveWest:
				setNewDirectionIfAny(gameMap, -1, 0);
				break;
			case MoveDown:
				setNewDirectionIfAny(gameMap, 0, 1);
				break;
			case MoveStop:
				stopPlayer();
				break;
		}
	}
}

void PlayerMoving::setNewDirectionIfAny(const GameMap& gameMap, int mat_x_add, int mat_y_add)
{
	if( canGetANewDirection(gameMap, mat_x_add, mat_y_add) )
	{
		currentDirection = wantedNextDirection;
		textureDirection = wantedNextDirection;
		setMoveState(actors::PlayerIsMoving);
	}
	else{
		setMoveState(actors::PlayerIsStopped);
	}
}

bool PlayerMoving::canGetANewDirection(const GameMap& gameMap, int mat_x_add, int mat_y_add)
{
	const Offset nextSquareToMoveTo{ static_cast<int>(inMatrixPosition.width) + mat_x_add, static_cast<int>(inMatrixPosition.height) + mat_y_add };
	
	if( gameMap.matrix.isSignedInsideBoundaries(nextSquareToMoveTo.x, nextSquareToMoveTo.y) )
	{
		if( gameMap.matrix(nextSquareToMoveTo.x, nextSquareToMoveTo.y).mapIndex == 0 )
		{
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return true;
	}
}

void PlayerMoving::setMoveState(unsigned newMoveState)
{
	assert( newMoveState == actors::PlayerIsMoving || newMoveState == actors::PlayerIsStopped );
	moveState = newMoveState;
}