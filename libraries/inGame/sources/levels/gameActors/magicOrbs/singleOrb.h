#ifndef BOB_THE_BLOB_IN_GAME_SINGLE_ORB_DATA_H
#define BOB_THE_BLOB_IN_GAME_SINGLE_ORB_DATA_H

#include "matrices/matrixStructs.h"
#include "time/accurateTime.h"
#include "customTypes/positionTypes.h"

enum : unsigned{
	OrbStatusOff,
	OrbStatusCreated,
	OrbStatusCreatedAndRecorded,
	OrbStatusDestroyed,
	OrbStatusDestroyedAndRecorded,
	OrbStatusMax
};

struct SingleOrb
{
	std::size_t orbTextureIndex;
	Coord2D orbCoordinates;
	AccurateTimeDelay durationDelay;
	unsigned itemId;
	unsigned status;
	bool isPresent;
	
	SingleOrb();
	SingleOrb(std::size_t newIndex, const Coord2D& newCoordinates, unsigned newItemId);
	~SingleOrb() = default;
	SingleOrb( const SingleOrb& ) = delete;
	SingleOrb& operator= ( const SingleOrb& ) = delete;
	SingleOrb( SingleOrb&& ) = default;
	SingleOrb& operator= ( SingleOrb&& ) = default;
	
	void createOrb(std::size_t newIndex, const Coord2D& newCoordinates, unsigned newItemId);
	void abortOrbPresenceIfAny(const std::chrono::milliseconds& orbDuration);
	
	Offset getRealPosition() const;
};

#endif //BOB_THE_BLOB_IN_GAME_SINGLE_ORB_DATA_H