#include "levels/demosRecordingAndPlaying/dataToRecord/itemData.h"

demos::ItemData::ItemData():
	event{ 0 },
	itemId{ 0 }
{
	
}

demos::ItemData::ItemData(const std::chrono::duration<long double, std::micro>& newDelay, const Coord2D& newPosition, unsigned eventType, unsigned idNumber):
	delay{ newDelay },
	position{ newPosition },
	event{ eventType },
	itemId{ idNumber }
{
	
}