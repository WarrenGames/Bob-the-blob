#ifndef BOB_THE_BLOB_IN_GAME_LEVEL_CONTEXT_H
#define BOB_THE_BLOB_IN_GAME_LEVEL_CONTEXT_H

#include "fileSystem/fileSystem.h"

struct Essentials;
struct PlayerAttributes;
struct GameGlobalObject;
namespace demos{ struct DataPackage; }

namespace standardLevel{

void levelContext(Essentials& essentials, PlayerAttributes& playerAttributes, const fs::path& levelPrefix, demos::DataPackage *demoPackage);

void quitContext(const GameGlobalObject& gameGlobalObject, bool& quitLevel);

void drawEverything(Essentials& essentials, GameGlobalObject& gameGlobalObject);

}

#endif //BOB_THE_BLOB_IN_GAME_LEVEL_CONTEXT_H