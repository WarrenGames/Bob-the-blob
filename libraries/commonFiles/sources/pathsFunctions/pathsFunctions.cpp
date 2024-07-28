#include "pathsFunctions/pathsFunctions.h"
#include "prefPath/prefPathFinder.h"
#include "consts/filesAndPaths.h"

fs::path path::getLanguageFile(const fs::path& language, const fs::path& fileSubPath)
{
	return fs::path{ files::LanguagesFilesDirectory / language / fileSubPath };
}

fs::path path::getOptionFilePath(const PrefPathFinder& prefPath, const fs::path& fileName)
{
	return fs::path{ prefPath.getFsPath() / files::OptionsDir / fileName };
}

fs::path path::getPrefPathFilePath(const PrefPathFinder& prefPath, const fs::path& fileName)
{
	return fs::path{ prefPath.getFsPath() / fileName };
}

fs::path path::getInputsFilePath(const PrefPathFinder& prefPath, const fs::path& fileName)
{
	return fs::path{ prefPath.getFsPath() / files::InputsDir / fileName };
}

fs::path path::getGameConfigFilePath(const fs::path& levelNamePrefix, const fs::path& fileSuffix)
{
	fs::path path{ files::DefaultMapsFilesDir / levelNamePrefix / levelNamePrefix };
	path += fileSuffix;
	return path;
}

fs::path path::getDemoConfigRelatedFile(const PrefPathFinder& prefPath, const fs::path& fileName)
{
	return fs::path{ prefPath.getFsPath() / files::DemosConfigDir / fileName };
}

fs::path path::getBenchmarksFilePath(const PrefPathFinder& prefPath, const fs::path& fileName)
{
	return fs::path{ prefPath.getFsPath() / files::BenchmarksConfigDir / fileName };
}