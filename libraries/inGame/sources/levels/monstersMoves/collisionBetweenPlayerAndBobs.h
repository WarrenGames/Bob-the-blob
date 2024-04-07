#ifndef BOB_THE_BLOB_IN_GAME_COLLISION_BETWEEN_PLAYER_AND_BOBS_H
#define BOB_THE_BLOB_IN_GAME_COLLISION_BETWEEN_PLAYER_AND_BOBS_H

class PlayerMoving;
class BobTheBlob;

bool isCollisioningWithPlayer(const PlayerMoving& playerObject, const BobTheBlob& bobby, int collisionOffset);

#endif //BOB_THE_BLOB_IN_GAME_COLLISION_BETWEEN_PLAYER_AND_BOBS_H