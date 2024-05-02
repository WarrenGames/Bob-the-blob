#ifndef BOB_THE_BLOB_IN_GAME_BOB_THE_BLOB_H
#define BOB_THE_BLOB_IN_GAME_BOB_THE_BLOB_H

#include "matrices/matrixStructs.h"
#include "customTypes/positionTypes.h"

struct GameMap;

class BobTheBlob
{
private:
	Coord2D startingPosition;
	Coord2D inMatrixPosition;
	Offset realPosition;
	unsigned currentDirection;
	bool hasMovedSince;

public:
	explicit BobTheBlob(const Coord2D& startingPos);
	~BobTheBlob() = default;
	BobTheBlob( const BobTheBlob& ) = delete;
	BobTheBlob& operator= ( const BobTheBlob& ) = delete;
	BobTheBlob( BobTheBlob&& ) = default;
	BobTheBlob& operator= ( BobTheBlob&& ) = default;
	
	const Coord2D& getMatrixPosition() const;
	const Coord2D& getStartingPosition() const;
	const Offset& getRealPosition() const;
	void setCurrentDirection(unsigned newDirection);
	unsigned getCurrentDirection() const;
	unsigned& getCurrentDirection();
	bool getHasMoveSince() const;
	
	void setRealPosition();
	bool hasReachCenterOfSquare() const;
	void checkMoveDelay();
	void moveBob();
	void setMatrixPosition();
	
	void resetBobbyPosition();
	void avoidMapLeaving(const GameMap& gameMap);
	void avoidMapLeavingFromLeft();
	void avoidMapLeavingFromRight(const GameMap& gameMap);
	void avoidMapLeavingFromTop();
	void avoidMapLeavingFromBottom(const GameMap& gameMap);
	void setFlagOffHasMovedSince();
	
	//Used with demo view only
	void changeCurrentDirection(unsigned newDirection);
	void setPosition(const Coord2D& newCoords);
};

#endif //BOB_THE_BLOB_IN_GAME_BOB_THE_BLOB_H