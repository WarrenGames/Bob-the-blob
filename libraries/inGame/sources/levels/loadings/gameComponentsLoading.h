#ifndef BOB_THE_BLOB_IN_GAME_COMPONENTS_LOADING_H
#define BOB_THE_BLOB_IN_GAME_COMPONENTS_LOADING_H

#include "fileSystem/fileSystem.h"
#include <optional>

struct Essentials;
struct LevelMandatoryData;
namespace demos{ struct DataPackage; }

void loadAndInitializeGameComponents(Essentials& essentials, LevelMandatoryData& levelData, const fs::path& levelPrefix, std::optional<demos::DataPackage>& demoDataPackage);

void loadMapSubdivision(LevelMandatoryData& levelData, std::optional<demos::DataPackage>& demoDataPackage);

#endif //BOB_THE_BLOB_IN_GAME_COMPONENTS_LOADING_H