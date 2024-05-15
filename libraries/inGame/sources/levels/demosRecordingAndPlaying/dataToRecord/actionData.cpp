#include "levels/demosRecordingAndPlaying/dataToRecord/actionData.h"

demos::ActionData::ActionData():
	funcEnum{ 0 },
	actionState{ false }
{
	
}

demos::ActionData::ActionData(const std::chrono::duration<long double, std::micro>& newDelay, unsigned newFunc, bool action):
	delay{ newDelay },
	funcEnum{ newFunc },
	actionState{ action }
{
	
}