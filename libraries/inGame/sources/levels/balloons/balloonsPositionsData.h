#ifndef BOB_THE_BLOB_IN_GAME_BALLOON_POSITIONS_DATA_H
#define BOB_THE_BLOB_IN_GAME_BALLOON_POSITIONS_DATA_H

#include "levels/balloons/balloonInfo.h"
#include "matrices/matrix2D.h"
#include <sstream>

class BalloonsPositions
{
private:
	MatrixTemp2D< BalloonInfos > positions;
	
public:
	BalloonsPositions();
	~BalloonsPositions() = default;
	BalloonsPositions( const BalloonsPositions& ) = delete;
	BalloonsPositions& operator= ( const BalloonsPositions& ) = delete;
	BalloonsPositions( BalloonsPositions&& ) = default;
	BalloonsPositions& operator= ( BalloonsPositions&& ) = default;
	
	std::size_t getScreenEnumMax() const;
	std::size_t getPerZoneNumber() const;
	
	const BalloonInfos& getElement(std::size_t screenPositionEnum, std::size_t balloonNumber) const;
	
	bool activateNewBalloonIfPossible(std::size_t screenPositionEnum, unsigned contentType, unsigned typeSubValue);
	
	std::vector< BalloonInfos >::const_iterator begin() const;
	std::vector< BalloonInfos >::const_iterator end() const;
	void resetAllBalloons();
};

void loadBalloonDataFromFile(MatrixTemp2D< BalloonInfos >& balloons);

void readBalloonPositionLine(MatrixTemp2D< BalloonInfos >& balloons, std::istringstream& lineStream, std::size_t screenPositionEnum);

#endif //BOB_THE_BLOB_IN_GAME_BALLOON_POSITIONS_DATA_H