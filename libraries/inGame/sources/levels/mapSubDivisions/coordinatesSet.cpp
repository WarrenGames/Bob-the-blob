#include "levels/mapSubDivisions/coordinatesSet.h"
#include <random>
#include <algorithm>
#include <cassert>

CoordinatesSet::CoordinatesSet():
	index{ 0 }
{
	
}

void CoordinatesSet::incrementIndex()
{
	if( index + 1 < coordsSet.size() )
	{
		index++;
	}
	else{
		index = 0;
	}
}

const Coord2D& CoordinatesSet::getCoords() const
{
	assert( index < coordsSet.size() );
	return coordsSet[index];
}

void CoordinatesSet::addElement(const Coord2D& newCoord)
{
	coordsSet.emplace_back( newCoord );
}

void CoordinatesSet::meltCoordinates()
{
	std::random_device randomDevice;
	std::mt19937 generator{ randomDevice() };
	
	std::shuffle( std::begin( coordsSet ), std::end( coordsSet ), generator );
}

std::size_t CoordinatesSet::size() const
{
	return coordsSet.size();
}