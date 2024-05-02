#ifndef BOB_THE_BLOB_IN_GAME_SINGLE_PLAYER_DATA_H
#define BOB_THE_BLOB_IN_GAME_SINGLE_PLAYER_DATA_H

#include "levels/gameActors/playerThings/playerMapRelativeAbilities.h"
#include "levels/gameActors/playerThings/playerMoving.h"
#include "levels/animation/spriteAnimation.h"

class PrefPathFinder;

struct SinglePlayerData
{
	PlayerAbilities abilities;
	PlayerMoving move;
	SpriteAnimation anim;
	Coord2D playerStartingPosition;
	unsigned playerId;
	bool hasActionBeenRecorded;
	bool hasStopBeenRecorded;
	
	
	explicit SinglePlayerData(const PrefPathFinder& prefPath, unsigned playerDemoId);
	~SinglePlayerData() = default;
	SinglePlayerData( const SinglePlayerData& ) = delete;
	SinglePlayerData& operator= ( const SinglePlayerData& ) = delete;
	SinglePlayerData( SinglePlayerData&& ) = default;
	SinglePlayerData& operator= ( SinglePlayerData&& ) = default;
	
	void resetPosition();
};

#endif //BOB_THE_BLOB_IN_GAME_SINGLE_PLAYER_DATA_H