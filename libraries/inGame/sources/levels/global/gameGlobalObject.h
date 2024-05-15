#ifndef BOB_THE_BLOB_IN_GAME_GAME_GLOBAL_OBJECT_H
#define BOB_THE_BLOB_IN_GAME_GAME_GLOBAL_OBJECT_H

#include "levels/global/levelMandatoryData.h"
#include "levels/textures/standardLevel/texturesLoader.h"
#include "levels/textures/standardLevel/texturesSprites.h"
#include "levels/textures/balloons/balloonsPack.h"
#include "levels/textures/infosPanel/stdLevelInfosPanel.h"
#include "fileSystem/fileSystem.h"

namespace sdl2{ class RendererWindow; }
struct PlayerAttributes;
struct Essentials;
struct GameConfigData;

struct GameGlobalObject
{
	LevelMandatoryData levelData;
	StandardLevelTexturesLoader texturesLoader;
	StandardLevelSprites texturesSprites;
	BalloonsPack balloonsPack;
	StdLevelInfosPanel infosPanel;
	
	explicit GameGlobalObject(Essentials& essentials, PlayerAttributes& playerAttributes, const fs::path& levelPrefix, demos::DataPackage* demoDataPackage,
								const GameConfigData& gameConfigData);
	~GameGlobalObject() = default;
	GameGlobalObject( const GameGlobalObject& ) = delete;
	GameGlobalObject& operator= ( const GameGlobalObject& ) = delete;
	GameGlobalObject( GameGlobalObject&& ) = default;
	GameGlobalObject& operator= ( GameGlobalObject&& ) = default;
	
	bool wasLoadingPerfect() const;
	void drawLevel(sdl2::RendererWindow& rndWnd);
	void updateGame(Essentials& essentials, PlayerAttributes& playerAttributes, demos::DataPackage* demoDataPackage);
	bool hasPlayerRequestedToExit() const;
	
	bool isLevelComplete() const;
};

#endif //BOB_THE_BLOB_IN_GAME_GAME_GLOBAL_OBJECT_H