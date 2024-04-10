#include "levels/monstersMoves/collisionBetweenPlayerAndBobs.h"
#include "levels/gameActors/playerThings/playerMoving.h"
#include "levels/gameActors/bobThings/bobTheBlob.h"
#include "levels/gameActors/playerActorsConsts.h"
#include "consts/includeOptions.h"

bool isCollisioningWithPlayer(const PlayerMoving& playerObject, const BobTheBlob& bobby, int collisionOffset)
{
	return playerObject.getRealPosition().x + SQR_SIZE / 2 - collisionOffset >= bobby.getRealPosition().x - SQR_SIZE / 2 + collisionOffset
		&& playerObject.getRealPosition().x - SQR_SIZE / 2 + collisionOffset < bobby.getRealPosition().x + SQR_SIZE / 2 - collisionOffset
		&& playerObject.getRealPosition().y + SQR_SIZE / 2 - collisionOffset >= bobby.getRealPosition().y - SQR_SIZE / 2 + collisionOffset
		&& playerObject.getRealPosition().y - SQR_SIZE / 2 + collisionOffset < bobby.getRealPosition().y + SQR_SIZE / 2 - collisionOffset;
}

bool isPlayerNearEnemySpawnCoordinates(const PlayerMoving& playerObject, const BobTheBlob& bobby)
{
	return areCoordinatesClose(playerObject.getMatrixPosition(), bobby.getStartingPosition(), actors::WithPlayerEnemySpawnDelta );
}

bool areCoordinatesClose(const Coord2D& coord1, const Coord2D& coord2, int collisionOffset)
{
	return static_cast<int>(coord1.width) + collisionOffset > static_cast<int>(coord2.width) 
		&& static_cast<int>(coord1.width) < static_cast<int>(coord2.width) + collisionOffset
		&& static_cast<int>(coord1.height) + collisionOffset > static_cast<int>(coord2.height)
		&& static_cast<int>(coord1.height) < static_cast<int>(coord2.height) + collisionOffset;
}