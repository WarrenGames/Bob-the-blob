#ifndef BOB_THE_BLOB_DEMOS_LIB_DEMO_CONFIG_FILES_H
#define BOB_THE_BLOB_DEMOS_LIB_DEMO_CONFIG_FILES_H

#include "fileSystem/fileSystem.h"

struct AppLogFiles;

namespace demos{

std::size_t fetchStackReservedSize(AppLogFiles& logs, const fs::path& filePath);

}

#endif //BOB_THE_BLOB_DEMOS_LIB_DEMO_CONFIG_FILES_H