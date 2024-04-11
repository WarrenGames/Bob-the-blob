#include "demos/data/dataPackage.h"
#include "package/essentials.h"
#include "pathsFunctions/pathsFunctions.h"
#include "demos/demosFiles/demoConfigFiles.h"
#include "demos/consts/demoConfigFilesConsts.h"
#include "demos/consts/dataRecordingConsts.h"
#include <cassert>

demos::DataPackage::DataPackage(Essentials& essentials, const std::string& levelName_, unsigned demoType_, unsigned gameAmbience_):
	demoType{ demoType_ },
	gameAmbience{ gameAmbience_ },
	spritesPositions{ essentials, demoType_ },
	playerInputsData{ essentials, demoType },
	soundsPlaying{ essentials.logs, demos::fetchStackReservedSize(essentials.logs, path::getDemoConfigRelatedFile(essentials.prefPath, demos::files::SoundsPlaying) ), 
					demoType, "sounds playing" },
	gameEvents{ essentials.logs, demos::fetchStackReservedSize(essentials.logs, path::getDemoConfigRelatedFile(essentials.prefPath, demos::files::GameEvents) ),
					demoType, "game events" },
	greenOrbRelatedItemsData{ essentials, demoType },
	mapsElements{},
	levelName{ levelName_ },
	haveBobbysStartMoving{false}
{
	assert( demoType < demos::GameDemoEnumMax );
}

void demos::DataPackage::joinTimePoints(const AccurateTimeDelay& newDelay)
{
	spritesPositions.joinAllTimePoints(newDelay);
	playerInputsData.joinTimePoints(newDelay);
	soundsPlaying.transferDelayTimePointValue(newDelay);
	gameEvents.transferDelayTimePointValue(newDelay);
	greenOrbRelatedItemsData.joinTimePoints(newDelay);
}

void demos::DataPackage::recordGameEvent(unsigned eventCategory, unsigned eventSubType, std::size_t newId)
{
	if( demoType == demos::GameIsRecording )
	{
		gameEvents.emplaceElement( demos::GameEvent{ gameEvents.getCurrentElapsedMicroSecondsTime(), eventCategory, eventSubType, newId } );
	}
}












