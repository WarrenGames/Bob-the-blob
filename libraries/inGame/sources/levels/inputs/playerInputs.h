#ifndef BOB_THE_BLOB_IN_GAME_PLAYER_INPUTS_H
#define BOB_THE_BLOB_IN_GAME_PLAYER_INPUTS_H

#include "inputsConfig/keyboardInputsConfig.h"
#include "inputsConfig/joystickInputsConfigData.h"
#include "levels/inputs/inputsStates.h"
#include "levels/inputs/eventsRecording.h"
#include "joystick/joystickEntity.h"
#include "SDL_events.h"

struct AppLogFiles;
class PrefPathFinder;

class PlayerInputs
{
private:
	KeyboardInputsConfig keyboardInputsConfig;
	JoystickInputsConfig joystickInputsConfig;

public:
	InputsStates inputsStates;
	RecordedEvents recordedEvents;
	sdl2::JoystickEntity joystickEntity;

private:
	SDL_Event event;
	unsigned demoType;

public:
	explicit PlayerInputs(AppLogFiles& logs, const PrefPathFinder& prefPath, unsigned demoType_);
	~PlayerInputs() = default;
	PlayerInputs( const PlayerInputs& ) = delete;
	PlayerInputs& operator= ( const PlayerInputs& ) = delete;
	PlayerInputs( PlayerInputs&& ) = default;
	PlayerInputs& operator= ( PlayerInputs&& ) = default;
	
	bool wasLoadingPerfect() const;
	void actAccordingToDemoStatus();
	void joinTimePointsForRecording(const AccurateTimeDelay& newDelay);

private:
	void updateEvents();
	void updateKeysStates(SDL_Keycode keycode, bool valueToSet);
	void updateWithJoystickButtonState(SDL_JoystickID joystickNumber, unsigned buttonNumber, bool valueToSet);
	void updateWithJoystickHat(SDL_JoystickID joystickNumber, unsigned hatNumber, unsigned hatState);
	void updateWithJoystickAxis(SDL_JoystickID joystickNumber, unsigned axisNumber, int axisValue);
	void actWithAxisValue(unsigned moveEnum, int axisValue);
	void setNewDirectionAndAbortOthers(std::size_t newState);
	
	void setSdlQuit();
	void setEscapeState(SDL_Keycode keycode, bool valueToSet);
	void recordAnEvent(std::size_t funcEnum, bool keyState);
	
	void setInputsStatesWithRecordedEvents();
	void actWithRecordedDemoActionData(const demos::ActionData& actionData);
	
	void setQuitCommandDuringDemo();
	void setEscapeCommandDuringDemo();
	
	void recordSdlQuitEventIfAny();
	void recordEscapeCommandIfAny(SDL_Keycode lastKeycode, bool isKeycodePushed);
};

#endif //BOB_THE_BLOB_IN_GAME_PLAYER_INPUTS_H