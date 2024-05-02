#include "demos/dataToRecord/moveAndPosition.h"

demos::MoveAndPosition::MoveAndPosition():
	currentPosition{ 0, 0 },
	protagonistEnum{ 0 },
	nextAction{ 0 },
	demoId{ 0 }
{
	
}

demos::MoveAndPosition::MoveAndPosition(const std::chrono::duration<long double, std::micro>& newDelay, const Coord2D& newPosition, unsigned protEnum, unsigned nextAct, 
														unsigned id):
	delay{ newDelay },
	currentPosition{ newPosition },
	protagonistEnum{ protEnum },
	nextAction{ nextAct },
	demoId{ id }
{
	
}