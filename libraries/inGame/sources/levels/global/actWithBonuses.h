#ifndef BOB_THE_BLOB_IN_GAME_ACT_WITH_BONUSES_H
#define BOB_THE_BLOB_IN_GAME_ACT_WITH_BONUSES_H

#include <chrono>
#include <cstdlib>

struct SinglePlayerData;
class BonusesMap;
class BobsPackage;
struct PlayerAttributes;
struct CommonTexturesSprites;

void eatBonusWithPlayer(SinglePlayerData& player, BonusesMap& bonusesMap, BobsPackage& bobsPackage, PlayerAttributes& playerAttributes);

void createBonusesAnimationData(BonusesMap& bonusesMap, const CommonTexturesSprites& sprites);

#endif //BOB_THE_BLOB_IN_GAME_ACT_WITH_BONUSES_H