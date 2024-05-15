#include "levels/demosRecordingAndPlaying/data/recordedInputsPlayerData.h"
#include "levels/demosRecordingAndPlaying/demosFiles/demoConfigFiles.h"
#include "package/essentials.h"
#include "levels/demosRecordingAndPlaying/consts/demoConfigFilesConsts.h"
#include "pathsFunctions/pathsFunctions.h"

demos::PlayerInputsData::PlayerInputsData(Essentials& essentials, unsigned demoType):
	playerInputs{ essentials.logs, demos::fetchStackReservedSize(essentials.logs, path::getDemoConfigRelatedFile(essentials.prefPath, demos::cfgFiles::ActionData) ), 
					demoType, "player inputs" }
	//movesInputs{ essentials.logs, demos::fetchStackReservedSize(essentials.logs, path::getDemoConfigRelatedFile(essentials.prefPath, demos::cfgFiles::ActionData) ), 
	//				demoType, "movesInputs" }
{
	
}

/*
void demos::PlayerInputsData::copyPlayerInputsToMovesInputs()
{
	for( auto const &data : playerInputs )
	{
		movesInputs.emplaceElement(data);
	}
}
*/

void demos::PlayerInputsData::joinTimePoints(const AccurateTimeDelay& newDelay)
{
	playerInputs.transferDelayTimePointValue(newDelay);
	//movesInputs.transferDelayTimePointValue(newDelay);
}