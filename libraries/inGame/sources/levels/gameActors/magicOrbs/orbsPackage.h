#ifndef BOB_THE_BLOB_IN_GAME_ORBS_PACKAGE_H
#define BOB_THE_BLOB_IN_GAME_ORBS_PACKAGE_H

#include "levels/gameActors/magicOrbs/singleOrb.h"
#include "time/accurateTime.h"
#include "fileSystem/fileSystem.h"
#include <vector>
#include <optional>

struct GameMap;
namespace demos{ struct DataPackage; template<typename T>class Stack; struct ItemData; }
class SoundPlayer;

class OrbsPackage
{
private:
	std::vector< SingleOrb > orbs;
	AccurateTimeDelay creationDelayMeasure;
	std::chrono::milliseconds orbDurationDelay;
	std::chrono::milliseconds orbCreationDelay;
	std::size_t orbColorIndex;
	int orbWorth;
	unsigned orbsIdentityNumber;
	bool isLoadingPerfect;

public:
	explicit OrbsPackage(std::size_t orbColor, int orbWorthValue, std::chrono::milliseconds creationDelay, std::chrono::milliseconds durationDelay);
	~OrbsPackage() = default;
	OrbsPackage( const OrbsPackage& ) = delete;
	OrbsPackage& operator= ( const OrbsPackage& ) = delete;
	OrbsPackage( OrbsPackage&& ) = default;
	OrbsPackage& operator= ( OrbsPackage&& ) = default;
	
	void createOrbs(const Coord2D& newCoordinates, const GameMap& gameMap, std::optional<demos::DataPackage>& demoDataPackage, const SoundPlayer& soundPlayer);
	std::vector< SingleOrb >::const_iterator begin() const;
	std::vector< SingleOrb >::const_iterator end() const;
	std::vector< SingleOrb >::iterator begin();
	std::vector< SingleOrb >::iterator end();
	std::size_t getColorIndex() const;
	int getOrbScoreValue() const;
	unsigned getCurrentIdentityNumber() const;
	void createWithDemo(demos::Stack< demos::ItemData >& orbsStack);
	void destroyWithDemo(demos::Stack< demos::ItemData >& orbsStack);
	void abortOrbsIfAny();
	void findAndDestroyAccordingToPlayerCoordinates(const Coord2D& playerCoordinates);
	
private:
	void findPlaceAndCreate(const Coord2D& newCoordinates, unsigned idNumber);
	void createNewOrbIfTimeHasElapsed(const Coord2D& newCoordinates, const GameMap& gameMap, const SoundPlayer& soundPlayer);
	void incrementIdentityNumber();
};

#endif //BOB_THE_BLOB_IN_GAME_ORBS_PACKAGE_H