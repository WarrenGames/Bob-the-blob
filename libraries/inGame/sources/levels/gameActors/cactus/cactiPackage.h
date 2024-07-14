#ifndef BOB_THE_BLOB_IN_GAME_CACTUS_PACKAGE_H
#define BOB_THE_BLOB_IN_GAME_CACTUS_PACKAGE_H

#include "levels/gameActors/cactus/cactusObstacle.h"
#include <vector>

struct Coord2D;
struct SinglePlayerData;
struct PlayerAttributes;
class BobsPackage;

class CactiPackage
{
private:
	std::vector< CactusObstacle > cacti;

public:
	CactiPackage() = default;
	~CactiPackage() = default;
	CactiPackage( const CactiPackage& ) = delete;
	CactiPackage& operator= ( const CactiPackage& ) = delete;
	CactiPackage( CactiPackage&& ) = default;
	CactiPackage& operator= ( CactiPackage&& ) = default;
	
	std::vector< CactusObstacle >::iterator begin();
	std::vector< CactusObstacle >::iterator end();
	std::vector< CactusObstacle >::const_iterator begin() const;
	std::vector< CactusObstacle >::const_iterator end() const;
	
	unsigned getEffectiveCactiNumber() const;
	
	void addCactus(const Coord2D& coordinates, std::size_t textureIndex, unsigned itemId);
	void detectCollisionWithPlayer(SinglePlayerData& player, PlayerAttributes& playerAttributes, BobsPackage& bobsPackage);
};

#endif //BOB_THE_BLOB_IN_GAME_CACTUS_PACKAGE_H