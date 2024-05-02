#include "levels/global/updateProtagonistsMoves.h"
#include "levels/gameActors/playerThings/singlePlayerData.h"
#include "levels/gameActors/bobThings/bobsPackage.h"
#include "levels/maps/gameMap.h"
#include "levels/inputs/playerInputs.h"
#include "levels/monstersMoves/detectingPlayer.h"
#include "levels/demos/soundsEventsWithDemos.h"
#include "demos/data/dataPackage.h"
#include "demos/data/determineGameStatus.h"
#include "soundSystem/soundsPlayer.h"
#include "levels/maps/mapsConsts.h"
#include "levels/gameActors/playerActorsConsts.h"
#include "consts/includeOptions.h"
#include "consts/playerInputsConsts.h"
#include "consts/soundsConsts.h"

void wrapPlayerThatHasLeftOnWest(PlayerMoving& playerMoving, BobsPackage& bobsPackage, const GameMap& gameMap)
{
	if( playerMoving.hasReachOutsideOfMap(gameMap) 
		&& playerMoving.getRealPosition().x < -SQR_SIZE / 2 
		&& playerMoving.getCurrentDirection() == MoveWest )
	{
		playerMoving.setDirectionChangeAbility(false);
		playerMoving.resetInMatrixPosition(Coord2D{gameMap.matrix.width() - 1, playerMoving.getMatrixPosition().height} );
		playerMoving.getRealPosition().x = static_cast<int>(gameMap.matrix.width()) * SQR_SIZE + SQR_SIZE / 2;
		bobsPackage.makeBobsNotSeekingPlayer();
	}
}

void wrapPlayerThatHasLeftOnEast(PlayerMoving& playerMoving, BobsPackage& bobsPackage, const GameMap& gameMap)
{
	if( playerMoving.hasReachOutsideOfMap(gameMap) 
		&& playerMoving.getRealPosition().x > static_cast<int>( gameMap.matrix.width() ) * SQR_SIZE + SQR_SIZE / 2 
		&& playerMoving.getCurrentDirection() == MoveEast )
	{
		playerMoving.setDirectionChangeAbility(false);
		playerMoving.resetInMatrixPosition(Coord2D{0, playerMoving.getMatrixPosition().height} );
		playerMoving.getRealPosition().x = -SQR_SIZE / 2;
		bobsPackage.makeBobsNotSeekingPlayer();
	}
}

void wrapPlayerThatHasLeftOnNorth(PlayerMoving& playerMoving, BobsPackage& bobsPackage, const GameMap& gameMap)
{
	if( playerMoving.hasReachOutsideOfMap(gameMap)
		&& playerMoving.getRealPosition().y < -SQR_SIZE / 2
		&& playerMoving.getCurrentDirection() == MoveUp )
	{
		playerMoving.setDirectionChangeAbility(false);
		playerMoving.resetInMatrixPosition(Coord2D{playerMoving.getMatrixPosition().width, gameMap.matrix.height() - 1} );
		playerMoving.getRealPosition().y = static_cast<int>(gameMap.matrix.height()) * SQR_SIZE + SQR_SIZE / 2;
		bobsPackage.makeBobsNotSeekingPlayer();
	}
}

void wrapPlayerThatHasLeftOnSouth(PlayerMoving& playerMoving, BobsPackage& bobsPackage, const GameMap& gameMap)
{
	if( playerMoving.hasReachOutsideOfMap(gameMap)
		&& playerMoving.getRealPosition().y > static_cast<int>( gameMap.matrix.height() ) * SQR_SIZE + SQR_SIZE / 2
		&& playerMoving.getCurrentDirection() == MoveDown )
	{
		playerMoving.setDirectionChangeAbility(false);
		playerMoving.resetInMatrixPosition(Coord2D{playerMoving.getMatrixPosition().width, 0} );
		playerMoving.getRealPosition().y = -SQR_SIZE / 2;
		bobsPackage.makeBobsNotSeekingPlayer();
	}
}

void updateBobbysDetectionWithSound(const SinglePlayerData& player, BobsPackage& bobsPackage, const GameMap& gameMap, const SoundPlayer& soundPlayer, demos::DataPackage *demoDataPackage)
{
	for( auto &bob : bobsPackage )
	{
		if( bob )
		{
			if( bob->isActive )
			{
				if( false == bob->canSeekPlayer )
				{
					bob->updatePathToPlayerIfAny(gameMap, player.move.getMatrixPosition() );
					playUhOhSoundOnce(soundPlayer, demoDataPackage, bob->canSeekPlayer, bob->hasPlayedUhOhSound );
				}
			}
		}
	}
}

void playUhOhSoundOnce(const SoundPlayer& soundPlayer, demos::DataPackage *demoDataPackage, bool canSeekPlayer, bool& hasPlayedUhOhSound)
{
	if( canSeekPlayer && hasPlayedUhOhSound == false )
	{
		switch( demos::getGameStatus(demoDataPackage) )
		{
			case demos::GameIsRecording:
				soundPlayer.playSoundOnGroup(sounds::Chunk_UhOh, sounds::Channel_Bobs);
				demos::recordSoundEvent(demoDataPackage, sounds::Chunk_UhOh, sounds::Channel_Bobs);
				hasPlayedUhOhSound = true;
				break;
			case demos::GameIsDemo:
				//See line 105 of "levels/global/updateGame.cpp" file 
				break;
			case demos::GameHasPlayerInputs:
				soundPlayer.playSoundOnGroup(sounds::Chunk_UhOh, sounds::Channel_Bobs);
				hasPlayedUhOhSound = true;
				break;
		}
	}
}


void resetPlayerDirectionChangementPossibility(PlayerMoving& playerMoving)
{
	if( playerMoving.getDirectionChangeAbility() == false
		&& playerMoving.getRealPosition().x >= SQR_SIZE / 2 
		&& playerMoving.getRealPosition().x < static_cast<int>(map::ClassicMapWidth) * SQR_SIZE - SQR_SIZE / 2 
		&& playerMoving.getRealPosition().y >= SQR_SIZE / 2 
		&& playerMoving.getRealPosition().y < static_cast<int>(map::ClassicMapHeight) * SQR_SIZE - SQR_SIZE / 2 )
	{
		playerMoving.setDirectionChangeAbility(true);
	}
}

void changeWantedNextDirection(PlayerInputs& playerInputs, PlayerMoving& playerMoving)
{
	for( std::size_t direction{0} ; direction < playerInputs.inputsStates.size() ; ++direction )
	{
		if( playerInputs.inputsStates.getState(direction) )
		{
			playerMoving.changeWantedDirection(static_cast<unsigned>(direction) );
		}
	}
}