#include "levels/mapSubDivisions/functions/cutZones.h"
#include "levels/mapSubDivisions/zoneFences.h"
#include "levels/maps/gameMap.h"

void cutSubdivisionIntoAreas(const GameMap& gameMap, ZonesFences& zonesFences)
{
	for( std::size_t width{ 0 } ; width < zonesFences.areaCoords.width() ; ++width )
	{
		for( std::size_t height{ 0 } ; height < zonesFences.areaCoords.height() ; ++height )
		{
			browseAreaCoords(gameMap, zonesFences, width, height);
		}
	}
}

void browseAreaCoords(const GameMap& gameMap, ZonesFences& zonesFences, std::size_t areaWidth, std::size_t areaHeight)
{
	for( std::size_t mapWidth{ getMapValue(areaWidth, zonesFences.areaCoords.width(), gameMap.matrix.width() ) } ; 
								mapWidth < getMapValue( areaWidth + 1, zonesFences.areaCoords.width(), gameMap.matrix.width() ) ; ++mapWidth )
	{
		for( std::size_t mapHeight{ getMapValue(areaHeight, zonesFences.areaCoords.height(), gameMap.matrix.height() ) } ;
				mapHeight < getMapValue( areaHeight + 1, zonesFences.areaCoords.height(), gameMap.matrix.height() ) ; ++mapHeight )
		{
			if( gameMap.matrix(mapWidth, mapHeight).mapIndex == 0 )
			{
				zonesFences.areaCoords(areaWidth, areaHeight).addElement( Coord2D{ mapWidth, mapHeight } );
			}
		}
	}
	zonesFences.areaCoords(areaWidth, areaHeight).meltCoordinates();
}

std::size_t getMapValue(std::size_t areaNum, std::size_t areaTotalNumber, std::size_t axisMapSize)
{
	return areaNum * axisMapSize / areaTotalNumber;
}

void setGlobalAreaReferences(ZonesFences& zonesFences)
{
	for( std::size_t mapWidth{0} ; mapWidth < zonesFences.globalAreaReference.width() ; ++mapWidth )
	{
		std::size_t areaWitdh{ getAreaValue(mapWidth, zonesFences.globalAreaReference.width(), zonesFences.areaCoords.width() ) };
		for( std::size_t mapHeight{0} ; mapHeight < zonesFences.globalAreaReference.height() ; ++mapHeight )
		{
			std::size_t areaHeight{ getAreaValue(mapHeight, zonesFences.globalAreaReference.height(), zonesFences.areaCoords.height() ) };
			
			const auto it{ zonesFences.subDivisionFileData.getMatchingCoord(Coord2D{ areaWitdh, areaHeight } ) };
			
			if( it != zonesFences.subDivisionFileData.subdivisionLinks.end() )
			{
				zonesFences.globalAreaReference(mapWidth, mapHeight) = it->second;
			}
		}
	}
}

std::size_t getAreaValue(std::size_t mapIndex, std::size_t axisMapSize, std::size_t areaTotalNumber)
{
	return mapIndex * areaTotalNumber / axisMapSize;
}