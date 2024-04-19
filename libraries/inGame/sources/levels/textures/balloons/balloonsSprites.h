#ifndef BOB_THE_BLOB_IN_GAME_BALLOONS_THINGS_SPRITES_H
#define BOB_THE_BLOB_IN_GAME_BALLOONS_THINGS_SPRITES_H

#include "advancedDrawing/texturesDrawing/constAnimationDrawing.h"

struct BalloonsTexturesLoader;

struct BalloonsSprites
{
	ConstAnimDraw balloonsSprites;
	ConstAnimDraw enemyLogos;
	ConstAnimDraw orbsLogos;
	sdl2::Sprite hammerLogo;
	
	explicit BalloonsSprites(const BalloonsTexturesLoader& loadedTextures);
	~BalloonsSprites() = default;
	BalloonsSprites( const BalloonsSprites& ) = delete;
	BalloonsSprites& operator= ( const BalloonsSprites& ) = delete;
	BalloonsSprites( BalloonsSprites&& ) = default;
	BalloonsSprites& operator= ( BalloonsSprites&& ) = default;
};

#endif //BOB_THE_BLOB_IN_GAME_BALLOONS_THINGS_SPRITES_H