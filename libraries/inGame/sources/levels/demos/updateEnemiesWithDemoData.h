#ifndef BOB_THE_BLOB_IN_GAME_UPDATE_ENEMIES_WITH_DEMO_DATA_H
#define BOB_THE_BLOB_IN_GAME_UPDATE_ENEMIES_WITH_DEMO_DATA_H

#include <vector>

class BobsPackage;
class BobTheBlob;
struct GlobalBob;
struct Coord2D;
class PlayerMoving;
struct GameMap;

namespace demos{
	template<typename T>class Stack;
	struct MoveAndPosition;
	
	void checkNewBobbyPositionEvent(BobsPackage& bobsPackage, std::vector< demos::Stack< demos::MoveAndPosition > >& enemyBobsMoves);
	
	void determineBobbyNextDirection(BobTheBlob& bobTheBlob, const Coord2D& nextCoords);
	
	void actWithNewBobbyPositionEvent(BobTheBlob& bobTheBlob, const demos::MoveAndPosition& event);
	
	void recordBobbysPackagePosition(unsigned demoType, const BobsPackage& bobsPackage, std::vector< demos::Stack< demos::MoveAndPosition > >& movesStack);
	
	void recordNewBobbyPosition(unsigned demoType, const GlobalBob& globalBob, demos::Stack< demos::MoveAndPosition >& movesStack, std::size_t bobIndex);
	
	void stackBobbyPositionData(const GlobalBob& globalBob, demos::Stack< demos::MoveAndPosition >& movesStack, std::size_t bobIndex);
	
	void makeBobbysStartMoving(BobsPackage& bobsPackage, std::vector< demos::Stack< demos::MoveAndPosition > >& enemyBobsMoves, bool& haveBobbysStartMoving);
	
	void makeBobbysStopSeekingPlayer(PlayerMoving& playerMoving, BobsPackage& bobsPackage, const GameMap& gameMap);
}

#endif //BOB_THE_BLOB_IN_GAME_UPDATE_ENEMIES_WITH_DEMO_DATA_H