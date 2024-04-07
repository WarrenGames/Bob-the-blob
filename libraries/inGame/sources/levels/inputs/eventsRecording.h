#ifndef BOB_THE_BLOB_IN_GAME_PLAYER_INPUTS_RECORDING_H
#define BOB_THE_BLOB_IN_GAME_PLAYER_INPUTS_RECORDING_H

#include "demos/dataToRecord/actionData.h"
#include "demos/templates/demoStack.h"
#include "time/accurateTime.h"

struct RecordedEvents
{
	demos::Stack< demos::ActionData > playerInputsStack;
	demos::Stack< demos::ActionData > movesInputsStack;
	demos::ActionData sdlQuitEvent;
	demos::ActionData escapeCommand;
	AccurateTimeDelay recordDelay;

	explicit RecordedEvents(AppLogFiles& logs, unsigned demoType);
	~RecordedEvents() = default;
	RecordedEvents( const RecordedEvents& ) = delete;
	RecordedEvents& operator= ( const RecordedEvents& ) = delete;
	RecordedEvents( RecordedEvents&& ) = default;
	RecordedEvents& operator= ( RecordedEvents&& ) = default;
	
	void recordAndEventIfEnoughAllocated(std::size_t funcEnum, bool keyState);
	
	bool hasQuitCommandComeOut() const;
	bool hasEscapeCommandComeOut() const;
	
	void joinTimePointsForRecording(const AccurateTimeDelay& newDelay);
	
	void recordSdlQuitEventIfAny();
	void recordEscapeKeyEventIfAny(bool keyState);
};

#endif //BOB_THE_BLOB_IN_GAME_PLAYER_INPUTS_RECORDING_H