#ifndef BOB_THE_BLOB_IN_GAME_ACT_WITH_BONUSES_H
#define BOB_THE_BLOB_IN_GAME_ACT_WITH_BONUSES_H

#include <chrono>
#include <cstdlib>

struct SinglePlayerData;
class BonusesMap;
class BobsPackage;
struct PlayerAttributes;
struct CommonTexturesSprites;
struct BonusElement;

void eatBonusWithPlayer(SinglePlayerData& player, BonusesMap& bonusesMap, BobsPackage& bobsPackage, PlayerAttributes& playerAttributes);

void updateBonusesAnimation(BonusesMap& bonusesMap, CommonTexturesSprites& sprites);

void animSingleBonus(BonusElement& bonusElement, std::size_t bonusFramesNumber, const std::chrono::milliseconds& delay);

#endif //BOB_THE_BLOB_IN_GAME_ACT_WITH_BONUSES_H