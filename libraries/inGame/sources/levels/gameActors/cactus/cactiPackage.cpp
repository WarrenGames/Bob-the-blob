#include "levels/gameActors/cactus/cactiPackage.h"
#include "levels/gameActors/playerThings/singlePlayerData.h"
#include "levels/playerAttributes/playerAttributes.h"
#include "levels/gameActors/bobThings/bobsPackage.h"
#include "levels/maps/mapsConsts.h"
#include "levels/gameActors/playerActorsConsts.h"

void CactiPackage::addCactus(const Coord2D& coordinates, std::size_t textureIndex, unsigned itemId)
{
	cacti.emplace_back( CactusObstacle{coordinates, textureIndex, itemId} );
}

void CactiPackage::detectCollisionWithPlayer(SinglePlayerData& player, PlayerAttributes& playerAttributes, BobsPackage& bobsPackage)
{
	for( auto &cactus : cacti )
	{
		if( cactus.isEffective )
		{
			if( coords::are2DCoordsTheSame(cactus.coordinates, player.move.getMatrixPosition() ) )
			{
				if( player.abilities[abilities::CanEatCacti].isAbilityActive() )
				{
					cactus.getsDestroyed();
					playerAttributes.addToScore(map::CactusEatingWorth);
				}
				else
				{
					cactus.status = CactusKillsPlayer;
					player.resetPosition();
					bobsPackage.resetAllBobsPositions();
					bobsPackage.makeBobsNotSeekingPlayer();
				}
			}
		}
	}
}

std::vector< CactusObstacle >::iterator CactiPackage::begin()
{
	return cacti.begin();
}

std::vector< CactusObstacle >::iterator CactiPackage::end()
{
	return cacti.end();
}

std::vector< CactusObstacle >::const_iterator CactiPackage::begin() const
{
	return cacti.cbegin();
}

std::vector< CactusObstacle >::const_iterator CactiPackage::end() const
{
	return cacti.cend();
}