#ifndef BOB_THE_BLOB_IN_GAME_UPDATE_GAME_H
#define BOB_THE_BLOB_IN_GAME_UPDATE_GAME_H

#include <cstdlib>
#include <optional>

struct Essentials;
struct PlayerAttributes;
struct SinglePlayerData;
struct ScoreDisplay;
class InfoGradient;
class Ability;
class PlayerAbilities;
struct ScreenScrolling;
struct LevelMandatoryData;
namespace demos{ struct DataPackage; }
class BobsPackage;

void update(Essentials& essentials, PlayerAttributes& playerAttributes, LevelMandatoryData& levelData, ScoreDisplay& scoreDisplay, std::optional<demos::DataPackage>& demoDataPackage);

void bothRecordAndStandardGamePlaying(LevelMandatoryData& levelData, std::optional<demos::DataPackage>& demoDataPackage);

void updateScreenScrolling(const SinglePlayerData& player, ScreenScrolling& screenScrolling);

void updatePlayerThings(LevelMandatoryData& levelData, std::optional<demos::DataPackage>& demoDataPackage);

void updateEnemyProtagonists(LevelMandatoryData& levelData, std::optional<demos::DataPackage>& demoDataPackage, PlayerAttributes& playerAttributes);

void bothRecordAndStandardPlayingEnemyProtagonists(LevelMandatoryData& levelData, std::optional<demos::DataPackage>& demoDataPackage, PlayerAttributes& playerAttributes);

void updateInfoGradient(InfoGradient& infoGradient, Ability& ability);

void updateWithSoundsEventsStack(LevelMandatoryData& levelData, std::optional<demos::DataPackage>& demoDataPackage);

void demoGameEnemyUpdate(LevelMandatoryData& levelData, std::optional<demos::DataPackage>& demoDataPackage);

void updateBobbysExplosionsIfAny(BobsPackage& bobsPackage, std::size_t explosionFramesNumber);

void exitDemo(LevelMandatoryData& levelData);

void abortPlayerAbilities(PlayerAbilities& playerAbilities);

#endif //BOB_THE_BLOB_IN_GAME_UPDATE_GAME_H