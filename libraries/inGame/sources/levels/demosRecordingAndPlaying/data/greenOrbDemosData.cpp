#include "levels/demosRecordingAndPlaying/data/greenOrbDemosData.h"
#include "package/essentials.h"
#include "pathsFunctions/pathsFunctions.h"
#include "levels/demosRecordingAndPlaying/demosFiles/demoConfigFiles.h"
#include "levels/demosRecordingAndPlaying/consts/demoConfigFilesConsts.h"
#include "consts/filesAndPaths.h"

demos::GreenOrbDataStack::GreenOrbDataStack(Essentials& essentials, unsigned demoType):
	greenOrb{ essentials.logs, demos::fetchStackReservedSize(essentials.logs, path::getDemoConfigRelatedFile(essentials.prefPath, demos::cfgFiles::GameEvents) ),
						demoType, "green orb creation and destruction events" },
	greenOrbsAndPlayer{ essentials.logs, demos::fetchStackReservedSize(essentials.logs, path::getDemoConfigRelatedFile(essentials.prefPath, demos::cfgFiles::GameEvents) ),
						demoType, "green orbs power for player" },
	cactiLife{ essentials.logs, demos::fetchStackReservedSize(essentials.logs, path::getDemoConfigRelatedFile(essentials.prefPath, demos::cfgFiles::GameEvents) ),
						demoType, "cacti create and destruction" },
	greenOrbPowerDuration{ 0 }
{
	
}

void demos::GreenOrbDataStack::joinTimePoints(const AccurateTimeDelay& newDelay)
{
	greenOrb.transferDelayTimePointValue(newDelay);
	greenOrbsAndPlayer.transferDelayTimePointValue(newDelay);
	cactiLife.transferDelayTimePointValue(newDelay);
}
