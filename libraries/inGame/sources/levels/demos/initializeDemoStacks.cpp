#include "levels/demos/initializeDemoStacks.h"
#include "levels/global/levelMandatoryData.h"
#include "levels/demosRecordingAndPlaying/data/dataPackage.h"
#include "levels/demosRecordingAndPlaying/data/determineGameStatus.h"
#include "package/essentials.h"
#include "levels/demosRecordingAndPlaying/consts/demosConsts.h"

void demos::initializeStacksNumber(Essentials& essentials, std::optional<demos::DataPackage>& demoDataPackage, const LevelMandatoryData& levelData)
{
	if( demos::getGameStatus(demoDataPackage) == demos::GameIsRecording )
	{
		demoDataPackage->spritesPositions.recordBobbysNumber(essentials, levelData.bobsPackage.size(), demoDataPackage->demoType );
		demoDataPackage->spritesPositions.recordPlayersNumber(essentials, demos::PlayerDefaultNumber, demoDataPackage->demoType );
	}
}
