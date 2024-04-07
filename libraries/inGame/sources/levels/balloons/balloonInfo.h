#ifndef BOB_THE_BLOB_IN_GAME_BALLOON_INFO_H
#define BOB_THE_BLOB_IN_GAME_BALLOON_INFO_H

#include "matrices/matrixStructs.h"
#include "customTypes/positionTypes.h"

struct BalloonInfos
{
	Coord2D screenSquarePosition;
	Offset accuratePosition;
	unsigned contentType;
	unsigned typeSubValue;
	bool isOccupied;
	
	explicit BalloonInfos();
	explicit BalloonInfos(const Coord2D& readCoordinates);
	~BalloonInfos() = default;
	BalloonInfos( const BalloonInfos& ) = default;
	BalloonInfos& operator= ( const BalloonInfos& ) = default;
	BalloonInfos( BalloonInfos&& ) = default;
	BalloonInfos& operator= ( BalloonInfos&& ) = default;
};

#endif //BOB_THE_BLOB_IN_GAME_BALLOON_INFO_H