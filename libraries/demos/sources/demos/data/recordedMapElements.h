#ifndef BOB_THE_BLOB_DEMOS_LIB_RECORDED_MAP_ELEMENTS_H
#define BOB_THE_BLOB_DEMOS_LIB_RECORDED_MAP_ELEMENTS_H

#include "levels/maps/bonusElement.h"
#include "levels/maps/mapElements.h"
#include "levels/mapSubDivisions/subDivFileData.h"
#include "matrices/matrix2D.h"

class BonusesMap;

namespace demos{

struct MapElements
{
	MatrixTemp2D< MapElement > gameMap;
	MatrixTemp2D< BonusElement > bonusesMap;
	SubDivisionFileData subDivisionFileData;
	
	MapElements() = default;
	~MapElements() = default;
	MapElements( const MapElements& ) = delete;
	MapElements& operator= ( const MapElements& ) = delete;
	MapElements( MapElements&& ) = default;
	MapElements& operator= ( MapElements&& ) = default;
	
	//At start recording to save to a demo file later
	void recordPlayedMatrix(const MatrixTemp2D< MapElement >& newMatrix, unsigned demoType);
	void recordBonusesMap(const BonusesMap& loadedBonusesMap, unsigned demoType);
	void recordSubDivisionMapData(const SubDivisionFileData& loadedSubDivisionFileData, unsigned demoType);
	
	//At start initialization of game for a demo
	void setLevelMatrix(MatrixTemp2D< MapElement >& levelMatrix, unsigned demoType) const;
	void setBonusesMap(BonusesMap& bonusesMap, unsigned demoType) const;
	void setSubDivisionMapData(SubDivisionFileData& toLoadSubDivisionFileData, unsigned demoType) const;
};
	
}

#endif //BOB_THE_BLOB_DEMOS_LIB_RECORDED_MAP_ELEMENTS_H