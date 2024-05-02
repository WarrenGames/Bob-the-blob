#ifndef BOB_THE_BLOB_IN_GAME_MAPS_DATA_H
#define BOB_THE_BLOB_IN_GAME_MAPS_DATA_H

#include "levels/maps/mapElements.h"
#include "matrices/matrix2D.h"
#include "fileSystem/fileSystem.h"

struct AppLogFiles;

struct GameMap
{
	MatrixTemp2D< MapElement > matrix;
	
	explicit GameMap(AppLogFiles& logs, const fs::path& mapFilePath, bool& isLoadingPerfect, unsigned demoType);
	~GameMap() = default;
	GameMap( const GameMap& ) = delete;
	GameMap& operator= ( const GameMap& ) = delete;
	GameMap( GameMap&& ) = default;
	GameMap& operator= ( GameMap&& ) = default;
};

#endif //BOB_THE_BLOB_IN_GAME_MAPS_DATA_H