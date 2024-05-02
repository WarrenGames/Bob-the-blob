#ifndef BOB_THE_BLOB_IN_GAME_LOAD_MAP_FROM_FILE_H
#define BOB_THE_BLOB_IN_GAME_LOAD_MAP_FROM_FILE_H

#include "fileSystem/fileSystem.h"
#include <sstream>
#include <cstdlib>

struct AppLogFiles;
struct GameMap;

void tryMapFileReading(AppLogFiles& logs, GameMap& gameMap, const fs::path& mapFilePath, bool& isLoadingPerfect);

void loadMapFromFile(GameMap& gameMap, const fs::path& dataFilePath);

void readFirstFileLineForMatrixSize(GameMap& gameMap, const fs::path& dataFilePath, std::ifstream& mapFile, std::size_t& fileLineNumber);

void startLoadingMapData(GameMap& gameMap, const fs::path& dataFilePath, std::ifstream& mapFile, std::size_t& fileLineNumber);

void loadDataFromLineStream(GameMap& gameMap, const fs::path& dataFilePath, std::istringstream& lineStream, std::size_t fileLineNumber);

#endif //BOB_THE_BLOB_IN_GAME_LOAD_MAP_FROM_FILE_H