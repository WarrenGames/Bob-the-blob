#ifndef BOB_THE_BLOB_IN_GAME_MAPS_ELEMENTS_H
#define BOB_THE_BLOB_IN_GAME_MAPS_ELEMENTS_H

#include <cstdlib>

struct MapElement
{
	std::size_t mapIndex;
	std::size_t indexProperty;
	
	explicit MapElement();
	~MapElement() = default;
	MapElement( const MapElement& ) = default;
	MapElement& operator= ( const MapElement& ) = default;
	MapElement( MapElement&& ) = default;
	MapElement& operator= ( MapElement&& ) = default;
};

#endif //BOB_THE_BLOB_IN_GAME_MAPS_ELEMENTS_H