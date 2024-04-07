#ifndef BOB_THE_BLOB_IN_GAME_GET_CONFIG_FILE_NUMBER_H
#define BOB_THE_BLOB_IN_GAME_GET_CONFIG_FILE_NUMBER_H

#include "fileSystem/fileSystem.h"
#include <string>

unsigned getUnsignedIntFromFile(const fs::path& filePath, const std::string& purpose);

#endif //BOB_THE_BLOB_IN_GAME_GET_CONFIG_FILE_NUMBER_H