#ifndef BOB_THE_BLOB_IN_GAME_MAP_SUB_DIVISION_MAP_CUT_ZONES_H
#define BOB_THE_BLOB_IN_GAME_MAP_SUB_DIVISION_MAP_CUT_ZONES_H

#include <cstdlib>

struct GameMap;
struct ZonesFences;

void cutSubdivisionIntoAreas(const GameMap& gameMap, ZonesFences& zonesFences);

void browseAreaCoords(const GameMap& gameMap, ZonesFences& zonesFences, std::size_t areaWidth, std::size_t areaHeight);

std::size_t getMapValue(std::size_t areaNum, std::size_t areaTotalNumber, std::size_t axisMapSize);

void setGlobalAreaReferences(ZonesFences& zonesFences);

std::size_t getAreaValue(std::size_t mapIndex, std::size_t axisMapSize, std::size_t areaTotalNumber);

#endif //BOB_THE_BLOB_IN_GAME_MAP_SUB_DIVISION_MAP_CUT_ZONES_H