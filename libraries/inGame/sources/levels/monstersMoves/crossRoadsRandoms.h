#ifndef BOB_THE_BLOB_IN_GAME_CROSS_ROADS_RANDOMS_H
#define BOB_THE_BLOB_IN_GAME_CROSS_ROADS_RANDOMS_H

#include "matrices/matrix2D.h"
#include <random>

struct GameMap;
struct Coord2D;
struct Offset;

struct CrossRoadsRandoms
{
	std::mt19937 mersenne;
	MatrixTemp2D< std::vector< unsigned > > gameMapDirections;
	std::vector< unsigned > forbiddenDirections;
	
	explicit CrossRoadsRandoms(const GameMap& gameMap);
	~CrossRoadsRandoms() = default;
	CrossRoadsRandoms( const CrossRoadsRandoms& ) = delete;
	CrossRoadsRandoms& operator= ( const CrossRoadsRandoms& ) = delete;
	CrossRoadsRandoms( CrossRoadsRandoms&& ) = default;
	CrossRoadsRandoms& operator= ( CrossRoadsRandoms&& ) = default;
	
	void createCrossRoadsPossibleDirections(const GameMap& gameMap);
	void addDirectionToCrossRoadsMatrix(const GameMap& gameMap, const Coord2D& coords, const Offset& decal, unsigned direction);
	void meltDirectionsInMatrix();
	void meltSingleCrossRoads(const Coord2D& coords);
};

#endif //BOB_THE_BLOB_IN_GAME_CROSS_ROADS_RANDOMS_H