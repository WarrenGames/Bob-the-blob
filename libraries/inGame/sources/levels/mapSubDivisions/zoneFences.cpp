#include "levels/mapSubDivisions/zoneFences.h"
#include "levels/maps/gameMap.h"
#include "levels/mapSubDivisions/loadSubdivisionData.h"
#include "levels/mapSubDivisions/functions/cutZones.h"
#include "demos/consts/demosConsts.h"

ZonesFences::ZonesFences(const GameMap& gameMap, const fs::path& subDivFilePath, unsigned demoType):
	subDivisionFileData{ },
	globalAreaReference{ gameMap.matrix.getCoordSize() },
	areaCoords{ subDivisionFileData.zonesNumber }
{
	if( demoType == demos::GameHasPlayerInputs || demoType == demos::GameIsRecording )
	{
		loadLevelSubdivision(subDivisionFileData, subDivFilePath);
		areaCoords.resize(subDivisionFileData.zonesNumber);
		cutSubdivisionIntoAreas(gameMap, *this);
		setGlobalAreaReferences(*this);
	}
}

void ZonesFences::setSize(const Coord2D& size)
{
	areaCoords.resize(size);
}

Coord2D ZonesFences::getMatchingCoordinates(const Coord2D& playerPosition)
{
	if( globalAreaReference.isInsideBoundaries(playerPosition) )
	{
		Coord2D toReturnCoords{ getCoordinates( globalAreaReference(playerPosition) ) };
		incrementIndex(playerPosition);
		return toReturnCoords;
	}
	else{
		return Coord2D{ 0, 0 };
	}
}

const Coord2D& ZonesFences::getCoordinates(const Coord2D& matchingAreaCoords) const
{
	return areaCoords(matchingAreaCoords).getCoords();
}

void ZonesFences::incrementIndex(const Coord2D& playerPosition)
{
	areaCoords( globalAreaReference(playerPosition) ).incrementIndex();
}