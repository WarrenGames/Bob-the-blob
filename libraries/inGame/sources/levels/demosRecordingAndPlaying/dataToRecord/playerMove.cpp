#include "levels/demosRecordingAndPlaying/dataToRecord/playerMove.h"

demos::PlayerMove::PlayerMove():
	action{ 0 },
	playerId{ 0 }
{

}

demos::PlayerMove::PlayerMove(const std::chrono::duration<long double, std::micro>& newDelay, const Coord2D& newPosition, unsigned newAction, unsigned newPlayerId):
	delay{ newDelay },
	position{ newPosition },
	action{ newAction },
	playerId{ newPlayerId }
{
	
}