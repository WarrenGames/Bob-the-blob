#ifndef BOB_THE_BLOB_IN_GAME_GAME_MONSTERS_MOVES_PATH_ELEMENT_H
#define BOB_THE_BLOB_IN_GAME_GAME_MONSTERS_MOVES_PATH_ELEMENT_H

#include "matrices/matrixStructs.h"

struct PathElement
{
	unsigned startDirection;
	bool canBeAnalysed;
	
	PathElement();
	~PathElement() = default;
	PathElement( const PathElement& ) = default;
	PathElement& operator= ( const PathElement& ) = default;
	PathElement( PathElement&& ) = default;
	PathElement& operator= ( PathElement&& ) = default;
};

struct IdealPathChunk
{
	Coord2D coords;
	unsigned effectiveDirection;
	bool isRelevant;
	
	IdealPathChunk();
	~IdealPathChunk() = default;
	IdealPathChunk( const IdealPathChunk& ) = default;
	IdealPathChunk& operator= ( const IdealPathChunk& ) = default;
	IdealPathChunk( IdealPathChunk&& ) = default;
	IdealPathChunk& operator= ( IdealPathChunk&& ) = default;
	
	void setFlagOff();
	void setEffectiveDirection(unsigned roadDirectionEnumValue);
};

#endif //BOB_THE_BLOB_IN_GAME_GAME_MONSTERS_MOVES_PATH_ELEMENT_H