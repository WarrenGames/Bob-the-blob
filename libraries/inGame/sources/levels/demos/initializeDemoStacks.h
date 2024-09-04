#ifndef IN_GAME_DEMOS_INITIALIZE_DEMO_STACKS_H
#define IN_GAME_DEMOS_INITIALIZE_DEMO_STACKS_H

#include <optional>

struct Essentials;
struct LevelMandatoryData;

namespace demos{
	struct DataPackage;
	
	void initializeStacksNumber(Essentials& essentials, std::optional<demos::DataPackage>& demoDataPackage, const LevelMandatoryData& levelData);
}

#endif //IN_GAME_DEMOS_INITIALIZE_DEMO_STACKS_H