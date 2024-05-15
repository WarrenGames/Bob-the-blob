#include "levels/maps/bonusesMap.h"
#include "levels/maps/readBonusesPositionsAndProperties.h"
#include "levels/maps/gameMap.h"
#include "levels/textures/common/commonSprite.h"
#include "pathsFunctions/pathsFunctions.h"
#include "levels/maps/mapsConsts.h"
#include "levels/textures/texturesConsts.h"
#include "levels/maps/bonusesConsts.h"
#include "consts/filesAndPaths.h"
#include "levels/demosRecordingAndPlaying/consts/demosConsts.h"
#include <cassert>

BonusesMap::BonusesMap(const GameMap& gameMap, const fs::path& levelPrefix, unsigned demoType):
	map{gameMap.matrix.getCoordSize()},
	elementsCount(bonuses::BonusMax, 0)
{
	if( demoType == demos::GameHasPlayerInputs || demoType == demos::GameIsRecording )
	{
		openBonusesDataFile(*this, path::getGameConfigFilePath(levelPrefix, files::DefaultBonusesFileSuffix), "load bonuses data");
	}
	countAllBonuses();
}

void BonusesMap::setParameterMap(MatrixTemp2D< BonusElement >& newMap) const
{
	newMap = map;
}

void BonusesMap::copyMapFromDemoData(const MatrixTemp2D< BonusElement >& newMap)
{
	map = newMap;
}

void BonusesMap::createGlassMarblesInsideMap(const GameMap& gameMap)
{
	for( std::size_t width{0} ; width < map.width() ; ++width )
	{
		for( std::size_t height{0} ; height < map.height() ; ++height )
		{
			if( gameMap.matrix(width, height).mapIndex == textures::SquareEmpty 
				&& map(width, height).isPresent == false
				&& map(width, height).bonusIndex == bonuses::BonusMax )
			{
				map(width, height).bonusIndex = bonuses::BonusGlassMarble;
				map(width, height).isPresent = true;
			}
		}
	}
}

void BonusesMap::countSpecificItemNumber(std::size_t itemId)
{
	assert( itemId < elementsCount.size() );
	for( auto const &element : map )
	{
		if( element.isPresent && element.bonusIndex == itemId )
		{
			elementsCount[itemId]++;
		}
	}
}

void BonusesMap::countAllBonuses()
{
	for( std::size_t i{0} ; i < bonuses::BonusMax ; ++i )
	{
		countSpecificItemNumber(i);
	}
}

const BonusElement& BonusesMap::getElement(const Coord2D& coordinates) const
{
	return map(coordinates);
}

BonusElement& BonusesMap::getElement(const Coord2D& coordinates)
{
	return map(coordinates);
}

bool BonusesMap::areCoordinatesInsideBoundaries(int width, int height) const
{
	return map.isSignedInsideBoundaries(width, height);
}

bool BonusesMap::areCoordinatesInsideBoundaries(const Coord2D& coordinates) const
{
	return map.isInsideBoundaries(coordinates);
}

void BonusesMap::decrementElementNumberCount(std::size_t index)
{
	assert( index < elementsCount.size() );
	assert( elementsCount[index] > 0 );
	elementsCount[index]--;
}

unsigned BonusesMap::getElementNumber(std::size_t index) const
{
	assert( index < elementsCount.size() );
	return elementsCount[index];
}

void BonusesMap::incrementBonusesAnimIndex()
{
	for( auto &data : animData )
	{
		data.animIndex();
	}
}

void BonusesMap::createAnimData(const CommonTexturesSprites& sprites)
{
	animData.emplace_back( BonusesAnimationData{ 1, 0 } );
	animData.emplace_back( BonusesAnimationData{ 1, 0 } );
	animData.emplace_back( BonusesAnimationData{ sprites.diamondsSprites.size(), textures::DiamondFrameDuration } );
	animData.emplace_back( BonusesAnimationData{ sprites.goldIngotSprites.size(), textures::GoldIngotFrameDuration } );
}

std::size_t BonusesMap::getAnimIndex(std::size_t index) const
{
	assert( index < animData.size() );
	return animData[index].getIndex();
}