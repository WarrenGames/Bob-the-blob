#include "levels/demos/updatePlayerWithDemoData.h"
#include "levels/gameActors/playerThings/singlePlayerData.h"
#include "levels/maps/gameMap.h"
#include "demos/templates/demoStack.h"
#include "demos/dataToRecord/playerMove.h"
#include "demos/consts/dataRecordingConsts.h"
#include "consts/playerInputsConsts.h"
#include "levels/gameActors/playerActorsConsts.h"

void demos::checkNewPlayerPositionEvent(SinglePlayerData& playerData, demos::Stack< demos::PlayerMove >& movesStack)
{
	while( movesStack.getCommandsNumber() > 0 && movesStack.hasLastTimeElapsed() )
	{
		demos::actWithNewPlayerEvent(playerData.move, movesStack.getLastElement() );
		movesStack.pop_back();
	}
}

void demos::actWithNewPlayerEvent(PlayerMoving& playerMoving, const demos::PlayerMove& event)
{
	assert( event.action < MoveMax );
	if( event.action != MoveStop )
	{
		playerMoving.resetInMatrixPosition(event.position);
		playerMoving.updateRealPositionWithNewCoord2D();
		playerMoving.setMoveState(actors::PlayerIsMoving);
		playerMoving.setNewMoveWithDemoStack(event.action);
	}
	else{
		playerMoving.stopPlayer();
	}
}

void demos::recordNewPlayerMove(SinglePlayerData& playerData, demos::Stack< demos::PlayerMove >& movesStack)
{
	if( playerData.move.hasReachCenterOfSquare() == false && playerData.hasActionBeenRecorded == false )
	{
		if( playerData.move.getCurrentDirection() != MoveStop )
		{
			if( movesStack.getCommandsNumber() > 0 
				&& ! ( coords::are2DCoordsTheSame(playerData.move.getMatrixPosition(), movesStack.getLastElement().position) 
					&& playerData.move.getCurrentDirection() == movesStack.getLastElement().action ) )
			{
				demos::stackNewPlayerPosition(playerData.move, movesStack, playerData.playerId);
				playerData.hasActionBeenRecorded = true;
			}
			else if( movesStack.getCommandsNumber() == 0 )
			{
				demos::stackNewPlayerPosition(playerData.move, movesStack, playerData.playerId);
				playerData.hasActionBeenRecorded = true;
			}
		}
	}
	else if( playerData.move.hasReachCenterOfSquare() )
	{
		playerData.hasActionBeenRecorded = false;
	}
}

void demos::recordNewPlayerStop(SinglePlayerData& playerData, demos::Stack< demos::PlayerMove >& movesStack)
{
	if( playerData.move.hasReachCenterOfSquare() && playerData.hasStopBeenRecorded == false )
	{
		demos::stackNewPlayerPosition(playerData.move, movesStack, playerData.playerId);
		playerData.hasStopBeenRecorded = true;
	}
	else if( playerData.move.hasReachCenterOfSquare() == false )
	{
		playerData.hasStopBeenRecorded = false;
	}
}

void demos::stackNewPlayerPosition(const PlayerMoving& playerMoving, demos::Stack< demos::PlayerMove >& movesStack, unsigned playerId)
{
	movesStack.emplaceElement(demos::PlayerMove{ movesStack.getCurrentElapsedMicroSecondsTime(), playerMoving.getMatrixPosition(), 
																	playerMoving.getCurrentDirection(), playerId } );
}

void demos::stopPlayerAccordingToMap(PlayerMoving& playerMoving, const GameMap& gameMap)
{
	if( playerMoving.hasReachCenterOfSquare() )
	{
		switch( playerMoving.getCurrentDirection() )
		{
			case MoveEast:
				demos::checkMapWallsForPlayer(playerMoving, gameMap, 1, 0);
				break;
			case MoveUp:
				demos::checkMapWallsForPlayer(playerMoving, gameMap, 0, -1);
				break;
			case MoveWest:
				demos::checkMapWallsForPlayer(playerMoving, gameMap, -1, 0);
				break;
			case MoveDown:
				demos::checkMapWallsForPlayer(playerMoving, gameMap, 0, 1);
				break;
		}
	}
}

void demos::checkMapWallsForPlayer(PlayerMoving& playerMoving, const GameMap& gameMap, int x_add, int y_add)
{
	if( false == playerMoving.canGetANewDirection(gameMap, x_add, y_add) )
	{
		playerMoving.stopPlayer();
	}
}