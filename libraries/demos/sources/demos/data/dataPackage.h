#ifndef BOB_THE_BLOB_DEMOS_LIB_DATA_PACKAGE_H
#define BOB_THE_BLOB_DEMOS_LIB_DATA_PACKAGE_H

#include "demos/data/recordedInputsPlayerData.h"
#include "demos/data/positionElements.h"
#include "demos/dataToRecord/soundPlaying.h"
#include "demos/dataToRecord/gameEvents.h"
#include "demos/data/greenOrbDemosData.h"
#include "demos/data/recordedMapElements.h"
#include <string>

struct Essentials;

namespace demos{

struct DataPackage
{
	unsigned demoType;
	unsigned gameAmbience;
	demos::SpritesPositions spritesPositions;
	demos::PlayerInputsData playerInputsData;
	demos::Stack< demos::SoundPlaying > soundsPlaying;
	demos::Stack< demos::GameEvent > gameEvents;
	demos::Stack< demos::GameEvent > levelWonEvents;
	demos::GreenOrbDataStack greenOrbRelatedItemsData;
	demos::MapElements mapsElements;
	const std::string levelName;
	bool haveBobbysStartMoving;
	
	explicit DataPackage(Essentials& essentials, const std::string& levelName_, unsigned demoType_, unsigned gameAmbience_);
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