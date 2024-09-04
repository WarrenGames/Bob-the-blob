#include "levels/loadings/gameConfigurationData.h"
#include "pathsFunctions/pathsFunctions.h"
#include "levels/loadings/getConfigFileNumber.h"
#include "package/essentials.h"
#include "levels/demosRecordingAndPlaying/data/dataPackage.h"
#include "levels/demosRecordingAndPlaying/data/determineGameStatus.h"
#include "consts/filesAndPaths.h"
#include "levels/demosRecordingAndPlaying/consts/demosConsts.h"

GameConfigData::GameConfigData(Essentials& essentials, const std::optional<demos::DataPackage>& demoPackage):
	bobMoveDelay{ getUnsignedIntFromFile( essentials.prefPath.getFsPath() / files::OptionsDir / files::BobsMoveDelayFile, "Bobs move delay" ) },
	bobAnimDelay{ getUnsignedIntFromFile( essentials.prefPath.getFsPath() / files::OptionsDir / files::BobsAnimDelayFile, "Bobs anim delay" ) },
	bobSpawnDelay{ getUnsignedIntFromFile( essentials.prefPath.getFsPath() / files::OptionsDir / files::BobsSpawnDelay, "Bobs spawn delay" ) },
	bobVulnerability{ 0 },
	greenOrbCreation{ 0 },
	greenOrbDuration{ 0 },
	playerCanEatCactiDelay{ 0 }
{
	if( demos::getGameStatus(demoPackage) == demos::GameIsDemo )
	{
		loadDataFromDemoPackage(demoPackage);
	}
	else{
		loadDataFromFile(essentials);
	}
}

void GameConfigData::loadDataFromFile(Essentials& essentials)
{
	bobSpawnDelay = std::chrono::milliseconds{ getUnsignedIntFromFile( path::getOptionFilePath(essentials.prefPath, files::BobsSpawnDelay), "bob spawn delay" ) };
	bobVulnerability = std::chrono::milliseconds{ getUnsignedIntFromFile( path::getOptionFilePath(essentials.prefPath, files::BobsEatableDelayFile), "bob vulnerability delay" ) };
	greenOrbCreation = std::chrono::milliseconds{ getUnsignedIntFromFile( path::getOptionFilePath(essentials.prefPath, files::GreenOrbCreationDelay), "green orb creation delay") };
	greenOrbDuration = std::chrono::milliseconds{ getUnsignedIntFromFile( path::getOptionFilePath(essentials.prefPath, files::GreenOrbDurationFile), "green orb duration delay") };
	playerCanEatCactiDelay = std::chrono::milliseconds{ getUnsignedIntFromFile( path::getOptionFilePath(essentials.prefPath, files::PlayerCanEatCacti), "player can eat cacti delay") };
}

void GameConfigData::loadDataFromDemoPackage(const std::optional<demos::DataPackage>& demoPackage)
{
	playerCanEatCactiDelay = std::chrono::milliseconds{ demoPackage->greenOrbRelatedItemsData.greenOrbPowerDuration };
	bobVulnerability = std::chrono::milliseconds{ demoPackage->enemyBobVulnerabilityDelay };
}

void GameConfigData::setDataToDemoPackage(std::optional<demos::DataPackage>& demoPackage)
{
	if( demos::getGameStatus(demoPackage) == demos::GameIsRecording )
	{
		demoPackage->greenOrbRelatedItemsData.greenOrbPowerDuration = playerCanEatCactiDelay.count();
		demoPackage->enemyBobVulnerabilityDelay = bobVulnerability.count();
	}
}