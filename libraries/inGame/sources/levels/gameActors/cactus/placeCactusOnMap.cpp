#include "levels/gameActors/cactus/placeCactusOnMap.h"
#include "levels/gameActors/cactus/cactiPackage.h"
#include "levels/mapSubDivisions/zoneFences.h"
#include "exceptions/readErrorExcept.h"
#include "levels/textures/texturesConsts.h"
#include "levels/textures/mexicanTexturesConsts.h"
#include "levels/gameActors/cactus/cactiConsts.h"
#include <cassert>

void cacti::placeCactiInAllZones(unsigned perZoneCactiNumber, ZonesFences& zonesFences, CactiPackage& cactiPackage, const Coord2D& playerStartingPosition)
{
	if( perZoneCactiNumber > 0 )
	{
		cacti::placeCacti(perZoneCactiNumber, zonesFences, cactiPackage, playerStartingPosition);
	}
	else{
		throw ReadError{"Error: zero cacti per zone to place on map."}; 
	}
}

void cacti::placeCacti(unsigned perZoneCactiNumber, ZonesFences& zonesFences, CactiPackage& cactiPackage, const Coord2D& playerStartingPosition)
{
	unsigned itemId{0};
	std::size_t cactusEnum{0};
	
	for( unsigned cactiNumber{0} ; cactiNumber < perZoneCactiNumber ; ++cactiNumber )
	{
		for( std::size_t i{0} ; i < zonesFences.areaCoords.size(); ++i )
		{
			if( perZoneCactiNumber < zonesFences.areaCoords[i].size() )
			{
				Coord2D newCactusCoords{ zonesFences.areaCoords[i].getCoords() };
				while( coords::are2DCoordsTheSame(newCactusCoords, playerStartingPosition) )
				{
					zonesFences.areaCoords[i].incrementIndex();
					newCactusCoords = zonesFences.areaCoords[i].getCoords();
				}
				cactiPackage.addCactus( zonesFences.areaCoords[i].getCoords(), cactusEnum, itemId );
				cacti::loopCactusType(cactusEnum);
				itemId++;
			}
			else{
				throw ReadError{"Error: too much cacti per zone to place on map."}; 
			}
		}
	}
}

void cacti::loopCactusType(std::size_t& cactusEnum)
{
	if( cactusEnum + 1 < textures::mexican::CactusMax )
	{
		cactusEnum++;
	}
	else{
		cactusEnum = 0;
	}
}