#ifndef BOB_THE_BLOB_IN_GAME_UPDATE_BALLOONS_H
#define BOB_THE_BLOB_IN_GAME_UPDATE_BALLOONS_H

#include <cstdlib>

struct LevelMandatoryData;
class BalloonsPositions;
class BobsPackage;
class OrbsPackage;
struct Offset;
struct ScreenScrolling;

void updateBalloons(LevelMandatoryData& levelMandatoryData);

void updateMexicanBalloons(LevelMandatoryData& levelMandatoryData, const OrbsPackage& orbsPackage);

void updateBallonsWithOrbs(BalloonsPositions& balloonsPositions, const OrbsPackage& orbsPackage, const ScreenScrolling& screenScrolling);

void updateBalloonsWithEnemyBobs(BalloonsPositions& balloonsPositions, const BobsPackage& bobsPackage, const ScreenScrolling& screenScrolling);

std::size_t getPositionEnumForBalloons(const Offset& position, const ScreenScrolling& screenScrolling);

#endif //BOB_THE_BLOB_IN_GAME_UPDATE_BALLOONS_H