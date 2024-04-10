#ifndef BOB_THE_BLOB_IN_GAME_TEXTURES_COMMON_LOADING_H
#define BOB_THE_BLOB_IN_GAME_TEXTURES_COMMON_LOADING_H

#include "advancedDrawing/texturesLoading/fileTexturesList.h"

struct CommonTexturesLoading
{
	TexturesFilesList playerTexturesLoader;
	TexturesFilesList applesTextures;
	sdl2::TextureLoader glassMarbleTexture;
	TexturesFilesList lightBulbAnimation;
	TexturesFilesList magicOrbTextures;
	TexturesFilesList diamondsTextures;
	TexturesFilesList goldIngotTextures;
	TexturesFilesList blueSmokeTextures;
	
	explicit CommonTexturesLoading(AppLogFiles& logs, sdl2::RendererWindow& rndWnd);
	~CommonTexturesLoading() = default;
	CommonTexturesLoading( const CommonTexturesLoading& ) = delete;
	CommonTexturesLoading& operator= ( const CommonTexturesLoading& ) = delete;
	CommonTexturesLoading( CommonTexturesLoading&& ) = default;
	CommonTexturesLoading& operator= ( CommonTexturesLoading&& ) = default;
	
	bool wasLoadingPerfect() const;
};

#endif //BOB_THE_BLOB_IN_GAME_TEXTURES_COMMON_LOADING_H