#include "levels/loadings/gameComponentsLoading.h"
#include "package/essentials.h"
#include "levels/global/levelMandatoryData.h"
#include "levels/maps/loadPlayerPosition.h"
#include "levels/mapSubDivisions/loadSubdivisionData.h"
#include "demos/data/dataPackage.h"
#include "demos/data/determineGameStatus.h"
#include "pathsFunctions/pathsFunctions.h"
#include "levels/gameActors/playerActorsConsts.h"
#include "consts/filesAndPaths.h"
#include "demos/consts/demosConsts.h"

void loadAndInitializeGameComponents(Essentials& essentials, LevelMandatoryData& levelData, const fs::path& levelPrefix, demos::DataPackage* demoDataPackage)
{
	loadPlayerPosition(essentials.logs, levelData.playerData, path::getGameConfigFilePath(levelPrefix, files::DefaultPlayerStartingPositionSuffix), levelData.isLoadingPerfect, 
						levelData.demoType);
	levelData.crossRoadsRandoms.createCrossRoadsPossibleDirections(levelData.gameMap);
	levelData.crossRoadsRandoms.meltDirectionsInMatrix();
	loadMapSubdivision(levelData, demoDataPackage);
}

void loadMapSubdivision(LevelMandatoryData& levelData, demos::DataPackage* demoDataPackage)
{
	switch( demos::getGameStatus(demoDataPackage) )
	{
		case demos::GameHasPlayerInputs:

			break;
		case demos::GameIsRecording:
			demoDataPackage->mapsElements.recordSubDivisionMapData(levelData.zonesFences.subDivisionFileData, levelData.demoType);
			break;
		case demos::GameIsDemo:
			demoDataPackage->mapsElements.setSubDivisionMapData(levelData.zonesFences.subDivisionFileData, levelData.demoType);
			break;
	}
}