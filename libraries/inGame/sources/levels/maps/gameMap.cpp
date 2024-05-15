#include "levels/maps/gameMap.h"
#include "levels/maps/loadMapFromFile.h"
#include "logging/logsStruct.h"
#include "levels/demosRecordingAndPlaying/consts/demosConsts.h"

GameMap::GameMap(AppLogFiles& logs, const fs::path& mapFilePath, bool& isLoadingPerfect, unsigned demoType)
{
	if( demoType == demos::GameHasPlayerInputs || demoType == demos::GameIsRecording )
	{
		tryMapFileReading(logs, *this, mapFilePath, isLoadingPerfect);
	}
}
