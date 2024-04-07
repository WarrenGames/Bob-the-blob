#include "levels/monstersMoves/collisionBetweenPlayerAndBobs.h"
#include "levels/gameActors/playerThings/playerMoving.h"
#include "levels/gameActors/bobThings/bobTheBlob.h"
#include "consts/includeOptions.h"

bool isCollisioningWithPlayer(const PlayerMoving& playerObject, const BobTheBlob& bobby, int collisionOffset)
{
	return playerObject.getRealPosition().x + SQR_SIZE / 2 - collisionOffset >= bobby.getRealPosition().x - SQR_SIZE / 2 + collisionOffset
		&& playerObject.getRealPosition().x - SQR_SIZE / 2 + collisionOffset < bobby.getRealPosition().x + SQR_SIZE / 2 - collisionOffset
		&& playerObject.getRealPosition().y + SQR_SIZE / 2 - collisionOffset >= bobby.getRealPosition().y - SQR_SIZE / 2 + collisionOffset
		&& playerObject.getRealPosition().y - SQR_SIZE / 2 + collisionOffset < bobby.getRealPosition().y + SQR_SIZE / 2 - collisionOffset;
}