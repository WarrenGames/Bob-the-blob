#include "levels/gameActors/magicOrbs/orbsPlayerPower.h"
#include "levels/gameActors/playerThings/singlePlayerData.h"
#include "levels/playerAttributes/playerAttributes.h"
#include "demos/data/dataPackage.h"
#include "demos/data/determineGameStatus.h"
#include "demos/consts/gameEventsConsts.h"
#include "levels/gameActors/playerActorsConsts.h"
#include "levels/maps/mapsConsts.h"

void greenOrb::checkForPowerEvent(SinglePlayerData& player, PlayerAttributes& playerAttributes, demos::DataPackage* demoDataPackage)
{
	if( demos::getGameStatus(demoDataPackage) == demos::GameIsDemo )
	{
		greenOrb::enablePower(player, playerAttributes, demoDataPackage->greenOrbRelatedItemsData.greenOrbsAndPlayer);
	}
}

void greenOrb::enablePower(SinglePlayerData& player, PlayerAttributes& playerAttributes, demos::Stack< demos::GameEvent >& stack)
{
	if( stack.getCommandsNumber() > 0 && stack.hasLastTimeElapsed() )
	{
		if( stack.getLastElement().category == demos::eventCat::PlayerPower && stack.getLastElement().subType == demos::playerPower::GreenOrb )
		{
			player.abilities[abilities::CanEatCacti].startAbility();
			playerAttributes.addToScore( map::GreenOrbWorth );
			stack.pop_back();
		}
	}
}
