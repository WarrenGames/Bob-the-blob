#ifndef BOB_THE_BLOB_IN_GAME_MAP_SUB_DIVISION_ZONES_FENCES_H
#define BOB_THE_BLOB_IN_GAME_MAP_SUB_DIVISION_ZONES_FENCES_H

#include "levels/mapSubDivisions/subDivFileData.h"
#include "levels/mapSubDivisions/coordinatesSet.h"
#include "matrices/matrix2D.h"

struct GameMap;

struct ZonesFences
{
	SubDivisionFileData subDivisionFileData;
	MatrixTemp2D< Coord2D > globalAreaReference;
	MatrixTemp2D< CoordinatesSet > areaCoords;

	ZonesFences(const GameMap& gameMap, const fs::path& subDivFilePath, unsigned demoType);
	~ZonesFences() = default;
	ZonesFences( const ZonesFences& ) = default;
	ZonesFences& operator= ( const ZonesFences& ) = default;
	
	void setSize(const Coord2D& size);
	Coord2D getMatchingCoordinates(const Coord2D& playerPosition);

	const Coord2D& getCoordinates(const Coord2D& matchingAreaCoords) const;
	void incrementIndex(const Coord2D& playerPosition);
};

#endif //BOB_THE_BLOB_IN_GAME_MAP_SUB_DIVISION_ZONES_FENCES_H