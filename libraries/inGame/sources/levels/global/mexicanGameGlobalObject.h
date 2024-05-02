#ifndef BOB_THE_BLOB_MEXICAN_IN_GAME_GAME_GLOBAL_OBJECT_H
#define BOB_THE_BLOB_MEXICAN_IN_GAME_GAME_GLOBAL_OBJECT_H

#include "levels/global/levelMandatoryData.h"
#include "levels/gameActors/cactus/cactiPackage.h"
#include "levels/gameActors/magicOrbs/orbsPackage.h"
#include "levels/textures/mexicanThings/mexicanTextureLoader.h"
#include "levels/textures/mexicanThings/mexicanSprites.h"
#include "levels/textures/balloons/balloonsPack.h"
#include "levels/textures/infosPanel/mexicanInfosPanel.h"
#include "fileSystem/fileSystem.h"

struct Essentials;
struct PlayerAttributes;
namespace sdl2{ class RendererWindow; }
namespace demos{ struct DataPackage; }

struct MexicanGameObject
{
	LevelMandatoryData levelData;
	CactiPackage cactiPackage;
	OrbsPackage greenOrbs;
	MexicanSpecificTexturesLoader mexicanTextures;
	MexicanSpecificSprites mexicanSprites;
	BalloonsPack balloonsPack;
	MexicanInfosPanel mexicanInfosPanel;
	
	explicit MexicanGameObject(Essentials& essentials, PlayerAttributes& playerAttributes, const fs::path& levelPrefix, demos::DataPackage* demoDataPackage);
	~MexicanGameObject() = default;
	MexicanGameObject( const MexicanGameObject& ) = delete;
	MexicanGameObject& operator= ( const MexicanGameObject& ) = delete;
	MexicanGameObject( MexicanGameObject&& ) = default;
	MexicanGameObject& operator= ( MexicanGameObject&& ) = default;
	
	bool wasLoadingPerfect() const;
	void drawLevel(sdl2::RendererWindow& rndWnd);
	void updateGame(Essentials& essentials, PlayerAttributes& playerAttributes, demos::DataPackage* demoDataPackage);
	
	void updateGreenOrbs(PlayerAttributes& playerAttributes, demos::DataPackage* demoDataPackage);
	
	bool hasPlayerRequestedToExit() const;
	
	void loadCactiPositions(const demos::DataPackage* demoDataPackage);
	void recordCactiPositions(demos::DataPackage* demoDataPackage) const;
	
	bool isLevelComplete() const;
};

#endif //BOB_THE_BLOB_MEXICAN_IN_GAME_GAME_GLOBAL_OBJECT_H