#ifndef DEMOS_LIB_DETERMINE_GAME_STATUS_H
#define DEMOS_LIB_DETERMINE_GAME_STATUS_H

#include <optional>

namespace demos{

struct DataPackage;

unsigned getGameStatus(const std::optional<demos::DataPackage>& demoDataPackage);

}

#endif //DEMOS_LIB_DETERMINE_GAME_STATUS_H