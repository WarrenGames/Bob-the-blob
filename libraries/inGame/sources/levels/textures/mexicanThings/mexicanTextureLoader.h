#ifndef BOB_THE_BLOB_IN_GAME_MEXICAN_TEXTURES_LOADER_H
#define BOB_THE_BLOB_IN_GAME_MEXICAN_TEXTURES_LOADER_H

#include "levels/textures/mappingTextures/mappingTextures.h"
#include "levels/textures/common/commonLoading.h"
#include "advancedDrawing/texturesLoading/2dimTexturesLoading.h"

struct AppLogFiles;
namespace sdl2{ class RendererWindow; }

struct MexicanSpecificTexturesLoader
{
	CommonTexturesLoading commonTextures;
	Matrix2DTexturesLoading mexicanBobTexturesLoader;
	MappingTextures mapTextures;
	sdl2::TextureLoader bobHat;
	TexturesFilesList cactiTextures;
	
	explicit MexicanSpecificTexturesLoader(AppLogFiles& logs, sdl2::RendererWindow& rndWnd);
	~MexicanSpecificTexturesLoader() = default;
	MexicanSpecificTexturesLoader( const MexicanSpecificTexturesLoader& ) = delete;
	MexicanSpecificTexturesLoader& operator= ( const MexicanSpecificTexturesLoader& ) = delete;
	MexicanSpecificTexturesLoader( MexicanSpecificTexturesLoader&& ) = default;
	MexicanSpecificTexturesLoader& operator= ( MexicanSpecificTexturesLoader&& ) = default;
	
	bool wasLoadingPerfect() const;
	
};

#endif //BOB_THE_BLOB_IN_GAME_MEXICAN_TEXTURES_LOADER_H