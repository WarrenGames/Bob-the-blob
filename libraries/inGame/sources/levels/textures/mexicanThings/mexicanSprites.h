#ifndef BOB_THE_BLOB_MEXICAN_IN_GAME_TEXTURES_SPRITES_H
#define BOB_THE_BLOB_MEXICAN_IN_GAME_TEXTURES_SPRITES_H

#include "levels/textures/mappingTextures/mappingSprites.h"
#include "levels/textures/common/commonSprite.h"
#include "advancedDrawing/texturesDrawing/2dimTexturesDrawing.h"

struct MexicanSpecificTexturesLoader;
namespace sdl2{ class RendererWindow; }
struct GameMap;

struct MexicanSpecificSprites
{
	CommonTexturesSprites commonSprites;
	Matrix2DTexturesDrawing bobSprites;
	MappingSprites mapSprites;
	sdl2::Sprite hatSprite;
	ConstAnimDraw cactiSprites;
	sdl2::Sprite cactiCanBeEatenIcon;
	
	explicit MexicanSpecificSprites(const MexicanSpecificTexturesLoader& loadedTextures);
	~MexicanSpecificSprites() = default;
	MexicanSpecificSprites( const MexicanSpecificSprites& ) = delete;
	MexicanSpecificSprites& operator= ( const MexicanSpecificSprites& ) = delete;
	MexicanSpecificSprites( MexicanSpecificSprites&& ) = default;
	MexicanSpecificSprites& operator= ( MexicanSpecificSprites&& ) = default;
	
	void drawWalls(sdl2::RendererWindow& rndWnd, const GameMap& gameMap);
};

#endif //BOB_THE_BLOB_MEXICAN_IN_GAME_TEXTURES_SPRITES_H