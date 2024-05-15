#include "levels/demos/updateEnemiesWithDemoData.h"
#include "levels/gameActors/bobThings/bobsPackage.h"
#include "levels/monstersMoves/monstersMovesConsts.h"
#include "levels/demosRecordingAndPlaying/templates/demoStack.h"
#include "levels/demosRecordingAndPlaying/dataToRecord/moveAndPosition.h"
#include <cassert>

void demos::checkNewBobbyPositionEvent(BobsPackage& bobsPackage, std::vector< demos::Stack< demos::MoveAndPosition > >& movesStacks)
{
	for( std::size_t i{0} ; i < movesStacks.size() ; ++i )
	{
		while( movesStacks[i].getCommandsNumber() > 0 && movesStacks[i].hasLastTimeElapsed() )
		{
			demos::actWithNewBobbyPositionEvent(bobsPackage.getElement(i).bobTheBlob, movesStacks[i].getLastElement() );
			movesStacks[i].pop_back();
			if( movesStacks[i].getCommandsNumber() > 0 )
			{
				demos::determineBobbyNextDirection(bobsPackage.getElement(i).bobTheBlob, movesStacks[i].getLastElement().currentPosition);
			}
		}
	}
}

void demos::actWithNewBobbyPositionEvent(BobTheBlob& bobTheBlob, const demos::MoveAndPosition& event)
{
	bobTheBlob.setPosition(event.currentPosition);
}

void demos::determineBobbyNextDirection(BobTheBlob& bobTheBlob, const Coord2D& nextCoords)
{
	if( coords::isNewCoordToRightFromSecond(nextCoords, bobTheBlob.getMatrixPosition() ) )
	{
		bobTheBlob.changeCurrentDirection(RoadToEast);
	}
	else if( coords::isNewCoordOnTopFromSecond(nextCoords, bobTheBlob.getMatrixPosition() ) )
	{
		bobTheBlob.changeCurrentDirection(RoadToNorth);
	}
	else if( coords::isNewCoordToLeftFromSecond(nextCoords, bobTheBlob.getMatrixPosition() ) )
	{
		bobTheBlob.changeCurrentDirection(RoadToWest);
	}
	else if( coords::isNewCoordToBottomFromSecond(nextCoords, bobTheBlob.getMatrixPosition() ) )
	{
		bobTheBlob.changeCurrentDirection(RoadToSouth);
	}
	else{
		bobTheBlob.changeCurrentDirection(RoadMax);
	}
}

void demos::recordNewBobbyPosition(unsigned demoType, const GlobalBob& globalBob, demos::Stack< demos::MoveAndPosition >& movesStack, std::size_t bobIndex)
{
	if( demoType == demos::GameIsRecording && globalBob.isActive )
	{
		if( movesStack.getCommandsNumber() == 0 ) 
		{
			if( false == coords::are2DCoordsTheSame(globalBob.bobTheBlob.getMatrixPosition(), globalBob.bobTheBlob.getStartingPosition() ) )
			{
				demos::stackBobbyPositionData(globalBob, movesStack, bobIndex);
			}
		}
		else if( movesStack.getCommandsNumber() > 0 )
		{
			if( false == coords::are2DCoordsTheSame(globalBob.bobTheBlob.getMatrixPosition(), movesStack.getLastElement().currentPosition ) )
			{
				demos::stackBobbyPositionData(globalBob, movesStack, bobIndex);
			}
		}
	}
}

void demos::recordBobbysPackagePosition(unsigned demoType, const BobsPackage& bobsPackage, std::vector< demos::Stack< demos::MoveAndPosition > >& movesStack)
{
	if( demoType == demos::GameIsRecording )
	{
		assert( bobsPackage.size() == movesStack.size() );
		for( std::size_t i{0} ; i < bobsPackage.size() && i < movesStack.size() ; ++i )
		{
			demos::recordNewBobbyPosition(demoType, bobsPackage.getElement(i), movesStack[i], i);
		}
	}
}

void demos::stackBobbyPositionData(const GlobalBob& globalBob, demos::Stack< demos::MoveAndPosition >& movesStack, std::size_t bobIndex)
{
	movesStack.emplaceElement( demos::MoveAndPosition{ movesStack.getCurrentElapsedMicroSecondsTime(), globalBob.bobTheBlob.getMatrixPosition(),
														static_cast<unsigned>(globalBob.colorIndex), globalBob.bobTheBlob.getCurrentDirection(), 
														static_cast<unsigned>(bobIndex) } );
}

void demos::makeBobbysStartMoving(BobsPackage& bobsPackage, std::vector< demos::Stack< demos::MoveAndPosition > >& enemyBobsMoves, bool& haveBobbysStartMoving)
{
	if( haveBobbysStartMoving == false )
	{
		assert( bobsPackage.size() == enemyBobsMoves.size() );
		for( std::size_t i{0} ; i < bobsPackage.size() && i < enemyBobsMoves.size() ; ++i )
		{
			if( enemyBobsMoves[i].getCommandsNumber() > 0 )
			{
				demos::determineBobbyNextDirection(bobsPackage.getElement(i).bobTheBlob, enemyBobsMoves[i].getLastElement().currentPosition);
			}
		}
		haveBobbysStartMoving = true;
	}
}