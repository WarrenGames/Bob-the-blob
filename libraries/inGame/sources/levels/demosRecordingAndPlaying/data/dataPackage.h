#ifndef BOB_THE_BLOB_DEMOS_LIB_DATA_PACKAGE_H
#define BOB_THE_BLOB_DEMOS_LIB_DATA_PACKAGE_H

#include "levels/demosRecordingAndPlaying/data/recordedInputsPlayerData.h"
#include "levels/demosRecordingAndPlaying/data/positionElements.h"
#include "levels/demosRecordingAndPlaying/dataToRecord/soundPlaying.h"
#include "levels/demosRecordingAndPlaying/dataToRecord/gameEvents.h"
#include "levels/demosRecordingAndPlaying/data/greenOrbDemosData.h"
#include "levels/demosRecordingAndPlaying/data/recordedMapElements.h"
#include <string>

struct Essentials;

namespace demos{

struct DataPackage
{
	unsigned demoType;
	unsigned gameAmbience;
	unsigned skillLevel;
	demos::SpritesPositions spritesPositions;
	demos::PlayerInputsData playerInputsData;
	demos::Stack< demos::SoundPlaying > soundsPlaying;
	demos::Stack< demos::GameEvent > gameEvents;
	demos::Stack< demos::GameEvent > levelWonEvents;
	demos::GreenOrbDataStack greenOrbRelatedItemsData;
	demos::MapElements mapsElements;
	const std::string levelName;
	long long int enemyBobVulnerabilityDelay;
	bool haveBobbysStartMoving;
	
	explicit DataPackage(Essentials& essentials, const std::string& levelName_, unsigned demoType_, unsigned gameAmbience_, unsigned skillLevel_);
	~DataPackage() = default;
	DataPackage( const DataPackage& ) = delete;
	DataPackage& operator= ( const DataPackage& ) = delete;
	DataPackage( DataPackage&& ) = default;
	DataPackage& operator= ( DataPackage&& ) = default;
	
	void joinTimePoints(const AccurateTimeDelay& newDelay);
	
	void recordGameEvent(unsigned eventCategory, unsigned eventSubType, std::size_t newId);
	void setLevelIsWon();
};

}

#endif //BOB_THE_BLOB_DEMOS_LIB_DATA_PACKAGE_H