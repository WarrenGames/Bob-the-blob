#ifndef BOB_THE_BLOB_IN_GAME_TEXTURES_LOADER_H
#define BOB_THE_BLOB_IN_GAME_TEXTURES_LOADER_H

#include "levels/textures/common/commonLoading.h"
#include "advancedDrawing/texturesLoading/2dimTexturesLoading.h"
#include "levels/textures/mappingTextures/mappingTextures.h"

struct AppLogFiles;
namespace sdl2{ class RendererWindow; }

struct StandardLevelTexturesLoader
{
	CommonTexturesLoading commonTextures;
	Matrix2DTexturesLoading blobTexturesLoader;
	MappingTextures mapTextures;
	
	explicit StandardLevelTexturesLoader(AppLogFiles& logs, sdl2::RendererWindow& rndWnd);
	~StandardLevelTexturesLoader() = default;
	StandardLevelTexturesLoader( const StandardLevelTexturesLoader& ) = delete;
	StandardLevelTexturesLoader& operator= ( const StandardLevelTexturesLoader& ) = delete;
	StandardLevelTexturesLoader( StandardLevelTexturesLoader&& ) = default;
	StandardLevelTexturesLoader& operator= ( StandardLevelTexturesLoader&& ) = default;
	
	bool wasLoadingPerfect() const;
};

#endif //BOB_THE_BLOB_IN_GAME_TEXTURES_LOADER_H