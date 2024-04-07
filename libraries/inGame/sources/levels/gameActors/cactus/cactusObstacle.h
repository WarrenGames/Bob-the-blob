#ifndef BOB_THE_BLOB_IN_GAME_GAME_ACTORS_CACTUS_OBSTACLE_H
#define BOB_THE_BLOB_IN_GAME_GAME_ACTORS_CACTUS_OBSTACLE_H

#include "matrices/matrixStructs.h"
#include "customTypes/positionTypes.h"

enum : unsigned{
	CactusIsPlaced,
	CactusIsDestroyed,
	CactusIsDestroyedAndRecorded,
	CactusKillsPlayer
};

struct CactusObstacle
{
	Coord2D coordinates;
	std::size_t cactusTexture;
	unsigned status;
	unsigned itemId;
	bool isEffective;
	bool hasRecordedDeath;
	
	explicit CactusObstacle(const Coord2D& coordinates_, std::size_t textureIndex_, unsigned cactusId);
	~CactusObstacle() = default;
	CactusObstacle( const CactusObstacle& ) = delete;
	CactusObstacle& operator= ( const CactusObstacle& ) = delete;
	CactusObstacle( CactusObstacle&& ) = default;
	CactusObstacle& operator= ( CactusObstacle&& ) = default;
	
	Offset getRealPosition() const;
	void getsDestroyed();
};

#endif //BOB_THE_BLOB_IN_GAME_GAME_ACTORS_CACTUS_OBSTACLE_H