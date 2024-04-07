#ifndef BOB_THE_BLOB_IN_GAME_BOB_THE_BLOB_OBJECT_H
#define BOB_THE_BLOB_IN_GAME_BOB_THE_BLOB_OBJECT_H

#include "matrices/matrixStructs.h"
#include "customTypes/positionTypes.h"
#include "time/accurateTime.h"
#include <cstdlib>

class PrefPathFinder;
struct GameMap;

class PlayerMoving
{
private:
	std::size_t textureDirection;
	Coord2D inMatrixPosition;
	Offset realPosition;
	AccurateTimeDelay moveTime;
	unsigned wantedNextDirection;
	unsigned currentDirection;
	unsigned moveState;
	std::chrono::microseconds moveDelay;
	bool canChangeDirection;

public:
	PlayerMoving(const PrefPathFinder& prefPath);
	~PlayerMoving() = default;
	PlayerMoving( const PlayerMoving& ) = delete;
	PlayerMoving& operator= ( const PlayerMoving& ) = delete;
	PlayerMoving( PlayerMoving&& ) = default;
	PlayerMoving& operator= ( PlayerMoving&& ) = default;
	
	const Coord2D& getMatrixPosition() const;
	const Offset& getRealPosition() const;
	Offset& getRealPosition();
	unsigned getCurrentDirection() const;
	bool getDirectionChangeAbility() const;
	void setDirectionChangeAbility(bool newValue);
	void changeWantedDirection(unsigned newDirection);
	void setCurrentDirection(unsigned newCurrentDirection);
	bool isPlayerStopped() const;
	
	void resetInMatrixPosition(const Coord2D& newCoord);
	bool hasReachCenterOfSquare() const;
	bool hasReachOutsideOfMap(const GameMap& gameMap);
	void setNewMatrixPosition();
	void checkMoveDelayToMove();
	void move();
	void resetPositionWhileRestarting(const Coord2D& startingPosition);
	void updateRealPositionWithNewCoord2D();
	void stopPlayer();
	void setNewMoveWithDemoStack(unsigned newDirection);
	void changePlayerDirection(const GameMap& gameMap);
	bool canGetANewDirection(const GameMap& gameMap, int mat_x_add, int mat_y_add);
	void setMoveState(unsigned newMoveState);
	
private:
	void setNewDirectionIfAny(const GameMap& gameMap, int mat_x_add, int mat_y_add);
};

#endif //BOB_THE_BLOB_IN_GAME_BOB_THE_BLOB_OBJECT_H