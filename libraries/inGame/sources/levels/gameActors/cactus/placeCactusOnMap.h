#ifndef BOB_THE_BLOB_IN_GAME_CACTUS_PLACE_CACTUS_ON_MAP_H
#define BOB_THE_BLOB_IN_GAME_CACTUS_PLACE_CACTUS_ON_MAP_H

#include <vector>

struct ZonesFences;
class CactiPackage;
struct Coord2D;

namespace cacti{

void placeCactiInAllZones(unsigned perZoneCactiNumber, ZonesFences& zonesFences, CactiPackage& cactiPackage, const Coord2D& playerStartingPosition);
	
void placeCacti(unsigned perZoneCactiNumber, ZonesFences& zonesFences, CactiPackage& cactiPackage, const Coord2D& playerStartingPosition);

void loopCactusType(std::size_t& cactusEnum);

}

#endif //BOB_THE_BLOB_IN_GAME_CACTUS_PLACE_CACTUS_ON_MAP_H