#include "levels/gameActors/cactus/cactusObstacle.h"
#include "consts/includeOptions.h"

CactusObstacle::CactusObstacle(const Coord2D& coordinates_, std::size_t textureIndex_, unsigned cactusId):
	coordinates{ coordinates_ },
	cactusTexture{ textureIndex_ },
	status{ CactusIsPlaced },
	itemId{ cactusId },
	isEffective{ true },
	hasRecordedDeath{ false }
{
	
}

Offset CactusObstacle::getRealPosition() const
{
	return Offset{ static_cast<int>(coordinates.width) * SQR_SIZE, static_cast<int>(coordinates.height * SQR_SIZE) };
}

void CactusObstacle::getsDestroyed()
{
	isEffective = false;
	status = CactusIsDestroyed;
}