#ifndef BOB_THE_BLOB_IN_GAME_READ_START_POSITION_IN_FILE_H
#define BOB_THE_BLOB_IN_GAME_READ_START_POSITION_IN_FILE_H

#include "fileSystem/fileSystem.h"
#include <string>
#include <sstream>

struct Coord2D;
class BobsPackage;

void loadPositionFromFile(Coord2D& coordinates, const fs::path& dataFilePath, const std::string& filePurpose);

void loadBobsDataFromFile(BobsPackage& bobsPackage, const fs::path& dataFilePath, const std::string& filePurpose, unsigned skillLevel);

void loadSingleBobData(BobsPackage& bobsPackage, const fs::path& dataFilePath, const std::string& filePurpose, std::istringstream& lineStream, std::size_t fileLineNum,
						unsigned skillLevel);

#endif //BOB_THE_BLOB_IN_GAME_READ_START_POSITION_IN_FILE_H