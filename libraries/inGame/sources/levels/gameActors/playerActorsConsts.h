#ifndef BOB_THE_BLOB_IN_GAME_BOB_THE_BLOB_ACTORS_CONSTS_H
#define BOB_THE_BLOB_IN_GAME_BOB_THE_BLOB_ACTORS_CONSTS_H

#include "consts/includeOptions.h"
#include <cstdlib>

namespace actors{
	
	enum : unsigned{ PlayerIsStopped, PlayerIsMoving };
	
	constexpr int DefaultMoveMicroSecDelay = static_cast<int>( 64.0 * 8.0 / SQR_SIZE * 1000 );
	
	constexpr int PlayerDetectionRange = 5;//4 before
	
	constexpr std::size_t PathFinderLength = 16;
	
	constexpr int WithPlayerEnemySpawnDelta = 7;
}

namespace abilities{
	enum{
		CanEatBob,
		CanEatCacti,
		CanEatMax
	};
}

#endif //BOB_THE_BLOB_IN_GAME_BOB_THE_BLOB_ACTORS_CONSTS_H