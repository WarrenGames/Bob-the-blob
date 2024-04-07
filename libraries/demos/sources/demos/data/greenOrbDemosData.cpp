#include "demos/data/greenOrbDemosData.h"
#include "package/essentials.h"
#include "pathsFunctions/pathsFunctions.h"
#include "demos/demosFiles/demoConfigFiles.h"
#include "demos/consts/demoConfigFilesConsts.h"

demos::GreenOrbDataStack::GreenOrbDataStack(Essentials& essentials, unsigned demoType):
	greenOrb{ essentials.logs, demos::fetchStackReservedSize(essentials.logs, path::getDemoConfigRelatedFile(essentials.prefPath, demos::files::GameEvents) ),
						demoType, "green orb creation and destruction events" },
	greenOrbsAndPlayer{ essentials.logs, demos::fetchStackReservedSize(essentials.logs, path::getDemoConfigRelatedFile(essentials.prefPath, demos::files::GameEvents) ),
						demoType, "green orbs power for player" },
	cactiLife{ essentials.logs, demos::fetchStackReservedSize(essentials.logs, path::getDemoConfigRelatedFile(essentials.prefPath, demos::files::GameEvents) ),
						demoType, "cacti create and destruction" }
{
	
}

void demos::GreenOrbDataStack::joinTimePoints(const AccurateTimeDelay& newDelay)
{
	greenOrb.transferDelayTimePointValue(newDelay);
	greenOrbsAndPlayer.transferDelayTimePointValue(newDelay);
	cactiLife.transferDelayTimePointValue(newDelay);
}
