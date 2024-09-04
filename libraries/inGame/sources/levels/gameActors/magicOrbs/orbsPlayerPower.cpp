#include "levels/gameActors/magicOrbs/orbsPlayerPower.h"
#include "levels/gameActors/playerThings/singlePlayerData.h"
#include "levels/playerAttributes/playerAttributes.h"
#include "levels/demosRecordingAndPlaying/data/dataPackage.h"
#include "levels/demosRecordingAndPlaying/data/determineGameStatus.h"
#include "levels/demosRecordingAndPlaying/consts/gameEventsConsts.h"
#include "levels/gameActors/playerActorsConsts.h"
#include "levels/maps/mapsConsts.h"
#include <cassert>

void greenOrb::checkForPowerEvent(SinglePlayerData& player, std::optional<demos::DataPackage>& demoDataPackage)
{
	if( demos::getGameStatus(demoDataPackage) == demos::GameIsDemo )
	{
		greenOrb::startOrStopPower(player, demoDataPackage->greenOrbRelatedItemsData.greenOrbsAndPlayer);
	}
}

void greenOrb::startOrStopPower(SinglePlayerData& player, demos::Stack< demos::GameEvent >& stack)
{
	if( stack.getCommandsNumber() > 0 && stack.hasLastTimeElapsed() )
	{
		if( stack.getLastElement().category == demos::eventCat::PlayerPowerEnable && stack.getLastElement().subType == demos::playerPower::GreenOrb )
		{
			player.abilities[abilities::CanEatCacti].startAbility();
			player.abilities.setDemoFlag(abilities::CanEatCacti, AbilityStatusOnAndRecorded);
			stack.pop_back();
		}
		else if( stack.getLastElement().category == demos::eventCat::PlayerPowerDisable && stack.getLastElement().subType == demos::playerPower::GreenOrb )
		{
			player.abilities[abilities::CanEatCacti].abortAbility();
			player.abilities.setDemoFlag(abilities::CanEatCacti, AbilityStatusOffAndRecorded);
			stack.pop_back();
		}
		else{
			assert( false && "Error: bad 'demos::GameEvent' structure members value(s)" );
			stack.pop_back();
		}
	}
}
