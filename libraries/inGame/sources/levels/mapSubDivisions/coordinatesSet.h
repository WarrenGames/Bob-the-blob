#ifndef BOB_THE_BLOB_IN_GAME_MAP_SUB_DIVISION_COORDINATES_SET_H
#define BOB_THE_BLOB_IN_GAME_MAP_SUB_DIVISION_COORDINATES_SET_H

/*
	Represents all the coordinates in a given zone (that may not be the entire map)
		that are valid for any protagonist to move on (including the player) or for 
		an item to appear. The game will pick a coordinates at a given time for any 
		task then it will increment the 'index' value so that the next picked 
		coordinate is different.
*/

#include "matrices/matrixStructs.h"
#include <vector>

class CoordinatesSet
{
private:
	std::size_t index;
	std::vector< Coord2D > coordsSet;

public:
	CoordinatesSet();
	~CoordinatesSet() = default;
	CoordinatesSet( const CoordinatesSet& ) = default;
	CoordinatesSet& operator= ( const CoordinatesSet& ) = default;
	
	void incrementIndex();
	const Coord2D& getCoords() const;
	void addElement(const Coord2D& newCoord);
	void meltCoordinates();
	std::size_t size() const;
};

#endif //BOB_THE_BLOB_IN_GAME_MAP_SUB_DIVISION_COORDINATES_SET_H