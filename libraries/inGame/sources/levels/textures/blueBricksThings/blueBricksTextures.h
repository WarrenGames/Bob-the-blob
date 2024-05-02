#ifndef BOB_THE_BLOB_IN_GAME_BLUE_BRICKS_SPECIFIC_TEXTURES_LOADER_H
#define BOB_THE_BLOB_IN_GAME_BLUE_BRICKS_SPECIFIC_TEXTURES_LOADER_H

#include "advancedDrawing/texturesLoading/fileTexturesList.h"

struct AppLogFiles;
namespace sdl2{ class RendererWindow; }

struct BlueBricksTexturesLoader
{
	TexturesFilesList hammerTextures;
	TexturesFilesList sparksTextures;
	
	explicit BlueBricksTexturesLoader(AppLogFiles& logs, sdl2::RendererWindow& rndWnd);
	~BlueBricksTexturesLoader() = default;
	BlueBricksTexturesLoader( const BlueBricksTexturesLoader& ) = delete;
	BlueBricksTexturesLoader& operator= ( const BlueBricksTexturesLoader& ) = delete;
	BlueBricksTexturesLoader( BlueBricksTexturesLoader&& ) = default;
	BlueBricksTexturesLoader& operator= ( BlueBricksTexturesLoader&& ) = default;
	
	bool wasLoadingPerfect() const;
};

#endif //BOB_THE_BLOB_IN_GAME_BLUE_BRICKS_SPECIFIC_TEXTURES_LOADER_H
