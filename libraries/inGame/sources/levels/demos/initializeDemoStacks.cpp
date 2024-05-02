#include "levels/demos/initializeDemoStacks.h"
#include "levels/global/levelMandatoryData.h"
#include "demos/data/dataPackage.h"
#include "demos/data/determineGameStatus.h"
#include "package/essentials.h"
#include "demos/consts/demosConsts.h"

void demos::initializeStacksNumber(Essentials& essentials, demos::DataPackage *demoDataPackage, const LevelMandatoryData& levelData)
{
	if( demos::getGameStatus(demoDataPackage) == demos::GameIsRecording )
	{
		demoDataPackage->spritesPositions.recordBobbysNumber(essentials, levelData.bobsPackage.size(), demoDataPackage->demoType );
		demoDataPackage->spritesPositions.recordPlayersNumber(essentials, demos::PlayerDefaultNumber, demoDataPackage->demoType );
	}
}
