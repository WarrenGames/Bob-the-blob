#ifndef BOB_THE_BLOB_IN_GAME_BOBS_PACKAGE_H
#define BOB_THE_BLOB_IN_GAME_BOBS_PACKAGE_H

#include "levels/gameActors/playerThings/characterAbility.h"
#include "levels/gameActors/bobThings/globalBob.h"
#include "fileSystem/fileSystem.h"
#include <vector>
#include <memory>

struct GameConfigData;
struct Essentials;
struct PlayerAttributes;
struct CrossRoadsRandoms;
struct SinglePlayerData;
class Ability;
class PlayerMoving;
namespace demos{ struct DataPackage; }

class BobsPackage
{
private:
	std::vector< std::unique_ptr< GlobalBob > > bobs;
	AccurateTimeDelay moveTime;
	AccurateTimeDelay spawnTime;
	std::chrono::microseconds bobsMoveDelay;
	std::chrono::milliseconds bobsAnimDelay;
	std::chrono::milliseconds bobsSpawnDelay;
	
public:
	explicit BobsPackage(const fs::path& bobsDataFilePath, unsigned demoType, unsigned skillLevel, const GameConfigData& gameConfigData);
	~BobsPackage() = default;
	BobsPackage( const BobsPackage& ) = delete;
	BobsPackage& operator= ( const BobsPackage& ) = delete;
	BobsPackage( BobsPackage&& ) = default;
	BobsPackage& operator= ( BobsPackage&& ) = default;
	
	std::vector< std::unique_ptr< GlobalBob > >::iterator begin();
	std::vector< std::unique_ptr< GlobalBob > >::iterator end();
	
	std::vector< std::unique_ptr< GlobalBob > >::const_iterator begin() const;
	std::vector< std::unique_ptr< GlobalBob > >::const_iterator end() const;
	
	std::size_t size() const;
	std::size_t getActiveBobsCount() const;
	const GlobalBob& getElement(std::size_t index) const;
	GlobalBob& getElement(std::size_t index);
	
	void emplaceBackBob(const Coord2D& startingPos, std::size_t colorEnum);
	
	void animatePackage();
	void movePackage();
	void changeDirectionIfAny(CrossRoadsRandoms& crossRoads, const GameMap& gameMap, const PlayerMoving& playerMoving);
	void loadBobsMoveDelay(Essentials& essentials);
	void detectCollisionWithPlayer(SinglePlayerData& player, PlayerAttributes& playerAttributes, const Ability& canEatBobs, demos::DataPackage *demoDataPackage);
	void recordBobRelatedGameEvent(demos::DataPackage *demoDataPackage, unsigned eventCategory, unsigned eventSubType, std::size_t newId) const;
	void resetAllBobsPositions();
	void makeBobsNotSeekingPlayer();
	void disableAllBobs();
	
	void initFirstDirection(const CrossRoadsRandoms& crossRoads);
	
	void spawnBobIfAny(const PlayerMoving& playerMove, demos::DataPackage *demoDataPackage);
	void spawnSingleBob(GlobalBob& globalBob);
	void spawnBobWithDemoStack(demos::DataPackage *demoDataPackage);
	
	void updateExplosionIfAny(std::size_t totalFrameNumber);
};

#endif //BOB_THE_BLOB_IN_GAME_BOBS_PACKAGE_H