#ifndef IN_GAME_DEMOS_INITIALIZE_DEMO_STACKS_H
#define IN_GAME_DEMOS_INITIALIZE_DEMO_STACKS_H

struct Essentials;
struct LevelMandatoryData;

namespace demos{
	struct DataPackage;
	
	void initializeStacksNumber(Essentials& essentials, demos::DataPackage *demoDataPackage, const LevelMandatoryData& levelData);
}

#endif //IN_GAME_DEMOS_INITIALIZE_DEMO_STACKS_H