#include "levels/inputs/eventsRecording.h"
#include "demos/consts/demosConsts.h"
#include "consts/playerInputsConsts.h"

RecordedEvents::RecordedEvents(AppLogFiles& logs, unsigned demoType):
	playerInputsStack{logs, demos::DefaultReservedDataForRecording, demoType, "player inputs"},
	movesInputsStack{logs, 0, demoType, "moves inputs"}
{
	sdlQuitEvent.delay = recordDelay.getCurrentElapsedMicrosecondsTime();
	escapeCommand.delay = recordDelay.getCurrentElapsedMicrosecondsTime();
}

void RecordedEvents::recordAndEventIfEnoughAllocated(std::size_t funcEnum, bool keyState)
{
	if( playerInputsStack.getCommandsNumber() + 1 < playerInputsStack.getCapacity() )
	{
		playerInputsStack.emplaceElement(demos::ActionData{ recordDelay.getCurrentElapsedMicrosecondsTime(), static_cast<unsigned>(funcEnum), keyState} );
	}
}

bool RecordedEvents::hasQuitCommandComeOut() const
{
	return recordDelay.hasTimeElapsed( sdlQuitEvent.delay );
}

bool RecordedEvents::hasEscapeCommandComeOut() const
{
	return recordDelay.hasTimeElapsed( escapeCommand.delay );
}

void RecordedEvents::joinTimePointsForRecording(const AccurateTimeDelay& newDelay)
{
	recordDelay = newDelay;
	playerInputsStack.transferDelayTimePointValue(newDelay);
	movesInputsStack.transferDelayTimePointValue(newDelay);
}

void RecordedEvents::recordSdlQuitEventIfAny()
{
	sdlQuitEvent.delay = recordDelay.getCurrentElapsedMicrosecondsTime();
	sdlQuitEvent.funcEnum = DemoSdlQuitCommand;
	sdlQuitEvent.actionState = true;
}

void RecordedEvents::recordEscapeKeyEventIfAny(bool keyState)
{
	escapeCommand.delay = recordDelay.getCurrentElapsedMicrosecondsTime();
	escapeCommand.funcEnum = DemoEscapeCommand;
	escapeCommand.actionState = keyState;
}