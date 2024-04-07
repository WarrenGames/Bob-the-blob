#ifndef BOB_THE_BLOB_GAME_CREATE_FOLDERS_IN_PREF_PATH_H
#define BOB_THE_BLOB_GAME_CREATE_FOLDERS_IN_PREF_PATH_H

#include "fileSystem/fileSystem.h"
#include <iosfwd>
#include <string>

class PrefPathFinder;
struct AppLogFiles;

namespace filesSetup{

void setupFiles(const PrefPathFinder& prefPath, AppLogFiles& logs);

void createFileInPath(AppLogFiles& logs, const fs::path& filePath, const std::string& dataToWrite);

void writeInOptionFile(AppLogFiles& logs, const fs::path& filePath, std::ofstream& file, const std::string& dataToWrite);

std::string getDefaultKeybInpFileStr();

}

#endif // BOB_THE_BLOB_GAME_CREATE_FOLDERS_IN_PREF_PATH_H