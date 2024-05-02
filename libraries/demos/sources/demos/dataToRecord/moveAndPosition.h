#ifndef BOB_THE_BLOB_DEMOS_LIB_NEW_POSITION_AND_NEXT_DIRECTION_H
#define BOB_THE_BLOB_DEMOS_LIB_NEW_POSITION_AND_NEXT_DIRECTION_H

#include "matrices/matrixStructs.h"
#include <chrono>

namespace demos{

struct MoveAndPosition
{
	std::chrono::duration<long double, std::micro> delay;
	Coord2D currentPosition;
	unsigned protagonistEnum;//Color index
	unsigned nextAction;//Represents direction for enemy
	unsigned demoId;//Only for enemies
	
	MoveAndPosition();
	MoveAndPosition(const std::chrono::duration<long double, std::micro>& newDelay, const Coord2D& newPosition, unsigned protEnum, unsigned nextAct, unsigned id);
	~MoveAndPosition() = default;
	MoveAndPosition( const MoveAndPosition& ) = default;
	MoveAndPosition& operator= ( const MoveAndPosition& ) = default;
	MoveAndPosition( MoveAndPosition&& ) = default;
	MoveAndPosition& operator= ( MoveAndPosition&& ) = default;
};

}

#endif //BOB_THE_BLOB_DEMOS_LIB_NEW_POSITION_AND_NEXT_DIRECTION_H