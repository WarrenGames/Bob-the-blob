#include "levels/demosRecordingAndPlaying/data/determineGameStatus.h"
#include "levels/demosRecordingAndPlaying/data/dataPackage.h"
#include "levels/demosRecordingAndPlaying/consts/demosConsts.h"
#include <cassert>

unsigned demos::getGameStatus(const std::optional<demos::DataPackage>& demoDataPackage)
{
	if( demoDataPackage )
	{
		assert( demoDataPackage->demoType == demos::GameIsRecording || demoDataPackage->demoType == demos::GameIsDemo );
		return demoDataPackage->demoType;
	}
	else{
		return demos::GameHasPlayerInputs;
	}
}