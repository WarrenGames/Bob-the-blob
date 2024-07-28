#ifndef PACMAN_COMMON_FILES_PATHS_FUNCTIONS_H
#define PACMAN_COMMON_FILES_PATHS_FUNCTIONS_H

#include "fileSystem/fileSystem.h"

class PrefPathFinder;

namespace path{

fs::path getLanguageFile(const fs::path& language, const fs::path& fileSubPath);

fs::path getOptionFilePath(const PrefPathFinder& prefPath, const fs::path& fileName);

fs::path getPrefPathFilePath(const PrefPathFinder& prefPath, const fs::path& fileName);

fs::path getInputsFilePath(const PrefPathFinder& prefPath, const fs::path& fileName);

fs::path getGameConfigFilePath(const fs::path& levelNamePrefix, const fs::path& fileSuffix);

fs::path getDemoConfigRelatedFile(const PrefPathFinder& prefPath, const fs::path& fileName);

fs::path getBenchmarksFilePath(const PrefPathFinder& prefPath, const fs::path& fileName);

}

#endif //PACMAN_COMMON_FILES_PATHS_FUNCTIONS_H