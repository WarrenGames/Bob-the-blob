#include "levels/inputs/playerInputs.h"
#include "pathsFunctions/pathsFunctions.h"
#include "consts/filesAndPaths.h"
#include "prefPath/prefPathFinder.h"
#include "logging/logsStruct.h"
#include "levels/demosRecordingAndPlaying/consts/demosConsts.h"
#include "consts/playerInputsConsts.h"
#include <cassert>

PlayerInputs::PlayerInputs(AppLogFiles& logs, const PrefPathFinder& prefPath, unsigned demoType_):
	keyboardInputsConfig{ logs, path::getInputsFilePath(prefPath, files::KeyboardInputsFile) },
	joystickInputsConfig{ logs, prefPath },
	recordedEvents{ logs, demoType_ },
	joystickEntity{ 0 },
	demoType{ demoType_ }
{
	
}

bool PlayerInputs::wasLoadingPerfect() const
{
	return keyboardInputsConfig.wasLoadingPerfect() && joystickInputsConfig.wasLoadingPerfect();
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
			case SDL_JOYBUTTONDOWN:
				updateWithJoystickButtonState(static_cast<SDL_JoystickID>(event.jbutton.which), static_cast<unsigned>(event.jbutton.button), true);
				break;
			case SDL_JOYBUTTONUP:
				updateWithJoystickButtonState(static_cast<SDL_JoystickID>(event.jbutton.which), static_cast<unsigned>(event.jbutton.button), false);
				break;
			case SDL_JOYHATMOTION:
				updateWithJoystickHat(static_cast<SDL_JoystickID>(event.jhat.which), static_cast<unsigned>(event.jhat.hat), static_cast<unsigned>(event.jhat.value) );
				break;
			case SDL_JOYAXISMOTION:
				updateWithJoystickAxis(static_cast<SDL_JoystickID>(event.jaxis.which), static_cast<unsigned>(event.jaxis.axis), static_cast<int>(event.jaxis.value) );
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
			recordAnEvent(i, valueToSet);
			inputsStates.setState(i, valueToSet);
		}
	}
}

void PlayerInputs::updateWithJoystickButtonState(SDL_JoystickID joystickNumber, unsigned buttonNumber, bool valueToSet)
{
	if( joystickEntity && joystickNumber == joystickEntity.getJoystickNumber() )
	{
		for( std::size_t i{0} ; i < joystickInputsConfig.size() && i < inputsStates.size() ; ++i )
		{
			if( joystickInputsConfig.getJoyElement(i) == JoyButtons && joystickInputsConfig.getElementNumber(i) == buttonNumber )
			{
				recordAnEvent(i, valueToSet);
				setNewDirectionAndAbortOthers(i);
			}
		}
	}
}

void PlayerInputs::updateWithJoystickHat(SDL_JoystickID joystickNumber, unsigned hatNumber, unsigned hatState)
{
	if( joystickEntity && joystickNumber == joystickEntity.getJoystickNumber() )
	{
		for( std::size_t i{0} ; i < joystickInputsConfig.size() && i < inputsStates.size() ; ++i )
		{
			if( joystickInputsConfig.getJoyElement(i) == JoyHats && joystickInputsConfig.getElementNumber(i) == hatNumber )
			{
				if( hatState == joystickInputsConfig.getElementValue(i) )
				{
					setNewDirectionAndAbortOthers(i);
				}
			}
		}
	}
}

void PlayerInputs::updateWithJoystickAxis(SDL_JoystickID joystickNumber, unsigned axisNumber, int axisValue)
{
	if( joystickEntity && joystickNumber == joystickEntity.getJoystickNumber() )
	{
		if( ! ( axisValue < joystickInputsConfig.getAxesTheshold() && axisValue >= -joystickInputsConfig.getAxesTheshold() ) )
		{
			for( std::size_t i{0} ; i < joystickInputsConfig.size() && i < inputsStates.size() ; ++i )
			{
				if( joystickInputsConfig.getJoyElement(i) == JoyAxes && joystickInputsConfig.getElementNumber(i) == axisNumber )
				{
					actWithAxisValue(static_cast<unsigned>(i), axisValue);
				}
			}
		}
	}
}

void PlayerInputs::actWithAxisValue(unsigned moveEnum, int axisValue)
{
	switch( moveEnum )
	{
		case MoveEast:
			if( axisValue >= joystickInputsConfig.getAxesTheshold() )
			{
				setNewDirectionAndAbortOthers(MoveEast);
			}
			break;
		case MoveUp:
			if( axisValue <= -joystickInputsConfig.getAxesTheshold() )
			{
				setNewDirectionAndAbortOthers(MoveUp);
			}
			break;
		case MoveWest:
			if( axisValue <= -joystickInputsConfig.getAxesTheshold() )
			{
				setNewDirectionAndAbortOthers(MoveWest);
			}
			break;
		case MoveDown:
			if( axisValue >= joystickInputsConfig.getAxesTheshold() )
			{
				setNewDirectionAndAbortOthers(MoveDown);
			}
			break;
	}
}

void PlayerInputs::setNewDirectionAndAbortOthers(std::size_t newState)
{
	for( std::size_t i{0} ; i < inputsStates.size() ; ++i )
	{
		if( i == newState )
		{
			recordAnEvent(i, true);
			inputsStates.setState(i, true);
		}
		else{
			recordAnEvent(i, false);
			inputsStates.setState(i, false);
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

void PlayerInputs::recordAnEvent(std::size_t funcEnum, bool keyState)
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
		if( recordedEvents.hasQuitCommandComeOut() && recordedEvents.sdlQuitEvent.actionState == true )
		{
			inputsStates.setSdlQuitFlag( recordedEvents.sdlQuitEvent.actionState );
		}
	}
}

void PlayerInputs::setEscapeCommandDuringDemo()
{
	if( demoType == demos::GameIsDemo )
	{
		if( recordedEvents.hasEscapeCommandComeOut() && recordedEvents.escapeCommand.actionState == true )
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

