#include "demos/data/determineGameStatus.h"
#include "demos/data/dataPackage.h"
#include "demos/consts/demosConsts.h"
#include <cassert>

unsigned demos::getGameStatus(const demos::DataPackage *demoDataPackage)
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