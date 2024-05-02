#ifndef BOB_THE_BLOB_DEMOS_LIB_STARTING_POSITIONS_H
#define BOB_THE_BLOB_DEMOS_LIB_STARTING_POSITIONS_H

#include "matrices/matrixStructs.h"
#include <chrono>

namespace demos{

struct StartingPosition
{
	unsigned type;
	unsigned subType;
	Coord2D position;
	unsigned id;
	
	StartingPosition();
	StartingPosition(const Coord2D& newPosition, unsigned typeEnum, unsigned subType, unsigned idNumber);
	~StartingPosition() = default;
	StartingPosition( const StartingPosition& ) = default;
	StartingPosition& operator= ( const StartingPosition& ) = default;
	StartingPosition( StartingPosition&& ) = default;
	StartingPosition& operator= ( StartingPosition&& ) = default;
};

}

#endif //BOB_THE_BLOB_DEMOS_LIB_STARTING_POSITIONS_H