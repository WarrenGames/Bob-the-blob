#ifndef BOB_THE_BLOB_IN_GAME_HANDLE_COLORED_ORBS_COLLECTION_H
#define BOB_THE_BLOB_IN_GAME_HANDLE_COLORED_ORBS_COLLECTION_H

#include <cstdlib>

struct LevelMandatoryData;
class OrbsPackage;
struct PlayerAttributes;
namespace demos{ struct DataPackage; }
struct SinglePlayerData;

void browseColoredOrbCollection(LevelMandatoryData& levelData, OrbsPackage& orbsPackage, PlayerAttributes& playerAttributes, demos::DataPackage* demoDataPackage, std::size_t abilityIndex);
void handleOrbsAccordingToDemoValue(SinglePlayerData& player, OrbsPackage& orbsPackage, PlayerAttributes& playerAttributes, demos::DataPackage* demoDataPackage, std::size_t abilityIndex);

void browseOrbsForPlayer(SinglePlayerData& player, OrbsPackage& orbsPackage, PlayerAttributes& playerAttributes, std::size_t abilityIndex);


#endif //BOB_THE_BLOB_IN_GAME_HANDLE_COLORED_ORBS_COLLECTION_H