#ifndef BOB_THE_BLOB_IN_GAME_MAPS_LOAD_PLAUYER_POSITION_H
#define BOB_THE_BLOB_IN_GAME_MAPS_LOAD_PLAUYER_POSITION_H

#include "fileSystem/fileSystem.h"

struct AppLogFiles;
struct SinglePlayerData;

void loadPlayerPosition(AppLogFiles& logs, SinglePlayerData& playerObject, const fs::path& positionFilePath, bool& isLoadingPerfect, unsigned demoType);

#endif //BOB_THE_BLOB_IN_GAME_MAPS_LOAD_PLAUYER_POSITION_H