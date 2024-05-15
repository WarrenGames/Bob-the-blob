#include "levels/demos/joinTimePoints.h"
#include "levels/global/levelMandatoryData.h"
#include "levels/demosRecordingAndPlaying/data/dataPackage.h"
#include "levels/demosRecordingAndPlaying/data/determineGameStatus.h"

void demos::joinTimePoints(demos::DataPackage *demoDataPackage, LevelMandatoryData& levelData)
{
	if( demos::getGameStatus(demoDataPackage) != demos::GameHasPlayerInputs )
	{
		const AccurateTimeDelay newDelay;
		demoDataPackage->joinTimePoints(newDelay);
		levelData.playerInputs.joinTimePointsForRecording(newDelay);
	}
}