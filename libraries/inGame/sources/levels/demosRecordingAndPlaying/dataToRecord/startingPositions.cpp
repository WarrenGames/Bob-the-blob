#include "levels/demosRecordingAndPlaying/dataToRecord/startingPositions.h"
#include "levels/demosRecordingAndPlaying/consts/dataRecordingConsts.h"

demos::StartingPosition::StartingPosition():
	type{ demosData::StartPosMax },
	subType{ 0 },
	position{ 0, 0 },
	id{ 0 }
{
	
}

demos::StartingPosition::StartingPosition(const Coord2D& newPosition, unsigned objectTypeEnum, unsigned objectOption, unsigned idNumber):
	type{ objectTypeEnum },
	subType{ objectOption },
	position{ newPosition },
	id{ idNumber }
{
	
}