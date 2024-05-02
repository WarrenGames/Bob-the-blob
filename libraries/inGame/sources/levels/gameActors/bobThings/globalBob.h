#ifndef IN_GAME_GAME_ACTORS_GLOBAL_BOB_H
#define IN_GAME_GAME_ACTORS_GLOBAL_BOB_H

#include "levels/monstersMoves/pathFinder.h"
#include "levels/gameActors/bobThings/bobTheBlob.h"
#include "levels/textures/drawing/explosionInfos.h"
#include "time/accurateTime.h"

struct CrossRoadsRandoms;

struct GlobalBob
{
	BobTheBlob bobTheBlob;
	PathFinder bobPathFinder;
	std::size_t lightBulbFrameNumber;
	AccurateTimeDelay animationTime;
	AccurateTimeDelay lightBulbAnimTime;
	std::size_t colorIndex;
	std::size_t frameNumber;
	unsigned demoUniqueId;
	ExplosionInfos blueSpawnExplosion;
	bool canSeekPlayer;
	bool hasPlayedUhOhSound;
	bool isActive;

	explicit GlobalBob(const Coord2D& startingPos, std::size_t colorEnum, unsigned demoIdParam);
	~GlobalBob() = default;
	GlobalBob( const GlobalBob& ) = delete;
	GlobalBob& operator= ( const GlobalBob& ) = delete;
	GlobalBob( GlobalBob&& ) = default;
	GlobalBob& operator= ( GlobalBob&& ) = default;
	
	void updateWithSightedPlayer(const GameMap& gameMap, const Coord2D& playerPosition);
	void updatePathToPlayerIfAny(const GameMap& gameMap, const Coord2D& playerPosition);
	void animateBob(const std::chrono::milliseconds& bobsAnimDelay);
	void animateLightBulb();
	void makeBobForgetPlayer();
	void determineNewDirection(CrossRoadsRandoms& crossRoads);
	void initFirstDirection(const CrossRoadsRandoms& crossRoads);
	void determineNewDirectionWithPlayer();
	void resetBobPosition();
	
	void avoidWallCollisionWhileSeekingPlayer(const GameMap& gameMap, CrossRoadsRandoms& crossRoads);
	void checkEastwardDirectionWithMap(const GameMap& gameMap, CrossRoadsRandoms& crossRoads);
	void checkNorthwardDirectionWithMap(const GameMap& gameMap, CrossRoadsRandoms& crossRoads);
	void checkWestwardDirectionWithMap(const GameMap& gameMap, CrossRoadsRandoms& crossRoads);
	void checkSouthwardDirectionWithMap(const GameMap& gameMap, CrossRoadsRandoms& crossRoads);
	
	void disableBob();
};

#endif //IN_GAME_GAME_ACTORS_GLOBAL_BOB_H