#ifndef BOB_THE_BLOB_IN_GAME_MAPPING_TEXTURES_H
#define BOB_THE_BLOB_IN_GAME_MAPPING_TEXTURES_H

#include "advancedDrawing/texturesLoading/fileTexturesList.h"
#include "fileSystem/fileSystem.h"

struct AppLogFiles;
namespace sdl2{ class RendererWindow; }

class MappingTextures
{
private:
	std::vector< TexturesFilesList > textures;
	bool isLoadingPerfect;

public:
	explicit MappingTextures(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const fs::path& texturesListFile);
	~MappingTextures() = default;
	MappingTextures( const MappingTextures& ) = delete;
	MappingTextures& operator= ( const MappingTextures& ) = delete;
	MappingTextures( MappingTextures&& ) = default;
	MappingTextures& operator= ( MappingTextures&& ) = default;
	
	bool wasLoadingPerfect() const;
	
	std::vector< TexturesFilesList >::const_iterator begin() const;
	std::vector< TexturesFilesList >::const_iterator end() const;
	
private:
	void openMainFile(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const fs::path& texturesListFile);
};

#endif //BOB_THE_BLOB_IN_GAME_MAPPING_TEXTURES_H