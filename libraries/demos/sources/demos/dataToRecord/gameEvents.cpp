#include "demos/dataToRecord/gameEvents.h"
#include "demos/consts/gameEventsConsts.h"

demos::GameEvent::GameEvent():
	category{ demos::eventCat::Max },
	subType{ 0 },
	id{ 0 }
{
	
}

demos::GameEvent::GameEvent(const std::chrono::duration<long double, std::micro>& newDelay, unsigned eventCategory, unsigned eventSubType, std::size_t newId):
	delay{ newDelay },
	category{ eventCategory },
	subType{ eventSubType },
	id{ newId }
{
	
}