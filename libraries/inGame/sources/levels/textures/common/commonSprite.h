#ifndef BOB_THE_BLOB_IN_GAME_TEXTURES_COMMON_SPRITE_H
#define BOB_THE_BLOB_IN_GAME_TEXTURES_COMMON_SPRITE_H

#include "advancedDrawing/texturesDrawing/constAnimationDrawing.h"

struct CommonTexturesLoading;
class Matrix2DTexturesLoading;

struct CommonTexturesSprites
{
	ConstAnimDraw playerSprites;
	ConstAnimDraw applesSprites;
	sdl2::Sprite glassMarbleSprite;
	ConstAnimDraw lightBulbSprites;
	ConstAnimDraw magicOrbSprites;
	sdl2::Sprite bobsCanBeEatenIcon;
	ConstAnimDraw diamondsSprites;
	ConstAnimDraw goldIngotSprites;
	ConstAnimDraw blueSmokeSprites;
	
	explicit CommonTexturesSprites(const CommonTexturesLoading& loadedTextures, const Matrix2DTexturesLoading& bobsTextures);
	~CommonTexturesSprites() = default;
	CommonTexturesSprites( const CommonTexturesSprites& ) = delete;
	CommonTexturesSprites& operator= ( const CommonTexturesSprites& ) = delete;
	CommonTexturesSprites( CommonTexturesSprites&& ) = default;
	CommonTexturesSprites& operator= ( CommonTexturesSprites&& ) = default;
};

#endif //BOB_THE_BLOB_IN_GAME_TEXTURES_COMMON_SPRITE_H