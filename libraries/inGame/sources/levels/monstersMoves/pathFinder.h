#ifndef BOB_THE_BLOB_IN_GAME_GAME_MONSTERS_MOVES_PATH_FINDER_H
#define BOB_THE_BLOB_IN_GAME_GAME_MONSTERS_MOVES_PATH_FINDER_H

#include "levels/monstersMoves/pathElement.h"
#include "matrices/matrix2D.h"
#include <vector>

struct GameMap;

class PathFinder
{
private:
	std::vector< IdealPathChunk > idealPath;
	std::vector< IdealPathChunk >::iterator currentNextPosition;
	std::vector< IdealPathChunk >::iterator oldPosition;
	int detectionRange;

public:
	explicit PathFinder(int detectionRange_);
	~PathFinder() = default;
	PathFinder( const PathFinder& ) = delete;
	PathFinder& operator= ( const PathFinder& ) = delete;
	PathFinder( PathFinder&& ) = default;
	PathFinder& operator= ( PathFinder&& ) = default;

	std::size_t size() const;
	const IdealPathChunk& operator[](std::size_t index) const;
	IdealPathChunk& operator[](std::size_t index);
	std::vector< IdealPathChunk >::const_iterator begin() const;
	std::vector< IdealPathChunk >::const_iterator end() const;
	const IdealPathChunk& getMostRecentChunk() const;
	const IdealPathChunk& getOldChunk() const;
	IdealPathChunk& getOldChunk();
	
	void updatePathToPlayer(const GameMap& gameMap, const Coord2D& origin, const Coord2D& destination, bool& canSeekPlayer, unsigned& currentDirection);
	void addNewCoordinatesToFollow(const GameMap& gameMap, const Coord2D& newCoordinates);
	void advanceOldPosition();
	void advanceNewCoordPosition();
	void forgetFollowing();
	
private:
	void tryToDetectPresence(const GameMap& gameMap, const Coord2D& origin, const Coord2D& destination, bool& canSeekPlayer, unsigned& currentDirection);
	void setResultingNewDirection(const std::vector< IdealPathChunk >::iterator& oldNextIterator);
	void actWhenFound(bool& canSeekPlayer);
	void advanceGivenPosition(std::vector< IdealPathChunk >::iterator& position);
	void setCurrentNextPositionIterator();
};

#endif //BOB_THE_BLOB_IN_GAME_GAME_MONSTERS_MOVES_PATH_FINDER_H