#include "levels/gameActors/bobThings/globalBob.h"
#include "levels/monstersMoves/crossRoadsRandoms.h"
#include "levels/maps/gameMap.h"
#include "levels/gameActors/playerActorsConsts.h"
#include "levels/textures/texturesConsts.h"
#include "levels/monstersMoves/monstersMovesConsts.h"
#include <algorithm>
#include <cassert>

GlobalBob::GlobalBob(const Coord2D& startingPos, std::size_t colorEnum, unsigned demoIdParam):
	bobTheBlob{ startingPos },
	bobPathFinder{ actors::PlayerDetectionRange },
	lightBulbFrameNumber{ 0 },
	colorIndex{ colorEnum },
	frameNumber{ 0 },
	demoUniqueId{ demoIdParam },
	blueSpawnExplosion{ true , textures::BlueSmokeFrameDuration },
	canSeekPlayer{false},
	hasPlayedUhOhSound{false},
	isActive{ true }
{

}

void GlobalBob::updateWithSightedPlayer(const GameMap& gameMap, const Coord2D& playerPosition)
{
	if( bobTheBlob.hasReachCenterOfSquare() )
	{
		bobTheBlob.setMatrixPosition();
		bobPathFinder.addNewCoordinatesToFollow(gameMap, playerPosition);
		determineNewDirectionWithPlayer();
	}
}

void GlobalBob::updatePathToPlayerIfAny(const GameMap& gameMap, const Coord2D& playerPosition)
{
	if( bobTheBlob.hasReachCenterOfSquare() )
	{
		bobPathFinder.updatePathToPlayer(gameMap, bobTheBlob.getMatrixPosition(), playerPosition, canSeekPlayer, bobTheBlob.getCurrentDirection() );
	}
}

void GlobalBob::animateBob(const std::chrono::milliseconds& bobsAnimDelay)
{
	if( animationTime.hasTimeElapsed( bobsAnimDelay ) )
	{
		animationTime.joinTimePoints();
		if( frameNumber + 1 < textures::BlobFramesNumber )
		{
			frameNumber++;
		}
		else{
			frameNumber = 0;
		}
	}
}

void GlobalBob::animateLightBulb()
{
	if( canSeekPlayer )
	{
		if( lightBulbAnimTime.hasTimeElapsed( std::chrono::milliseconds{textures::LightBulbFrameDuration} ) )
		{
			lightBulbAnimTime.joinTimePoints();
			if( lightBulbFrameNumber + 1 < textures::LightBulbMax )
			{
				lightBulbFrameNumber++;
			}
			else{
				lightBulbFrameNumber = 0;
			}
		}
	}
}

void GlobalBob::makeBobForgetPlayer()
{
	canSeekPlayer = false;
	hasPlayedUhOhSound = false;
	bobPathFinder.forgetFollowing();
}

void GlobalBob::determineNewDirection(CrossRoadsRandoms& crossRoads)
{
	if( false == canSeekPlayer && bobTheBlob.hasReachCenterOfSquare() && bobTheBlob.getHasMoveSince() )
	{
		bobTheBlob.setMatrixPosition();
		if( crossRoads.gameMapDirections.isInsideBoundaries(bobTheBlob.getMatrixPosition() ) )
		{
			if( crossRoads.gameMapDirections(bobTheBlob.getMatrixPosition() ).size() >= 2 )
			{
				const std::vector<unsigned>::const_iterator it{ std::find_if_not( std::cbegin(crossRoads.gameMapDirections(bobTheBlob.getMatrixPosition() ) ), 
															std::cend( crossRoads.gameMapDirections(bobTheBlob.getMatrixPosition() ) ), 
															[this, &crossRoads](unsigned value)
															{ 
																assert( bobTheBlob.getCurrentDirection() < crossRoads.forbiddenDirections.size() );
																return crossRoads.forbiddenDirections[bobTheBlob.getCurrentDirection()] == value; 
															} ) };
				bobTheBlob.setCurrentDirection( *it );
				crossRoads.meltSingleCrossRoads(bobTheBlob.getMatrixPosition() );
			}
			else if( crossRoads.gameMapDirections(bobTheBlob.getMatrixPosition() ).size() == 1 )
			{
				bobTheBlob.setCurrentDirection( crossRoads.gameMapDirections(bobTheBlob.getMatrixPosition() ).front() );
			}
		}
		bobTheBlob.setFlagOffHasMovedSince();
	}
}

void GlobalBob::initFirstDirection(const CrossRoadsRandoms& crossRoads)
{
	bobTheBlob.setCurrentDirection( crossRoads.gameMapDirections(bobTheBlob.getMatrixPosition() ).front() );
}

void GlobalBob::determineNewDirectionWithPlayer()
{
	if( canSeekPlayer && bobTheBlob.getHasMoveSince() )
	{
		bobPathFinder.getOldChunk().isRelevant = false;
		bobPathFinder.advanceOldPosition();
		bobTheBlob.setCurrentDirection( bobPathFinder.getOldChunk().effectiveDirection );
		assert( bobTheBlob.getCurrentDirection() < RoadMax );
		bobTheBlob.setFlagOffHasMovedSince();
	}
}

void GlobalBob::resetBobPosition()
{
	bobTheBlob.resetBobbyPosition();
	canSeekPlayer = false;
	hasPlayedUhOhSound = false;
	isActive = true;
}

void GlobalBob::avoidWallCollisionWhileSeekingPlayer(const GameMap& gameMap, CrossRoadsRandoms& crossRoads)
{
	switch( bobTheBlob.getCurrentDirection() )
	{
		case RoadToEast:
			checkEastwardDirectionWithMap(gameMap, crossRoads);
			break;
		case RoadToNorth:
			checkNorthwardDirectionWithMap(gameMap, crossRoads);
			break;
		case RoadToWest:
			checkWestwardDirectionWithMap(gameMap, crossRoads);
			break;
		case RoadToSouth:
			checkSouthwardDirectionWithMap(gameMap, crossRoads);
			break;
		default:
			bobTheBlob.setCurrentDirection( RoadMax );
			break;
	}
}

void GlobalBob::checkEastwardDirectionWithMap(const GameMap& gameMap, CrossRoadsRandoms& crossRoads)
{
	if( gameMap.matrix.isSignedInsideBoundaries(static_cast<int>(bobTheBlob.getMatrixPosition().width) + 1, static_cast<int>(bobTheBlob.getMatrixPosition().height) ) )
	{
		if( gameMap.matrix(bobTheBlob.getMatrixPosition().width + 1, bobTheBlob.getMatrixPosition().height).mapIndex != textures::SquareEmpty )
		{
			canSeekPlayer = false;
			determineNewDirection(crossRoads);
		}
	}
}

void GlobalBob::checkNorthwardDirectionWithMap(const GameMap& gameMap, CrossRoadsRandoms& crossRoads)
{
	if( gameMap.matrix.isSignedInsideBoundaries(static_cast<int>(bobTheBlob.getMatrixPosition().width), static_cast<int>(bobTheBlob.getMatrixPosition().height) - 1) )
	{
		if( gameMap.matrix(bobTheBlob.getMatrixPosition().width, bobTheBlob.getMatrixPosition().height - 1).mapIndex != textures::SquareEmpty )
		{
			canSeekPlayer = false;
			determineNewDirection(crossRoads);
		}
	}
}

void GlobalBob::checkWestwardDirectionWithMap(const GameMap& gameMap, CrossRoadsRandoms& crossRoads)
{
	if( gameMap.matrix.isSignedInsideBoundaries(static_cast<int>(bobTheBlob.getMatrixPosition().width) - 1, static_cast<int>(bobTheBlob.getMatrixPosition().height) ) )
	{
		if( gameMap.matrix(bobTheBlob.getMatrixPosition().width - 1, bobTheBlob.getMatrixPosition().height).mapIndex != textures::SquareEmpty )
		{
			canSeekPlayer = false;
			determineNewDirection(crossRoads);
		}
	}
}

void GlobalBob::checkSouthwardDirectionWithMap(const GameMap& gameMap, CrossRoadsRandoms& crossRoads)
{
	if( gameMap.matrix.isSignedInsideBoundaries(static_cast<int>(bobTheBlob.getMatrixPosition().width), static_cast<int>(bobTheBlob.getMatrixPosition().height) + 1) )
	{
		if( gameMap.matrix(bobTheBlob.getMatrixPosition().width, bobTheBlob.getMatrixPosition().height + 1).mapIndex != textures::SquareEmpty )
		{
			canSeekPlayer = false;
			determineNewDirection(crossRoads);
		}
	}
}

void GlobalBob::disableBob()
{
	isActive = false;
}