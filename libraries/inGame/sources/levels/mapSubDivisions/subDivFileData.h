#ifndef BOB_THE_BLOB_IN_GAME_MAP_SUB_DIV_FILE_DATA_H
#define BOB_THE_BLOB_IN_GAME_MAP_SUB_DIV_FILE_DATA_H

#include "matrices/matrixStructs.h"
#include "fileSystem/fileSystem.h"
#include <utility>
#include <vector>

struct SubDivisionFileData
{
	Coord2D zonesNumber;
	std::vector< std::pair< Coord2D, Coord2D > > subdivisionLinks;//Here 'Coord2D' represents the 'zone' coordinates in 'ZonesSubDiviser' class
	bool isLoadingPerfect;
	
	SubDivisionFileData();
	~SubDivisionFileData() = default;
	SubDivisionFileData( const SubDivisionFileData& ) = default;
	SubDivisionFileData& operator= ( const SubDivisionFileData& ) = default;
	
	void loadLinkData(const std::pair< Coord2D, Coord2D >& newLinks, std::size_t fileLineNumber, const fs::path& dataFilePath);
	
	std::vector< std::pair< Coord2D, Coord2D > >::const_iterator getMatchingCoord(const Coord2D& coord) const;
};

#endif //BOB_THE_BLOB_IN_GAME_MAP_SUB_DIV_FILE_DATA_H