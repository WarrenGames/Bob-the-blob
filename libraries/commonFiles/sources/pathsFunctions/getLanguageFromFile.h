#ifndef BOB_COMMON_FILES_GET_LANGUAGE_FROM_FILE_H
#define BOB_COMMON_FILES_GET_LANGUAGE_FROM_FILE_H

#include "fileSystem/fileSystem.h"

struct AppLogFiles;



std::string getChosenLanguageFromFile(AppLogFiles& logs, const fs::path& filePath);

#endif //BOB_COMMON_FILES_GET_LANGUAGE_FROM_FILE_H