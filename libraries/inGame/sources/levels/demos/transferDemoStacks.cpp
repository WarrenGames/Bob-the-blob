#include "levels/demos/transferDemoStacks.h"
#include "levels/inputs/eventsRecording.h"
#include "demos/data/dataPackage.h"
#include "demos/data/determineGameStatus.h"
#include "demos/consts/demosConsts.h"

void demos::transferEventsStackInCaseOfDemo(demos::DataPackage *demoDataPackage, RecordedEvents& recordedEvents)
{
	if( demos::getGameStatus(demoDataPackage) == demos::GameIsDemo )
	{
		recordedEvents.playerInputsStack = std::move( demoDataPackage->playerInputsData.playerInputs );
		recordedEvents.escapeCommand = demoDataPackage->playerInputsData.escapeCommand;
		recordedEvents.sdlQuitEvent = demoDataPackage->playerInputsData.sdlQuitEvent;
	}
}

void demos::transferEventsStackInCaseOfRecording(demos::DataPackage *demoDataPackage, RecordedEvents& recordedEvents)
{
	if( demos::getGameStatus(demoDataPackage) == demos::GameIsRecording )
	{
		demoDataPackage->playerInputsData.playerInputs = std::move(recordedEvents.playerInputsStack);
		demoDataPackage->playerInputsData.escapeCommand = recordedEvents.escapeCommand;
		demoDataPackage->playerInputsData.sdlQuitEvent = recordedEvents.sdlQuitEvent;
	}
}