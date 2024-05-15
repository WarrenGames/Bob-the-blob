#include "levels/demosRecordingAndPlaying/data/recordedMapElements.h"
#include "levels/maps/bonusesMap.h"
#include "levels/demosRecordingAndPlaying/consts/demosConsts.h"

void demos::MapElements::recordPlayedMatrix(const MatrixTemp2D< MapElement >& newMatrix, unsigned demoType)
{
	if( demoType == demos::GameIsRecording )
	{
		gameMap = newMatrix;
	}
}

void demos::MapElements::recordBonusesMap(const BonusesMap& loadedBonusesMap, unsigned demoType)
{
	if( demoType == demos::GameIsRecording )
	{
		loadedBonusesMap.setParameterMap( bonusesMap );
	}
}

void demos::MapElements::setLevelMatrix(MatrixTemp2D< MapElement >& levelMatrix, unsigned demoType) const
{
	if( demoType == demos::GameIsDemo )
	{
		levelMatrix = gameMap;
	}
}

void demos::MapElements::setBonusesMap(BonusesMap& loadedBonusesMap, unsigned demoType) const
{
	if( demoType == demos::GameIsDemo )
	{
		loadedBonusesMap.copyMapFromDemoData(bonusesMap);
	}
}

void demos::MapElements::setSubDivisionMapData(SubDivisionFileData& toLoadSubDivisionFileData, unsigned demoType) const
{
	if( demoType == demos::GameIsDemo )
	{
		toLoadSubDivisionFileData = subDivisionFileData;
	}
}

void demos::MapElements::recordSubDivisionMapData(const SubDivisionFileData& loadedSubDivisionFileData, unsigned demoType)
{
	if( demoType == demos::GameIsRecording )
	{
		subDivisionFileData = loadedSubDivisionFileData;
	}
}
