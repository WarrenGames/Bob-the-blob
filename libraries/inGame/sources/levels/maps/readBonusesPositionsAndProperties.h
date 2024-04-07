#ifndef BOB_THE_BLOB_IN_GAME_READ_APPLES_POSITIONS_AND_PROPERTIES_H
#define BOB_THE_BLOB_IN_GAME_READ_APPLES_POSITIONS_AND_PROPERTIES_H

#include "fileSystem/fileSystem.h"
#include <string>
#include <sstream>

class BonusesMap;

void openBonusesDataFile(BonusesMap& bonusesMap, const fs::path& dataFilePath, const std::string& filePurpose);

void readBonusesData(BonusesMap& bonusesMap, const fs::path& dataFilePath, const std::string& filePurpose, std::istringstream& lineStream, std::size_t fileLineNum);

#endif //BOB_THE_BLOB_IN_GAME_READ_APPLES_POSITIONS_AND_PROPERTIES_H