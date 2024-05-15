#ifndef BOB_THE_BLOB_IN_GAME_MEXICAN_ZONE_CONTEXT_H
#define BOB_THE_BLOB_IN_GAME_MEXICAN_ZONE_CONTEXT_H

#include "fileSystem/fileSystem.h"

struct Essentials;
struct PlayerAttributes;
struct MexicanGameObject;
namespace demos{ struct DataPackage; }

namespace mexican{

void levelContext(Essentials& essentials, PlayerAttributes& playerAttributes, const fs::path& levelPrefix, demos::DataPackage *demoPackage);

void quitContext(const MexicanGameObject& mexicanGameObject, bool& quitLevel);

void drawEverything(Essentials& essentials, MexicanGameObject& mexicanGameObject);

}

#endif //BOB_THE_BLOB_IN_GAME_MEXICAN_ZONE_CONTEXT_H