#include "levels/mapSubDivisions/subDivFileData.h"
#include "exceptions/readErrorExcept.h"
#include <algorithm>

SubDivisionFileData::SubDivisionFileData():
	zonesNumber{ 0, 0 },
	isLoadingPerfect{ true }
{
	
}

/*
SubDivisionFileData::SubDivisionFileData(const fs::path& subDivFilePath):
	isLoadingPerfect{ true }
{
	//loadLevelSubdivision(*this, subDivFilePath);
}
*/

void SubDivisionFileData::loadLinkData(const std::pair< Coord2D, Coord2D >& newLinks, std::size_t fileLineNumber, const fs::path& dataFilePath)
{
	if( newLinks.first.width < zonesNumber.width && newLinks.first.height < zonesNumber.height 
		&& newLinks.second.width < zonesNumber.width && newLinks.second.height < zonesNumber.height )
	{
		subdivisionLinks.emplace_back( newLinks );
	}
	else{
		isLoadingPerfect = false;
		throw ReadError{"Error: bad map subdivision links value at line number: " + std::to_string(fileLineNumber) + " in '" + dataFilePath.string() + "' file .\n"};
	}
}

std::vector< std::pair< Coord2D, Coord2D > >::const_iterator SubDivisionFileData::getMatchingCoord(const Coord2D& coord) const
{
	return std::find_if( std::cbegin( subdivisionLinks ), std::cend( subdivisionLinks ), [&coord](auto const& pair)
		{ return coords::are2DCoordsTheSame(coord, pair.first); } );
}