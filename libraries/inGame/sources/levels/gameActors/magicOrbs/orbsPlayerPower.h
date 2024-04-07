#ifndef BOB_THE_BLOB_IN_GAME_GREEN_ORBS_PLAYER_POWER_H
#define BOB_THE_BLOB_IN_GAME_GREEN_ORBS_PLAYER_POWER_H

struct SinglePlayerData;
struct PlayerAttributes;
namespace demos{ struct DataPackage; template<typename>class Stack; struct GameEvent; }

namespace greenOrb{

void checkForPowerEvent(SinglePlayerData& player, PlayerAttributes& playerAttributes, demos::DataPackage* demoDataPackage);

void enablePower(SinglePlayerData& player, PlayerAttributes& playerAttributes, demos::Stack< demos::GameEvent >& stack); 

}

#endif //BOB_THE_BLOB_IN_GAME_GREEN_ORBS_PLAYER_POWER_H