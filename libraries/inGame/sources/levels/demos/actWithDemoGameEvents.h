#ifndef BOB_THE_BLOB_IN_GAME_DEMOS_GAME_EVENTS_H
#define BOB_THE_BLOB_IN_GAME_DEMOS_GAME_EVENTS_H

#include <optional>

struct LevelMandatoryData;
struct PlayerAttributes;

namespace demos{
struct DataPackage;
struct GameEvent;

//For standard levels
void handleGameEvents(LevelMandatoryData& levelData, std::optional<demos::DataPackage>& demoDataPackage, PlayerAttributes& playerAttributes);

void actWithSingleEvent(LevelMandatoryData& levelData, const demos::GameEvent& gameEvent, PlayerAttributes& playerAttributes, bool& haveBobbysStartMoving);

void actWithEnemyBobEvent(LevelMandatoryData& levelData, const demos::GameEvent& gameEvent, PlayerAttributes& playerAttributes, bool& haveBobbysStartMoving);

void playerWasCaughtByBob(LevelMandatoryData& levelData, bool& haveBobbysStartMoving);

void playerAteOneBob(LevelMandatoryData& levelData, const demos::GameEvent& gameEvent, PlayerAttributes& playerAttributes);

}

#endif //BOB_THE_BLOB_IN_GAME_DEMOS_GAME_EVENTS_H