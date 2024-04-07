#ifndef DEMOS_LIB_GAME_EVENTS_CONSTS_H
#define DEMOS_LIB_GAME_EVENTS_CONSTS_H

namespace demos{

	namespace eventCat{	//Event category
		enum : unsigned{
			Bob,
			OrbLife,
			CactusAndPlayer,
			CactusLife,
			PlayerPower,
			Max
		};
	}

	namespace eventSubBob{
		enum : unsigned{
			CatchPlayer,
			EatenByPlayer,
			Max
		};
	}
	
	namespace eventItem{
		enum : unsigned{ 
			Creation,
			Destruction,
			Max
		};
	}
	
	namespace playerPower{
		enum : unsigned{
			GreenOrb,
			Max
		};
	}
}

#endif //DEMOS_LIB_GAME_EVENTS_CONSTS_H