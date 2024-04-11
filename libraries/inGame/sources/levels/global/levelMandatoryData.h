#ifndef BOB_THE_BLOB_IN_GAME_GLOBAL_LEVEL_MANDATORY_DATA_H
#define BOB_THE_BLOB_IN_GAME_GLOBAL_LEVEL_MANDATORY_DATA_H

#include "levels/gameActors/playerThings/singlePlayerData.h"
#include "levels/gameActors/bobThings/bobsPackage.h"
#include "levels/maps/gameMap.h"
#include "levels/maps/bonusesMap.h"
#include "levels/monstersMoves/crossRoadsRandoms.h"
#include "levels/inputs/playerInputs.h"
#include "sounds/gameSoundSystem.h"
#include "levels/textures/drawing/screenScrolling.h"
#include "levels/balloons/balloonsPositionsData.h"
#include "levels/mapSubDivisions/zoneFences.h"
#include "levels/levelFinish/levelFinishInterface.h"
#include "fileSystem/fileSystem.h"

struct Essentials;
namespace demos{ struct DataPackage; }

struct LevelMandatoryData
{
	bool isLoadingPerfect;
	bool hasLevelEnded;
	bool quitLevel;
	unsigned demoType;
	GameMap gameMap;
	BonusesMap bonusesMap;
	SinglePlayerData playerData;
	BobsPackage bobsPackage;
	CrossRoadsRandoms crossRoadsRandoms;
	PlayerInputs playerInputs;
	GameSoundSystem gameSoundSystem;
	ScreenScrolling screenScrolling;
	BalloonsPositions balloonsPositions;
	ZonesFences zonesFences;
	AccurateTimeDelay levelFinishDelay;
	LevelFinishInterface levelFinishInterface;
	
	explicit LevelMandatoryData(Essentials& essentials, const fs::path& levelPrefix, demos::DataPackage* demoDataPackage);
	~LevelMandatoryData() = default;
	LevelMandatoryData( const LevelMandatoryData& ) = delete;
	LevelMandatoryData& operator= ( const LevelMandatoryData& ) = delete;
	LevelMandatoryData( LevelMandatoryData&& ) = default;
	LevelMandatoryData& operator= ( LevelMandatoryData&& ) = default;
	
	void recordStartingData(demos::DataPackage& demoDataPackage) const;
	void setLevelDataFromRecordedDemo(const demos::DataPackage& demoDataPackage);
	void actWithDemoStatus(demos::DataPackage* demoDataPackage);
	
	Coord2D getGameMapSize(const demos::DataPackage* demoDataPackage) const;
	
	void displayLevelEndMessage(sdl2::RendererWindow& rndWnd);
	
	void actWithLevelEnd(demos::DataPackage* demoDataPackage, bool externWinningCondition);
	
	void checkLevelEndCondition(bool externWinningCondition);
	void checkLevelEndCondition(demos::DataPackage* demoDataPackage, bool externWinningCondition);
	void updateLevelExiting();
	
	bool canQuitLevel() const;
	
	void claimVictory();
	void claimVictoryWithRecordedDemoData(demos::DataPackage* demoDataPackage);
};

#endif //BOB_THE_BLOB_IN_GAME_GLOBAL_LEVEL_MANDATORY_DATA_H