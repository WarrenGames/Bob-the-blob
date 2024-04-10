#ifndef BOB_THE_BLOB_IN_GAME_COLLISION_BETWEEN_PLAYER_AND_BOBS_H
#define BOB_THE_BLOB_IN_GAME_COLLISION_BETWEEN_PLAYER_AND_BOBS_H

class PlayerMoving;
class BobTheBlob;
struct Coord2D;

bool isCollisioningWithPlayer(const PlayerMoving& playerObject, const BobTheBlob& bobby, int collisionOffset);

bool isPlayerNearEnemySpawnCoordinates(const PlayerMoving& playerObject, const BobTheBlob& bobby);

bool areCoordinatesClose(const Coord2D& coord1, const Coord2D& coord2, int collisionOffset);

#endif //BOB_THE_BLOB_IN_GAME_COLLISION_BETWEEN_PLAYER_AND_BOBS_H