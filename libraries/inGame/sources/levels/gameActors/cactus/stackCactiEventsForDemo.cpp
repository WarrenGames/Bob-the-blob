#include "levels/gameActors/cactus/stackCactiEventsForDemo.h"
#include "levels/gameActors/cactus/cactiPackage.h"
#include "levels/gameActors/playerThings/singlePlayerData.h"
#include "levels/playerAttributes/playerAttributes.h"
#include "levels/gameActors/bobThings/bobsPackage.h"
#include "demos/dataToRecord/gameEvents.h"
#include "demos/templates/demoStack.h"
#include "demos/consts/gameEventsConsts.h"
#include "levels/maps/mapsConsts.h"
#include <algorithm>
#include <cassert>

void recordCactiEvents::stackCactusEvent(CactiPackage& cactiPackage, demos::Stack< demos::GameEvent >& stack)
{
	for( auto &cactus : cactiPackage )
	{
		switch( cactus.status )
		{
			case CactusIsDestroyed:
				if( cactus.hasRecordedDeath == false )
				{
					stack.emplaceElement( demos::GameEvent{ stack.getCurrentElapsedMicroSecondsTime(), demos::eventCat::CactusLife, demos::eventItem::Destruction, cactus.itemId } );
					cactus.status = CactusIsDestroyedAndRecorded;
					cactus.hasRecordedDeath = true;
				}
				break;
			case CactusKillsPlayer:
				stack.emplaceElement( demos::GameEvent{ stack.getCurrentElapsedMicroSecondsTime(), demos::eventCat::CactusAndPlayer, demos::eventItem::Destruction, cactus.itemId } );
				cactus.status = CactusIsPlaced;
				break;
		}
	}
}

void demosCactiEvents::actWithCactiEvents(CactiPackage& cactiPackage, demos::Stack< demos::GameEvent >& stack, SinglePlayerData& player, PlayerAttributes& playerAttributes, 
											BobsPackage& bobsPackage)
{
	while( stack.getCommandsNumber() > 0 && stack.hasLastTimeElapsed() )
	{
		switch( stack.getLastElement().category )
		{
			case demos::eventCat::CactusLife:
				demosCactiEvents::destroyCactus(cactiPackage, playerAttributes, stack.getLastElement() );
				break;
			case demos::eventCat::CactusAndPlayer:
				demosCactiEvents::resetGame(cactiPackage, player, bobsPackage, stack.getLastElement() );
				break;
			default:
				assert( false && "Error: bad 'GameEvents' 'category' struct value !" );
				break;
		}
		stack.pop_back();
	}
}

void demosCactiEvents::destroyCactus(CactiPackage& cactiPackage, PlayerAttributes& playerAttributes, const demos::GameEvent& gameEvent)
{
	auto it = std::find_if( std::begin(cactiPackage), std::end(cactiPackage), [&gameEvent](auto &cactus){ return static_cast<unsigned>(gameEvent.id) == cactus.itemId; } );
	
	if( it != cactiPackage.end() )
	{
		it->isEffective = false;
		it->status = CactusIsDestroyed;
		playerAttributes.addToScore(map::CactusEatingWorth);
	}
}

void demosCactiEvents::resetGame(CactiPackage& cactiPackage, SinglePlayerData& player, BobsPackage& bobsPackage, const demos::GameEvent& gameEvent)
{
	auto it = std::find_if( std::begin(cactiPackage), std::end(cactiPackage), [&gameEvent](auto &cactus){ return static_cast<unsigned>(gameEvent.id) == cactus.itemId; } );
	
	if( it != cactiPackage.end() )
	{
		it->status = CactusIsPlaced;
		player.resetPosition();
		bobsPackage.resetAllBobsPositions();
		bobsPackage.makeBobsNotSeekingPlayer();
	}
}