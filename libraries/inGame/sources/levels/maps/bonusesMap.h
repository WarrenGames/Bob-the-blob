#ifndef BOB_THE_BLOB_IN_GAME_BONUSES_MAP_H
#define BOB_THE_BLOB_IN_GAME_BONUSES_MAP_H

#include "levels/maps/bonusElement.h"
#include "levels/maps/bonusesAnimation.h"
#include "matrices/matrix2D.h"
#include "fileSystem/fileSystem.h"

struct GameMap;
struct CommonTexturesSprites;

class BonusesMap
{
private:
	MatrixTemp2D< BonusElement > map;
	std::vector< unsigned > elementsCount;
	std::vector< BonusesAnimationData > animData;

public:
	explicit BonusesMap(const GameMap& gameMap, const fs::path& levelPrefix, unsigned demoType);
	~BonusesMap() = default;
	BonusesMap( const BonusesMap& ) = delete;
	BonusesMap& operator= ( const BonusesMap& ) = delete;
	BonusesMap( BonusesMap&& ) = default;
	BonusesMap& operator= ( BonusesMap&& ) = default;
	
	void setParameterMap(MatrixTemp2D< BonusElement >& newMap) const;
	void copyMapFromDemoData(const MatrixTemp2D< BonusElement >& newMap);
	
	void createGlassMarblesInsideMap(const GameMap& gameMap);
	void countSpecificItemNumber(std::size_t itemId);
	void countAllBonuses();
	
	const BonusElement& getElement(const Coord2D& coordinates) const;
	BonusElement& getElement(const Coord2D& coordinates);
	bool areCoordinatesInsideBoundaries(int width, int height) const;
	bool areCoordinatesInsideBoundaries(const Coord2D& coordinates) const;
	
	void decrementElementNumberCount(std::size_t index);
	unsigned getElementNumber(std::size_t index) const;
	
	void incrementBonusesAnimIndex();

	void createAnimData(const CommonTexturesSprites& sprites);
	std::size_t getAnimIndex(std::size_t index) const;
};

#endif //BOB_THE_BLOB_IN_GAME_BONUSES_MAP_H