#ifndef BOB_THE_BLOB_COMMON_FILES_FILE_DATA_FETCH_H
#define BOB_THE_BLOB_COMMON_FILES_FILE_DATA_FETCH_H

#include "fileSystem/fileSystem.h"
#include <string>

namespace fileDataFetch{

unsigned getUnsignedInt(const fs::path& filePath);

}

#endif //BOB_THE_BLOB_COMMON_FILES_FILE_DATA_FETCH_H