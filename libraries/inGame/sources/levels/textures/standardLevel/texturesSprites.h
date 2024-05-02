#ifndef BOB_THE_BLOB_IN_GAME_TEXTURES_SPRITES_H
#define BOB_THE_BLOB_IN_GAME_TEXTURES_SPRITES_H

#include "levels/textures/common/commonSprite.h"
#include "advancedDrawing/texturesDrawing/2dimTexturesDrawing.h"
#include "levels/textures/mappingTextures/mappingSprites.h"
#include "levels/textures/blueBricksThings/blueBricksSprites.h"

struct StandardLevelTexturesLoader;

struct StandardLevelSprites
{
	CommonTexturesSprites commonSprites;
	Matrix2DTexturesDrawing blobSprites;
	MappingSprites mapSprites;
	BlueBricksSprites blueBricksSprites;
	
	explicit StandardLevelSprites(const StandardLevelTexturesLoader& textures);
	~StandardLevelSprites() = default;
	StandardLevelSprites( const StandardLevelSprites& ) = delete;
	StandardLevelSprites& operator= ( const StandardLevelSprites& ) = delete;
	StandardLevelSprites( StandardLevelSprites&& ) = default;
	StandardLevelSprites& operator= ( StandardLevelSprites&& ) = default;
};

#endif //BOB_THE_BLOB_IN_GAME_TEXTURES_SPRITES_H