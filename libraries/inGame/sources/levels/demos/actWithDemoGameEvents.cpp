#include "levels/demos/actWithDemoGameEvents.h"
#include "levels/global/levelMandatoryData.h"
#include "levels/demosRecordingAndPlaying/data/dataPackage.h"
#include "levels/demosRecordingAndPlaying/data/determineGameStatus.h"
#include "levels/playerAttributes/playerAttributes.h"
#include "levels/demosRecordingAndPlaying/consts/gameEventsConsts.h"
#include "levels/maps/mapsConsts.h"
#include <cassert>

void demos::handleGameEvents(LevelMandatoryData& levelData, std::optional<demos::DataPackage>& demoDataPackage, PlayerAttributes& playerAttributes)
{
	if( demos::getGameStatus(demoDataPackage) == demos::GameIsDemo )
	{
		while( demoDataPackage->gameEvents.getCommandsNumber() > 0 && demoDataPackage->gameEvents.hasLastTimeElapsed() )
		{
			demos::actWithSingleEvent(levelData, demoDataPackage->gameEvents.getLastElement(), playerAttributes, demoDataPackage->haveBobbysStartMoving );
			demoDataPackage->gameEvents.pop_back();
		}
	}
}

void demos::actWithSingleEvent(LevelMandatoryData& levelData, const demos::GameEvent& gameEvent, PlayerAttributes& playerAttributes, bool& haveBobbysStartMoving)
{
	switch( gameEvent.category )
	{
		case demos::eventCat::Bob:
			demos::actWithEnemyBobEvent(levelData, gameEvent, playerAttributes, haveBobbysStartMoving);
			break;
		case demos::eventCat::GameWon:
		
			break;
		default:
			assert( false && "Error: bad event category value !" );
			break;
	}
}

void demos::actWithEnemyBobEvent(LevelMandatoryData& levelData, const demos::GameEvent& gameEvent, PlayerAttributes& playerAttributes, bool& haveBobbysStartMoving)
{
	switch( gameEvent.subType )
	{
		case demos::eventSubBob::CatchPlayer:
			demos::playerWasCaughtByBob(levelData, haveBobbysStartMoving);
			break;
		case demos::eventSubBob::EatenByPlayer:
			demos::playerAteOneBob(levelData, gameEvent, playerAttributes);
			break;
		default:
			assert( false && "Error: bad 'sub' bob event category value !" );
			break;
	}
}

void demos::playerWasCaughtByBob(LevelMandatoryData& levelData, bool& haveBobbysStartMoving)
{
	levelData.playerData.resetPosition();
	levelData.bobsPackage.resetAllBobsPositions();
	levelData.bobsPackage.makeBobsNotSeekingPlayer();
	haveBobbysStartMoving = false;
}

void demos::playerAteOneBob(LevelMandatoryData& levelData, const demos::GameEvent& gameEvent, PlayerAttributes& playerAttributes)
{
	assert( gameEvent.id < levelData.bobsPackage.size() );
	levelData.bobsPackage.getElement(gameEvent.id).disableBob();
	playerAttributes.addToScore(map::BobEatingWorth);
}
