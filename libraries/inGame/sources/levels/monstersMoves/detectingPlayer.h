#ifndef BOB_THE_BLOB_IN_GAME_DETECTING_PLAYER_H
#define BOB_THE_BLOB_IN_GAME_DETECTING_PLAYER_H

#include <vector>

struct GameMap;
struct Coord2D;
struct IdealPathChunk;

bool hasPlayerBeenDetected(const GameMap& gameMap, const Coord2D& destination, const Coord2D& origin, int rangeBeforeDetection, std::vector< IdealPathChunk >& idealPath);

bool hasPlayerBeenDetectedOnBobbysLeft(const GameMap& gameMap, const Coord2D& destination, const Coord2D& origin, int rangeBeforeDetection, std::vector< IdealPathChunk >& idealPath);

bool hasPlayerBeenDetectedOnBobbysRight(const GameMap& gameMap, const Coord2D& destination, const Coord2D& origin, int rangeBeforeDetection, std::vector< IdealPathChunk >& idealPath);

bool hasPlayerBeenDetectedOnBobbysTop(const GameMap& gameMap, const Coord2D& destination, const Coord2D& origin, int rangeBeforeDetection, std::vector< IdealPathChunk >& idealPath);

bool hasPlayerBeenDetectedOnBobbysBottom(const GameMap& gameMap, const Coord2D& destination, const Coord2D& origin, int rangeBeforeDetection, std::vector< IdealPathChunk >& idealPath);

bool isSquareAWall(int width, int height, const GameMap& gameMap);

void fillWesternDetection(const Coord2D& destination, const Coord2D& origin, int rangeBeforeDetection, std::vector< IdealPathChunk >& idealPath);

void fillEasternDetection(const Coord2D& destination, const Coord2D& origin, int rangeBeforeDetection, std::vector< IdealPathChunk >& idealPath, const GameMap& gameMap);

void fillNorthernDetection(const Coord2D& destination, const Coord2D& origin, int rangeBeforeDetection, std::vector< IdealPathChunk >& idealPath);

void fillSouthernDetection(const Coord2D& destination, const Coord2D& origin, int rangeBeforeDetection, std::vector< IdealPathChunk >& idealPath, const GameMap& gameMap);

void fillIdealPathChunk(std::size_t constantValue, std::size_t& constantAxisValue, std::size_t changingAxisValue, std::size_t& changingAxisCoordValue);

void fillOtherInfos(unsigned directionEnumValue, IdealPathChunk& idealPathChunk);

#endif //BOB_THE_BLOB_IN_GAME_DETECTING_PLAYER_H