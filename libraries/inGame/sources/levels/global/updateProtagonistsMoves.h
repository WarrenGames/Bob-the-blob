#ifndef BOB_THE_BLOB_IN_GAME_UPDATE_PROTAGONISTS_MOVES_H
#define BOB_THE_BLOB_IN_GAME_UPDATE_PROTAGONISTS_MOVES_H

class PlayerMoving;
class BobsPackage;
struct GameMap;
struct SinglePlayerData;
class SoundPlayer;
class PlayerInputs;
namespace demos{ struct DataPackage; }

void wrapPlayerThatHasLeftOnWest(PlayerMoving& playerObject, BobsPackage& bobsPackage, const GameMap& gameMap);

void wrapPlayerThatHasLeftOnEast(PlayerMoving& playerObject, BobsPackage& bobsPackage, const GameMap& gameMap);

void wrapPlayerThatHasLeftOnNorth(PlayerMoving& playerObject, BobsPackage& bobsPackage, const GameMap& gameMap);

void wrapPlayerThatHasLeftOnSouth(PlayerMoving& playerObject, BobsPackage& bobsPackage, const GameMap& gameMap);

void updateBobbysDetectionWithSound(const SinglePlayerData& player, BobsPackage& bobsPackage, const GameMap& gameMap, const SoundPlayer& soundPlayer, demos::DataPackage *demoDataPackage);

void playUhOhSoundOnce(const SoundPlayer& soundPlayer, demos::DataPackage *demoDataPackage, bool canSeekPlayer, bool& hasPlayedUhOhSound);

void resetPlayerDirectionChangementPossibility(PlayerMoving& playerObject);

void changeWantedNextDirection(PlayerInputs& playerInputs, PlayerMoving& playerObject);

#endif //BOB_THE_BLOB_IN_GAME_UPDATE_PROTAGONISTS_MOVES_H