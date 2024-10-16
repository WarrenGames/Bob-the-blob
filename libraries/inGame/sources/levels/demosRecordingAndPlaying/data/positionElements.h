#ifndef BOB_THE_BLOB_DEMOS_LIB_RECORDED_SPRITES_POSITIONS_H
#define BOB_THE_BLOB_DEMOS_LIB_RECORDED_SPRITES_POSITIONS_H

#include "levels/demosRecordingAndPlaying/dataToRecord/moveAndPosition.h"
#include "levels/demosRecordingAndPlaying/dataToRecord/startingPositions.h"
#include "levels/demosRecordingAndPlaying/dataToRecord/playerMove.h"
#include "levels/demosRecordingAndPlaying/dataToRecord/gameEvents.h"
#include "levels/demosRecordingAndPlaying/templates/demoStack.h"

struct Essentials;
struct SinglePlayerData;
class BobsPackage;
class CactiPackage;

namespace demos{

struct SpritesPositions
{
	std::vector< demos::StartingPosition > protagonistsStartingPosition;
	std::vector< demos::StartingPosition > itemsStartingPosition;//Cacti for example, if any
	std::vector< demos::Stack< demos::PlayerMove > > playersMoves;
	std::vector< demos::Stack< demos::MoveAndPosition > > enemyBobsMoves;
	demos::Stack< demos::GameEvent > enemyBobsRespawn;
	
	explicit SpritesPositions(Essentials& essentials, unsigned demoType_);
	~SpritesPositions() = default;
	SpritesPositions( const SpritesPositions& ) = delete;
	SpritesPositions& operator= ( const SpritesPositions& ) = delete;
	SpritesPositions( SpritesPositions&& ) = default;
	SpritesPositions& operator= ( SpritesPositions&& ) = default;
	
	void joinAllTimePoints(const AccurateTimeDelay& newDelay);
	void joinPlayersTimePoints(const AccurateTimeDelay& newDelay);
	void joinBobbyMovesTimePoints(const AccurateTimeDelay& newDelay);
	void addBobMoveStack(Essentials& essentials, unsigned demoType);//Add a move data stack according to the number of enemies in the level (in recording mode)
	
	//At start recording to save to a demo file later (from game data to stacks or equivalent)
	void recordPlayerStartingPosition(const SinglePlayerData& singlePlayerData, unsigned demoType);
	void recordProtagonistsStartingPosition(const BobsPackage& bobsPackage, unsigned demoType);
	void recordCactiStartingPositions(const CactiPackage& cactiPackage);
	void recordBobRespawnEvent(std::size_t bobId, unsigned demoType);
	
	//At start initialization of game for a demo (from stacks to game data)
	void setBobbysLevelDataFromDemoData(BobsPackage& bobsPackage, unsigned demoType) const;
	void setPlayerLevelDataFromDemoData(SinglePlayerData& singlePlayerData, unsigned demoType) const;
	void setCactiStartingPositions(CactiPackage& cactiPackage) const;
	
	//Just before level starts
	void recordBobbysNumber(Essentials& essentials, std::size_t bobbysNumber, unsigned demoType);
	void recordPlayersNumber(Essentials& essentials, std::size_t playersNumber, unsigned demoType);
};
	
}

#endif //BOB_THE_BLOB_DEMOS_LIB_RECORDED_SPRITES_POSITIONS_H