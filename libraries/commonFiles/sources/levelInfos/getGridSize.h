#ifndef COMMON_FILES_LEVEL_INFOS_GET_GRID_SIZE_H
#define COMMON_FILES_LEVEL_INFOS_GET_GRID_SIZE_H

#include "fileSystem/fileSystem.h"
#include "customTypes/positionTypes.h"
#include <string>

struct Essentials;
struct AppLogFiles;

enum : std::size_t{
	TxtGridSize,
	TxtMax
};

constexpr char LanguageFile[] = "levelChoiceMenu/gridSize.txt";

Offset getLevelGridSize(AppLogFiles& logs, const fs::path& levelGridPath);

std::string getLevelGridSizeText(const std::string& languageText, const Offset& levelSize);

#endif //COMMON_FILES_LEVEL_INFOS_GET_GRID_SIZE_H