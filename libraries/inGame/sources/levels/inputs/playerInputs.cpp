#include "levels/inputs/playerInputs.h"
#include "pathsFunctions/pathsFunctions.h"
#include "consts/filesAndPaths.h"
#include "prefPath/prefPathFinder.h"
#include "logging/logsStruct.h"
#include "demos/consts/demosConsts.h"
#include "consts/playerInputsConsts.h"
#include <cassert>

PlayerInputs::PlayerInputs(AppLogFiles& logs, const PrefPathFinder& prefPath, unsigned demoType_):
	keyboardInputsConfig{ logs, path::getInputsFilePath(prefPath, files::KeyboardInputsFile) },
	recordedEvents{ logs, demoType_ },
	demoType{ demoType_ }
{
	
}

void PlayerInputs::actAccordingToDemoStatus()
{
	switch( demoType )
	{
		case demos::GameHasPlayerInputs:
			updateEvents();
			break;
		case demos::GameIsRecording:
			updateEvents();
			break;
		case demos::GameIsDemo:
			updateEvents();//To get from demo viewer SDL_QUIT or SDLK_ESCAPE pushed event as unexpected demo quit will.
			setInputsStatesWithRecordedEvents();
			setQuitCommandDuringDemo();
			setEscapeCommandDuringDemo();
			break;
	}
}

void PlayerInputs::joinTimePointsForRecording(const AccurateTimeDelay& newDelay)
{
	if( demoType == demos::GameIsRecording || demoType == demos::GameIsDemo )
	{
		recordedEvents.joinTimePointsForRecording(newDelay);
	}
}

void PlayerInputs::updateEvents()
{
	while( SDL_PollEvent(&event) )
	{
		switch( event.type )
		{
			case SDL_QUIT:
				setSdlQuit();
				recordSdlQuitEventIfAny();
				break;
			case SDL_KEYDOWN:
				updateKeysStates(event.key.keysym.sym, true);
				setEscapeState(event.key.keysym.sym, true);
				recordEscapeCommandIfAny(event.key.keysym.sym, true);
				break;
			case SDL_KEYUP:
				updateKeysStates(event.key.keysym.sym, false);
				setEscapeState(event.key.keysym.sym, false);
				recordEscapeCommandIfAny(event.key.keysym.sym, false);
				break;
		}
	}
}

void PlayerInputs::updateKeysStates(SDL_Keycode keycode, bool valueToSet)
{
	for( std::size_t i{0} ; i < keyboardInputsConfig.size() && i < inputsStates.size() ; ++i )
	{
		if( keyboardInputsConfig.getKeycode(i) == keycode )
		{
			recordAndEvent(i, valueToSet);
			inputsStates.setState(i, valueToSet);
		}
	}
}

void PlayerInputs::setSdlQuit()
{
	inputsStates.setSdlQuitFlag(true);
}

void PlayerInputs::setEscapeState(SDL_Keycode keycode, bool valueToSet)
{
	if( keycode == SDLK_ESCAPE )
	{
		inputsStates.setEscapeKeyFlag(valueToSet);
	}
}

void PlayerInputs::recordAndEvent(std::size_t funcEnum, bool keyState)
{
	if( demoType == demos::GameIsRecording )
	{
		recordedEvents.recordAndEventIfEnoughAllocated(funcEnum, keyState);
	}
}

void PlayerInputs::setInputsStatesWithRecordedEvents()
{
	while( recordedEvents.playerInputsStack.getCommandsNumber() > 0 && recordedEvents.playerInputsStack.hasLastTimeElapsed() )
	{
		actWithRecordedDemoActionData(recordedEvents.playerInputsStack.getLastElement() );
		recordedEvents.playerInputsStack.pop_back();
	}
}

void PlayerInputs::actWithRecordedDemoActionData(const demos::ActionData& actionData)
{
	assert( actionData.funcEnum < MoveMax );
	inputsStates.setState(actionData.funcEnum, actionData.actionState);
}

void PlayerInputs::setQuitCommandDuringDemo()
{
	if( demoType == demos::GameIsDemo )
	{
		if( recordedEvents.hasQuitCommandComeOut() )
		{
			inputsStates.setSdlQuitFlag( recordedEvents.sdlQuitEvent.actionState );
		}
	}
}

void PlayerInputs::setEscapeCommandDuringDemo()
{
	if( demoType == demos::GameIsDemo )
	{
		if( recordedEvents.hasEscapeCommandComeOut() )
		{
			inputsStates.setEscapeKeyFlag( recordedEvents.escapeCommand.actionState );
		}
	}
}

void PlayerInputs::recordSdlQuitEventIfAny()
{
	if( demoType == demos::GameIsRecording)
	{
		recordedEvents.recordSdlQuitEventIfAny();
		
	}
}

void PlayerInputs::recordEscapeCommandIfAny(SDL_Keycode lastKeycode, bool isKeycodePushed)
{
	if( demoType == demos::GameIsRecording )
	{
		if( lastKeycode == SDLK_ESCAPE )
		{
			recordedEvents.recordEscapeKeyEventIfAny(isKeycodePushed);
		}
	}
}
