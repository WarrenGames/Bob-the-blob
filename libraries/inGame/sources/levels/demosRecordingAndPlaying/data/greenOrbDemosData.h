#ifndef BOB_THE_BLOB_DEMOS_LIB_ITEMS_DATA_STACKS_H
#define BOB_THE_BLOB_DEMOS_LIB_ITEMS_DATA_STACKS_H

#include "levels/demosRecordingAndPlaying/dataToRecord/itemData.h"
#include "levels/demosRecordingAndPlaying/dataToRecord/gameEvents.h"
#include "levels/demosRecordingAndPlaying/templates/demoStack.h"

struct Essentials;

namespace demos{

struct GreenOrbDataStack
{
	demos::Stack< demos::ItemData > greenOrb;//Green orbs apparitions and destructions
	demos::Stack< demos::GameEvent > greenOrbsAndPlayer;//Whenever a player acquire a green orb ability
	demos::Stack< demos::GameEvent > cactiLife;//Whenever a player destroy a cactus or get killed by it
	long long int greenOrbPowerDuration;//Milliseconds
	
	explicit GreenOrbDataStack(Essentials& essentials, unsigned demoType);
	~GreenOrbDataStack() = default;
	GreenOrbDataStack( const GreenOrbDataStack& ) = delete;
	GreenOrbDataStack& operator= ( const GreenOrbDataStack& ) = delete;
	GreenOrbDataStack( GreenOrbDataStack&& ) = default;
	GreenOrbDataStack& operator= ( GreenOrbDataStack&& ) = default;
	
	void joinTimePoints(const AccurateTimeDelay& newDelay);
};

}

#endif //BOB_THE_BLOB_DEMOS_LIB_ITEMS_DATA_STACKS_H