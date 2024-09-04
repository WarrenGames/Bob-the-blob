#ifndef BOB_THE_BLOB_IN_GAME_GREEN_ORBS_PLAYER_POWER_H
#define BOB_THE_BLOB_IN_GAME_GREEN_ORBS_PLAYER_POWER_H

#include <optional>

struct SinglePlayerData;
namespace demos{ struct DataPackage; template<typename>class Stack; struct GameEvent; }

namespace greenOrb{

void checkForPowerEvent(SinglePlayerData& player, std::optional<demos::DataPackage>& demoDataPackage);

void startOrStopPower(SinglePlayerData& player, demos::Stack< demos::GameEvent >& stack); 

}

#endif //BOB_THE_BLOB_IN_GAME_GREEN_ORBS_PLAYER_POWER_H