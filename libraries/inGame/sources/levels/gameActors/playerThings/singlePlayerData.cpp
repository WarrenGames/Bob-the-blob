#include "levels/gameActors/playerThings/singlePlayerData.h"
#include "levels/textures/texturesConsts.h"

SinglePlayerData::SinglePlayerData(const PrefPathFinder& prefPath, unsigned playerDemoId):
	abilities{ prefPath },
	move{ prefPath },
	anim{ textures::PlayerFramesNumber, std::chrono::milliseconds{ textures::PlayerFrameDuration } },
	playerId{ playerDemoId },
	hasActionBeenRecorded{ true },
	hasStopBeenRecorded{ true }
{
	
}

void SinglePlayerData::resetPosition()
{
	move.resetInMatrixPosition(playerStartingPosition);
	move.resetPositionWhileRestarting(playerStartingPosition);
	move.stopPlayer();
}