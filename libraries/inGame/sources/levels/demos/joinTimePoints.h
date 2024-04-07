#ifndef BOB_THE_BLOB_IN_GAME_LEVEL_DEMOS_JOIN_TIME_POINTS_H
#define BOB_THE_BLOB_IN_GAME_LEVEL_DEMOS_JOIN_TIME_POINTS_H

struct LevelMandatoryData;

namespace demos{

struct DataPackage;
	
void joinTimePoints(demos::DataPackage *demoDataPackage, LevelMandatoryData& levelData);

}
#endif //BOB_THE_BLOB_IN_GAME_LEVEL_DEMOS_JOIN_TIME_POINTS_H