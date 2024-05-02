#include "levels/monstersMoves/crossRoadsRandoms.h"
#include "levels/maps/gameMap.h"
#include "customTypes/positionTypes.h"
#include "levels/monstersMoves/monstersMovesConsts.h"
#include "levels/textures/texturesConsts.h"
#include <algorithm>
#include <chrono>

CrossRoadsRandoms::CrossRoadsRandoms(const GameMap& gameMap):
	mersenne{ static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) },
	gameMapDirections{ gameMap.matrix.width(), gameMap.matrix.height() },
	forbiddenDirections{ RoadToWest, RoadToSouth, RoadToEast, RoadToNorth }
{
	
}

void CrossRoadsRandoms::createCrossRoadsPossibleDirections(const GameMap& gameMap)
{
	for( std::size_t height{0} ; height < gameMap.matrix.height() ; ++height )
	{
		for( std::size_t width{0} ; width < gameMap.matrix.width() ; ++width )
		{
			if( gameMap.matrix(width, height).mapIndex == textures::SquareEmpty )
			{
				addDirectionToCrossRoadsMatrix(gameMap, Coord2D{width, height}, Offset{1, 0}, RoadToEast);
				addDirectionToCrossRoadsMatrix(gameMap, Coord2D{width, height}, Offset{0, -1}, RoadToNorth);
				addDirectionToCrossRoadsMatrix(gameMap, Coord2D{width, height}, Offset{-1, 0}, RoadToWest);
				addDirectionToCrossRoadsMatrix(gameMap, Coord2D{width, height}, Offset{0, 1}, RoadToSouth);
			}
		}
	}
}

void CrossRoadsRandoms::addDirectionToCrossRoadsMatrix(const GameMap& gameMap, const Coord2D& coords, const Offset& decal, unsigned direction)
{
	const Coord2D resultingCoords{ coords.width + decal.x, coords.height + decal.y };
	
	if( gameMap.matrix.isInsideBoundaries(resultingCoords) && gameMap.matrix(resultingCoords).mapIndex == textures::SquareEmpty )
	{
		gameMapDirections(coords).emplace_back( direction );
	}
}

void CrossRoadsRandoms::meltDirectionsInMatrix()
{
	for( std::size_t height{0} ; height < gameMapDirections.height() ; ++height )
	{
		for( std::size_t width{0} ; width < gameMapDirections.width() ; ++width )
		{
			meltSingleCrossRoads(Coord2D{width, height} );
		}
	}
}

void CrossRoadsRandoms::meltSingleCrossRoads(const Coord2D& coords)
{
	if( gameMapDirections.isInsideBoundaries(coords) && gameMapDirections(coords).size() >= 2 )
	{
		std::shuffle(gameMapDirections(coords).begin(), gameMapDirections(coords).end(), mersenne);
	}
}