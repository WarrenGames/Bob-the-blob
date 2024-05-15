#include "levels/gameActors/playerThings/singlePlayerData.h"
#include "levels/loadings/gameConfigurationData.h"
#include "levels/textures/texturesConsts.h"

SinglePlayerData::SinglePlayerData(const GameConfigData& gameConfigData, unsigned playerDemoId):
	abilities{ gameConfigData },
	move{ gameConfigData },
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