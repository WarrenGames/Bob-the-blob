#ifndef BOB_THE_BLOB_IN_GAME_LOAD_LEVEL_SUBDIVISION_H
#define BOB_THE_BLOB_IN_GAME_LOAD_LEVEL_SUBDIVISION_H

#include "fileSystem/fileSystem.h"
#include <sstream>

struct SubDivisionFileData;

void loadLevelSubdivision(SubDivisionFileData& subDivisionFileData, const fs::path& subDivFilePath);

void actAccordingToIndex(SubDivisionFileData& subDivisionFileData, std::istringstream& lineStream, int readIndex, const fs::path& dataFilePath, std::size_t fileLineNumber);

void loadSubDivisionPartsNumber(SubDivisionFileData& subDivisionFileData, std::istringstream& lineStream, const fs::path& dataFilePath, std::size_t fileLineNumber);

void loadSubDivisionLinksCoords(SubDivisionFileData& subDivisionFileData, std::istringstream& lineStream, const fs::path& dataFilePath, std::size_t fileLineNumber);

#endif //BOB_THE_BLOB_IN_GAME_LOAD_LEVEL_SUBDIVISION_H