#ifndef BOB_THE_BLOB_IN_GAME_UPDATE_PLAYER_WITH_DEMO_DATA_H
#define BOB_THE_BLOB_IN_GAME_UPDATE_PLAYER_WITH_DEMO_DATA_H

#include <vector>

struct SinglePlayerData;
class PlayerMoving;
struct GameMap;

namespace demos{
	template<typename T>class Stack;
	struct PlayerMove;
	
	void checkNewPlayerPositionEvent(SinglePlayerData& playerMoving, demos::Stack< demos::PlayerMove >& movesStack);
	
	void actWithNewPlayerEvent(PlayerMoving& playerMoving, const demos::PlayerMove& event);
	
	void recordNewPlayerMove(SinglePlayerData& playerData, demos::Stack< demos::PlayerMove >& movesStack);
	
	void recordNewPlayerStop(SinglePlayerData& playerData, demos::Stack< demos::PlayerMove >& movesStack);
	
	void stackNewPlayerPosition(const PlayerMoving& playerMoving, demos::Stack< demos::PlayerMove >& movesStack, unsigned playerId);
	
	void stopPlayerAccordingToMap(PlayerMoving& playerMoving, const GameMap& gameMap);
	
	void checkMapWallsForPlayer(PlayerMoving& playerMoving, const GameMap& gameMap, int x_add, int y_add);
}

#endif //BOB_THE_BLOB_IN_GAME_UPDATE_PLAYER_WITH_DEMO_DATA_H