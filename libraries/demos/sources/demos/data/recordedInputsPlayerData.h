#ifndef BOB_THE_BLOB_DEMOS_LIB_RECORDDED_INPUTS_PLAYER_DATA_H
#define BOB_THE_BLOB_DEMOS_LIB_RECORDDED_INPUTS_PLAYER_DATA_H

#include "demos/dataToRecord/actionData.h"
#include "demos/templates/demoStack.h"

struct Essentials;

namespace demos{

struct PlayerInputsData
{
	demos::Stack< demos::ActionData > playerInputs;
	//demos::Stack< demos::ActionData > movesInputs;//Must be a copy of 'playerInputs'
	demos::ActionData sdlQuitEvent;
	demos::ActionData escapeCommand;
	
	explicit PlayerInputsData(Essentials& essentials, unsigned demoType);
	~PlayerInputsData() = default;
	PlayerInputsData( const PlayerInputsData& ) = delete;
	PlayerInputsData& operator= ( const PlayerInputsData& ) = delete;
	PlayerInputsData( PlayerInputsData&& ) = default;
	PlayerInputsData& operator= ( PlayerInputsData&& ) = default;
	
	//void copyPlayerInputsToMovesInputs();
	
	void joinTimePoints(const AccurateTimeDelay& newDelay);
};

}

#endif //BOB_THE_BLOB_DEMOS_LIB_RECORDDED_INPUTS_PLAYER_DATA_H