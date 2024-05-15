#ifndef BOB_THE_BLOB_DEMOS_LIB_ITEM_DATA_H
#define BOB_THE_BLOB_DEMOS_LIB_ITEM_DATA_H

#include "matrices/matrixStructs.h"
#include <chrono>

namespace demos{

struct ItemData
{
	std::chrono::duration<long double, std::micro> delay;
	Coord2D position;
	unsigned event;
	unsigned itemId;
	
	ItemData();
	ItemData(const std::chrono::duration<long double, std::micro>& newDelay, const Coord2D& newPosition, unsigned eventType, unsigned idNumber);
	~ItemData() = default;
	ItemData( const ItemData& ) = default;
	ItemData& operator= ( const ItemData& ) = default;
};

}

#endif //BOB_THE_BLOB_DEMOS_LIB_ITEM_DATA_H