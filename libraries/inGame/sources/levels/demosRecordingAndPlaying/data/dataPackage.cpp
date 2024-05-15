#include "levels/demosRecordingAndPlaying/data/dataPackage.h"
#include "package/essentials.h"
#include "pathsFunctions/pathsFunctions.h"
#include "levels/demosRecordingAndPlaying/demosFiles/demoConfigFiles.h"
#include "levels/demosRecordingAndPlaying/consts/demoConfigFilesConsts.h"
#include "levels/demosRecordingAndPlaying/consts/dataRecordingConsts.h"
#include "levels/demosRecordingAndPlaying/consts/gameEventsConsts.h"
#include "consts/skillLevelsConsts.h"
#include <cassert>

demos::DataPackage::DataPackage(Essentials& essentials, const std::string& levelName_, unsigned demoType_, unsigned gameAmbience_, unsigned skillLevel_):
	demoType{ demoType_ },
	gameAmbience{ gameAmbience_ },
	skillLevel{ skillLevel_ },
	spritesPositions{ essentials, demoType_ },
	playerInputsData{ essentials, demoType },
	soundsPlaying{ essentials.logs, demos::fetchStackReservedSize(essentials.logs, path::getDemoConfigRelatedFile(essentials.prefPath, demos::cfgFiles::SoundsPlaying) ), 
					demoType, "sounds playing" },
	gameEvents{ essentials.logs, demos::fetchStackReservedSize(essentials.logs, path::getDemoConfigRelatedFile(essentials.prefPath, demos::cfgFiles::GameEvents) ),
					demoType, "game events" },
	levelWonEvents{ essentials.logs, demos::fetchStackReservedSize(essentials.logs, path::getDemoConfigRelatedFile(essentials.prefPath, demos::cfgFiles::GameEvents) ),
					demoType, "level won events" },
	greenOrbRelatedItemsData{ essentials, demoType },
	mapsElements{},
	levelName{ levelName_ },
	enemyBobVulnerabilityDelay{ 0 },
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

void demos::DataPackage::setLevelIsWon()
{
	if( demoType == demos::GameIsRecording )
	{
		levelWonEvents.emplaceElement( demos::GameEvent{ gameEvents.getCurrentElapsedMicroSecondsTime(), demos::eventCat::GameWon, 0, 0 } );
	}
}











