#include "levels/gameActors/magicOrbs/singleOrb.h"
#include "levels/maps/bonusesConsts.h"
#include "consts/includeOptions.h"

SingleOrb::SingleOrb():
	orbTextureIndex{ bonuses::OrbMax },
	orbCoordinates{ 0, 0 },
	itemId{ 0 },
	status{ OrbStatusOff },
	isPresent{ false }
{
	
}

SingleOrb::SingleOrb(std::size_t newIndex, const Coord2D& newCoordinates, unsigned newItemId):
	orbTextureIndex{ newIndex },
	orbCoordinates{ newCoordinates },
	itemId{ newItemId },
	status{ OrbStatusCreated },
	isPresent{ true }
{
	durationDelay.joinTimePoints();
}

void SingleOrb::createOrb(std::size_t newIndex, const Coord2D& newCoordinates, unsigned newItemId)
{
	orbTextureIndex = newIndex;
	orbCoordinates = newCoordinates;
	itemId = newItemId;
	status = OrbStatusCreated;
	isPresent = true;
	durationDelay.joinTimePoints();
}

void SingleOrb::abortOrbPresenceIfAny(const std::chrono::milliseconds& orbDurationTime)
{
	if( durationDelay.hasTimeElapsed(orbDurationTime) && isPresent)
	{
		durationDelay.joinTimePoints();
		status = OrbStatusDestroyed;
		isPresent = false;
	}
}

Offset SingleOrb::getRealPosition() const
{
	return Offset{ static_cast<int>(orbCoordinates.width) * SQR_SIZE, static_cast<int>(orbCoordinates.height) * SQR_SIZE };
}