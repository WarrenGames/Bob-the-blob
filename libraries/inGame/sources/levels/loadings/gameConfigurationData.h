#ifndef COMMON_FILES_GAME_CONFIGURATION_DATA_H
#define COMMON_FILES_GAME_CONFIGURATION_DATA_H

#include <chrono>
#include <optional>

struct Essentials;
namespace demos{ struct DataPackage; }

struct GameConfigData
{
	std::chrono::microseconds bobMoveDelay;//Don't affect demo playing regardless its value
	std::chrono::milliseconds bobAnimDelay;//Don't affect demo playing regardless its value
	std::chrono::milliseconds bobSpawnDelay;
	std::chrono::milliseconds bobVulnerability;
	std::chrono::milliseconds greenOrbCreation;//Don't affect demo playing regardless its value
	std::chrono::milliseconds greenOrbDuration;//Don't affect demo playing regardless its value
	std::chrono::milliseconds playerCanEatCactiDelay;
	
	explicit GameConfigData(Essentials& essentials, const std::optional<demos::DataPackage>& demoPackage);
	~GameConfigData() = default;
	GameConfigData( const GameConfigData& ) = delete;
	GameConfigData& operator= ( const GameConfigData& ) = delete;
	GameConfigData( GameConfigData&& ) = default;
	GameConfigData& operator= ( GameConfigData&& ) = default;
	
	void loadDataFromFile(Essentials& essentials);
	void loadDataFromDemoPackage(const std::optional<demos::DataPackage>& demoPackage);
	void setDataToDemoPackage(std::optional<demos::DataPackage>& demoPackage);
};

#endif //COMMON_FILES_GAME_CONFIGURATION_DATA_H