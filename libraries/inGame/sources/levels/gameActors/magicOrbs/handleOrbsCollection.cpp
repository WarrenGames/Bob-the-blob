#include "levels/gameActors/magicOrbs/handleOrbsCollection.h"
#include "levels/global/levelMandatoryData.h"
#include "levels/gameActors/magicOrbs/orbsPackage.h"
#include "levels/playerAttributes/playerAttributes.h"
#include "levels/demosRecordingAndPlaying/data/dataPackage.h"
#include "levels/demosRecordingAndPlaying/data/determineGameStatus.h"

void browseColoredOrbCollection(LevelMandatoryData& levelData, OrbsPackage& orbsPackage, PlayerAttributes& playerAttributes, demos::DataPackage* demoDataPackage, std::size_t abilityIndex)
{
	orbsPackage.createOrbs( levelData.zonesFences.getMatchingCoordinates(levelData.playerData.move.getMatrixPosition() ), levelData.gameMap, demoDataPackage, 
							levelData.gameSoundSystem.soundSystem.soundPlayer );
	orbsPackage.abortOrbsIfAny();
	handleOrbsAccordingToDemoValue(levelData.playerData, orbsPackage, playerAttributes, demoDataPackage, abilityIndex);
}

void handleOrbsAccordingToDemoValue(SinglePlayerData& player, OrbsPackage& orbsPackage, PlayerAttributes& playerAttributes, demos::DataPackage* demoDataPackage, std::size_t abilityIndex)
{
	switch( demos::getGameStatus(demoDataPackage) )
	{
		case demos::GameIsRecording:
			browseOrbsForPlayer(player, orbsPackage, playerAttributes, abilityIndex);
			break;
		case demos::GameIsDemo:
			
			break;
		case demos::GameHasPlayerInputs:
			browseOrbsForPlayer(player, orbsPackage, playerAttributes, abilityIndex);
			break;
	}
}

void browseOrbsForPlayer(SinglePlayerData& player, OrbsPackage& orbsPackage, PlayerAttributes& playerAttributes, std::size_t abilityIndex)
{
	for( auto &orb : orbsPackage )
	{
		if( orb.isPresent )
		{
			if( coords::are2DCoordsTheSame(player.move.getMatrixPosition(), orb.orbCoordinates) )
			{
				player.abilities[abilityIndex].startAbility();
				player.abilities.setDemoFlag(abilityIndex, true);
				playerAttributes.addToScore(orbsPackage.getOrbScoreValue() );
				orb.isPresent = false;
				orb.status = OrbStatusDestroyed;
			}
		}
	}
}

