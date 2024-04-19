#ifndef BOB_THE_BLOB_IN_GAME_BALLOONS_THINGS_TEXTURES_LOADER_H
#define BOB_THE_BLOB_IN_GAME_BALLOONS_THINGS_TEXTURES_LOADER_H

#include "advancedDrawing/texturesLoading/fileTexturesList.h"

struct AppLogFiles;
namespace sdl2{ class RendererWindow; }

struct BalloonsTexturesLoader
{
	TexturesFilesList balloonsTextures;
	TexturesFilesList enemyLogos;
	TexturesFilesList orbsLogos;
	sdl2::TextureLoader hammerLogo;
	
	explicit BalloonsTexturesLoader(AppLogFiles& logs, sdl2::RendererWindow& rndWnd);
	~BalloonsTexturesLoader() = default;
	BalloonsTexturesLoader( const BalloonsTexturesLoader& ) = delete;
	BalloonsTexturesLoader& operator= ( const BalloonsTexturesLoader& ) = delete;
	BalloonsTexturesLoader( BalloonsTexturesLoader&& ) = default;
	BalloonsTexturesLoader& operator= ( BalloonsTexturesLoader&& ) = default;
	
	bool wasLoadingPerfect() const;
};

#endif //BOB_THE_BLOB_IN_GAME_BALLOONS_THINGS_TEXTURES_LOADER_H