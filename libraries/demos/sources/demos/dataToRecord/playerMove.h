#ifndef BOB_THE_BLOB_DEMOS_LIB_PLAYER_MOVE_DATA_H
#define BOB_THE_BLOB_DEMOS_LIB_PLAYER_MOVE_DATA_H

#include "matrices/matrixStructs.h"
#include <chrono>

namespace demos{

struct PlayerMove
{
	std::chrono::duration<long double, std::micro> delay;
	Coord2D position;
	unsigned action;
	unsigned playerId;
	
	PlayerMove();
	PlayerMove(const std::chrono::duration<long double, std::micro>& newDelay, const Coord2D& newPosition, unsigned newAction, unsigned newPlayerId);
	~PlayerMove() = default;
	PlayerMove( const PlayerMove& ) = default;
	PlayerMove& operator= ( const PlayerMove& ) = default;
};

}

#endif //BOB_THE_BLOB_DEMOS_LIB_PLAYER_MOVE_DATA_H