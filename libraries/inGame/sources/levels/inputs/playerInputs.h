#ifndef BOB_THE_BLOB_IN_GAME_PLAYER_INPUTS_H
#define BOB_THE_BLOB_IN_GAME_PLAYER_INPUTS_H

#include "inputsConfig/keyboardInputsConfig.h"
#include "levels/inputs/inputsStates.h"
#include "levels/inputs/eventsRecording.h"
#include "SDL_events.h"

struct AppLogFiles;
class PrefPathFinder;

class PlayerInputs
{
private:
	KeyboardInputsConfig keyboardInputsConfig;

public:
	InputsStates inputsStates;
	RecordedEvents recordedEvents;

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
	
	void actAccordingToDemoStatus();
	void joinTimePointsForRecording(const AccurateTimeDelay& newDelay);

private:
	void updateEvents();
	void updateKeysStates(SDL_Keycode keycode, bool valueToSet);
	void setSdlQuit();
	void setEscapeState(SDL_Keycode keycode, bool valueToSet);
	void recordAndEvent(std::size_t funcEnum, bool keyState);
	
	void setInputsStatesWithRecordedEvents();
	void actWithRecordedDemoActionData(const demos::ActionData& actionData);
	
	void setQuitCommandDuringDemo();
	void setEscapeCommandDuringDemo();
	
	void recordSdlQuitEventIfAny();
	void recordEscapeCommandIfAny(SDL_Keycode lastKeycode, bool isKeycodePushed);
};

#endif //BOB_THE_BLOB_IN_GAME_PLAYER_INPUTS_H