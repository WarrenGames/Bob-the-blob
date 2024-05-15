#include "levels/demosRecordingAndPlaying/data/positionElements.h"
#include "levels/gameActors/playerThings/singlePlayerData.h"
#include "levels/demosRecordingAndPlaying/demosFiles/demoConfigFiles.h"
#include "levels/gameActors/bobThings/bobsPackage.h"
#include "levels/gameActors/cactus/cactiPackage.h"
#include "package/essentials.h"
#include "pathsFunctions/pathsFunctions.h"
#include "levels/demosRecordingAndPlaying/consts/demoConfigFilesConsts.h"
#include "levels/demosRecordingAndPlaying/consts/dataRecordingConsts.h"
#include "levels/demosRecordingAndPlaying/consts/gameEventsConsts.h"

demos::SpritesPositions::SpritesPositions(Essentials& essentials, unsigned demoType_):
	enemyBobsRespawn{essentials.logs, demos::fetchStackReservedSize(essentials.logs, path::getDemoConfigRelatedFile(essentials.prefPath, demos::cfgFiles::GameEvents) ), 
			demoType_, "Enemy bobs respawn"}
{
	
}

void demos::SpritesPositions::joinAllTimePoints(const AccurateTimeDelay& newDelay)
{
	joinPlayersTimePoints(newDelay);
	joinBobbyMovesTimePoints(newDelay);
	enemyBobsRespawn.transferDelayTimePointValue(newDelay);
}

void demos::SpritesPositions::joinPlayersTimePoints(const AccurateTimeDelay& newDelay)
{
	for( auto &data : playersMoves )
	{
		data.transferDelayTimePointValue(newDelay);
	}
}

void demos::SpritesPositions::joinBobbyMovesTimePoints(const AccurateTimeDelay& newDelay)
{
	for( auto &data : enemyBobsMoves )
	{
		data.transferDelayTimePointValue(newDelay);
	}
}

void demos::SpritesPositions::addBobMoveStack(Essentials& essentials, unsigned demoType)
{
	enemyBobsMoves.emplace_back( demos::Stack<demos::MoveAndPosition>{ essentials.logs, demos::fetchStackReservedSize(essentials.logs, path::getDemoConfigRelatedFile(essentials.prefPath, 
												demos::cfgFiles::NextPositionAndAction) ), 
					demoType, "enemy bobs moves" } );
}

void demos::SpritesPositions::recordPlayerStartingPosition(const SinglePlayerData& singlePlayerData, unsigned demoType)
{
	if( demoType == demos::GameIsRecording )
	{
		protagonistsStartingPosition.emplace_back( demos::StartingPosition{singlePlayerData.playerStartingPosition, demosData::StartPosPlayer, demosData::PlayerSubType1, 0} );
	}
}

void demos::SpritesPositions::recordProtagonistsStartingPosition(const BobsPackage& bobsPackage, unsigned demoType)
{
	if( demoType == demos::GameIsRecording )
	{
		for( auto const &bobby : bobsPackage )
		{
			protagonistsStartingPosition.emplace_back( 
				demos::StartingPosition{bobby->bobTheBlob.getStartingPosition(), demosData::StartPosBobby, static_cast<unsigned>(bobby->colorIndex ), bobby->demoUniqueId } );
		}
	}
}

void demos::SpritesPositions::recordCactiStartingPositions(const CactiPackage& cactiPackage)
{
	for( auto const &cactus : cactiPackage )
	{
		itemsStartingPosition.emplace_back( 
			demos::StartingPosition{ cactus.coordinates, demosData::ItemCactiStartPos, static_cast<unsigned>(cactus.cactusTexture), cactus.itemId } 
		);
	}
}

void demos::SpritesPositions::recordBobRespawnEvent(std::size_t bobId, unsigned demoType)
{
	if( demoType == demos::GameIsRecording )
	{
		enemyBobsRespawn.emplaceElement( demos::GameEvent{ enemyBobsRespawn.getCurrentElapsedMicroSecondsTime(), demos::eventCat::Bob, demos::eventSubBob::Respawn, bobId } );
	}
}

void demos::SpritesPositions::setBobbysLevelDataFromDemoData(BobsPackage& bobsPackage, unsigned demoType) const
{
	if( demoType == demos::GameIsDemo )
	{
		for( auto const &protagonist : protagonistsStartingPosition )
		{
			if( protagonist.type == demosData::StartPosBobby )
			{
				bobsPackage.emplaceBackBob(protagonist.position, protagonist.subType);
			}
		}
	}
}

void demos::SpritesPositions::setPlayerLevelDataFromDemoData(SinglePlayerData& singlePlayerData, unsigned demoType) const
{
	if( demoType == demos::GameIsDemo )
	{
		for( auto const &protagonist : protagonistsStartingPosition )
		{
			if( protagonist.type == demosData::StartPosPlayer )
			{
				singlePlayerData.playerStartingPosition = protagonist.position;
			}
		}
	}
}

void demos::SpritesPositions::setCactiStartingPositions(CactiPackage& cactiPackage) const
{
	for( auto const &item : itemsStartingPosition )
	{
		if( item.type == demosData::ItemCactiStartPos )
		{
			cactiPackage.addCactus(item.position, item.subType, item.id);
		}
	}
}

void demos::SpritesPositions::recordBobbysNumber(Essentials& essentials, std::size_t bobbysNumber, unsigned demoType)
{
	if( demoType == demos::GameIsRecording )
	{
		for( std::size_t i{0} ; i < bobbysNumber ; ++i )
		{
			enemyBobsMoves.emplace_back( demos::Stack< demos::MoveAndPosition >{essentials.logs, 
				demos::fetchStackReservedSize(essentials.logs, path::getDemoConfigRelatedFile(essentials.prefPath, demos::cfgFiles::NextPositionAndAction) ), demoType, "Bobbys position" } );
		}
	}
}

void demos::SpritesPositions::recordPlayersNumber(Essentials& essentials, std::size_t playersNumber, unsigned demoType)
{
	if( demoType == demos::GameIsRecording )
	{
		for( std::size_t i{0} ; i < playersNumber ; ++i )
		{
			playersMoves.emplace_back( demos::Stack< demos::PlayerMove >{essentials.logs,
				demos::fetchStackReservedSize(essentials.logs, path::getDemoConfigRelatedFile(essentials.prefPath, demos::cfgFiles::NextPositionAndAction) ), demoType, 
				"Player(s) position" } );
		}
	}
}