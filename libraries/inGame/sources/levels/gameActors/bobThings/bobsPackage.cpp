#include "levels/gameActors/bobThings/bobsPackage.h"
#include "levels/gameActors/playerThings/singlePlayerData.h"
#include "levels/playerAttributes/playerAttributes.h"
#include "package/essentials.h"
#include "levels/loadings/readStartPositionInFile.h"
#include "levels/loadings/getConfigFileNumber.h"
#include "levels/monstersMoves/collisionBetweenPlayerAndBobs.h"
#include "demos/data/dataPackage.h"
#include "demos/data/determineGameStatus.h"
#include "levels/gameActors/playerActorsConsts.h"
#include "consts/includeOptions.h"
#include "levels/maps/mapsConsts.h"
#include "consts/filesAndPaths.h"
#include "demos/consts/demosConsts.h"
#include "demos/consts/gameEventsConsts.h"
#include <algorithm>
#include <cassert>

BobsPackage::BobsPackage(Essentials& essentials, const fs::path& bobsDataFilePath, unsigned demoType):
	bobsMoveDelay{ getUnsignedIntFromFile( essentials.prefPath.getFsPath() / files::OptionsDir / files::BobsMoveDelayFile, "Bobs move delay" ) },
	bobsAnimDelay{ getUnsignedIntFromFile( essentials.prefPath.getFsPath() / files::OptionsDir / files::BobsAnimDelayFile, "Bobs anim delay" ) },
	bobsSpawnDelay{ getUnsignedIntFromFile( essentials.prefPath.getFsPath() / files::OptionsDir / files::BobsSpawnDelay, "Bobs spawn delay" ) }
{
	if( demoType == demos::GameHasPlayerInputs || demoType == demos::GameIsRecording )
	{
		loadBobsDataFromFile(*this, bobsDataFilePath, "load bobs data");	
	}
}

std::vector< std::unique_ptr< GlobalBob > >::iterator BobsPackage::begin()
{
	return bobs.begin();
}

std::vector< std::unique_ptr< GlobalBob > >::iterator BobsPackage::end()
{
	return bobs.end();
}

std::vector< std::unique_ptr< GlobalBob > >::const_iterator BobsPackage::begin() const
{
	return bobs.cbegin();
}

std::vector< std::unique_ptr< GlobalBob > >::const_iterator BobsPackage::end() const
{
	return bobs.cend();
}

std::size_t BobsPackage::size() const
{
	return bobs.size();
}

std::size_t BobsPackage::getActiveBobsCount() const
{
	std::size_t count{0};
	for( auto const &bob : bobs )
	{
		if( bob )
		{
			if( bob->isActive )
			{
				count++;
			}
		}
	}
	return count;
}

const GlobalBob& BobsPackage::getElement(std::size_t index) const
{
	assert( index < bobs.size() );
	return *bobs[index];
}

GlobalBob& BobsPackage::getElement(std::size_t index)
{
	assert( index < bobs.size() );
	return *bobs[index];
}

void BobsPackage::emplaceBackBob(const Coord2D& startingPos, std::size_t colorEnum)
{
	bobs.emplace_back( std::make_unique< GlobalBob >(startingPos, colorEnum, static_cast<unsigned>( bobs.size() ) ) );
}

void BobsPackage::animatePackage()
{
	for( auto &bob : bobs )
	{
		if( bob )
		{
			if( bob->isActive )
			{
				bob->animateBob(bobsAnimDelay);
				bob->animateLightBulb();
			}
		}
	}
}

void BobsPackage::movePackage()
{
	if( moveTime.hasTimeElapsed( bobsMoveDelay ) )
	{
		moveTime.joinTimePoints();
		for( auto &bob : bobs )
		{
			if( bob )
			{
				if( bob->isActive )
				{
					bob->bobTheBlob.checkMoveDelay();
				}
			}
		}
	}
}

void BobsPackage::changeDirectionIfAny(CrossRoadsRandoms& crossRoads, const GameMap& gameMap, const PlayerMoving& playerMoving)
{
	for( auto &bob : bobs )
	{
		if( bob )
		{
			if( bob->isActive )
			{
				if( false == bob->canSeekPlayer )
				{
					bob->determineNewDirection(crossRoads);
				}
				else{
					bob->updateWithSightedPlayer(gameMap, playerMoving.getMatrixPosition() );
				}
			}
		}
	}
}

void BobsPackage::detectCollisionWithPlayer(SinglePlayerData& player, PlayerAttributes& playerAttributes, const Ability& canEatBobs, demos::DataPackage *demoDataPackage)
{
	for( std::size_t i{0} ; i < bobs.size() ; ++i )
	{
		if( bobs[i] )
		{
			if( bobs[i]->isActive )
			{
				if( isCollisioningWithPlayer(player.move, bobs[i]->bobTheBlob, SQR_SIZE / 8) )
				{
					if( canEatBobs.isAbilityActive() )
					{
						recordBobRelatedGameEvent(demoDataPackage, demos::eventCat::Bob, demos::eventSubBob::EatenByPlayer, i);
						bobs[i]->disableBob();
						playerAttributes.addToScore(map::BobEatingWorth);
					}
					else{
						recordBobRelatedGameEvent(demoDataPackage, demos::eventCat::Bob, demos::eventSubBob::CatchPlayer, i);
						player.resetPosition();
						resetAllBobsPositions();
						makeBobsNotSeekingPlayer();
					}
				}
			}
		}
	}
}

void BobsPackage::recordBobRelatedGameEvent(demos::DataPackage *demoDataPackage, unsigned eventCategory, unsigned eventSubType, std::size_t newId) const
{
	if( demos::getGameStatus(demoDataPackage) == demos::GameIsRecording )
	{
		demoDataPackage->recordGameEvent(eventCategory, eventSubType, newId);
	}
}

void BobsPackage::resetAllBobsPositions()
{
	for( auto &bob : bobs )
	{
		if( bob )
		{
			bob->resetBobPosition();
		}
	}
}

void BobsPackage::makeBobsNotSeekingPlayer()
{
	for( auto &bob: bobs )
	{
		if( bob )
		{
			if( bob->isActive )
			{
				bob->makeBobForgetPlayer();
			}
		}
	}
}

void BobsPackage::disableAllBobs()
{
	for( auto &bob : bobs )
	{
		if( bob )
		{
			bob->disableBob();
		}
	}
}

void BobsPackage::initFirstDirection(const CrossRoadsRandoms& crossRoads)
{
	for( auto &bob : bobs )
	{
		if( bob )
		{
			bob->initFirstDirection(crossRoads);
		}
	}
}

void BobsPackage::spawnBobIfAny(const PlayerMoving& playerMove, demos::DataPackage *demoDataPackage)
{
	if( getActiveBobsCount() < size() )
	{
		if( spawnTime.hasTimeElapsed( bobsSpawnDelay ) )
		{
			spawnTime.joinTimePoints();
			for( auto const &bob : bobs )
			{
				if( false == bob->isActive && false == isPlayerNearEnemySpawnCoordinates(playerMove, bob->bobTheBlob) )
				{
					spawnSingleBob(*bob);
					if( demos::getGameStatus(demoDataPackage) == demos::GameIsRecording )
					{
						demoDataPackage->spritesPositions.recordBobRespawnEvent(bob->demoUniqueId, demoDataPackage->demoType);
					}
					return;
				}
			}
		}
	}
}

void BobsPackage::spawnSingleBob(GlobalBob& globalBob)
{
	globalBob.resetBobPosition();
	globalBob.makeBobForgetPlayer();
	globalBob.blueSpawnExplosion.resetExplosionDisplay();
}

void BobsPackage::spawnBobWithDemoStack(demos::DataPackage *demoDataPackage)
{
	if( demos::getGameStatus(demoDataPackage) == demos::GameIsDemo )
	{
		while( demoDataPackage->spritesPositions.enemyBobsRespawn.getCommandsNumber() > 0 && demoDataPackage->spritesPositions.enemyBobsRespawn.hasLastTimeElapsed() )
		{
			for( auto &bob : bobs )
			{
				if( static_cast<std::size_t>(bob->demoUniqueId) == demoDataPackage->spritesPositions.enemyBobsRespawn.getLastElement().id )
				{
					spawnSingleBob(*bob);
					demoDataPackage->spritesPositions.enemyBobsRespawn.pop_back();
					break;
				}
			}
		}
	}
}

void BobsPackage::updateExplosionIfAny(std::size_t totalFrameNumber)
{
	for( auto const &bob : bobs )
	{
		if( bob->blueSpawnExplosion.isExplosionActive() )
		{
			bob->blueSpawnExplosion.incrementFrame(totalFrameNumber);
		}
	}
}