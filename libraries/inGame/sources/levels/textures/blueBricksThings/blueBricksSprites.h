#ifndef BOB_THE_BLOB_IN_GAME_BLUE_BRICKS_SPRITES_H
#define BOB_THE_BLOB_IN_GAME_BLUE_BRICKS_SPRITES_H

#include "advancedDrawing/texturesDrawing/constAnimationDrawing.h"

struct BlueBricksTexturesLoader;

struct BlueBricksSprites
{
	ConstAnimDraw hammerSprites;
	ConstAnimDraw sparksSprites;
	
	explicit BlueBricksSprites(const BlueBricksTexturesLoader& blueBricksTexturesLoading);
	~BlueBricksSprites() = default;
	BlueBricksSprites( const BlueBricksSprites& ) = delete;
	BlueBricksSprites& operator= ( const BlueBricksSprites& ) = delete;
	BlueBricksSprites( BlueBricksSprites&& ) = default;
	BlueBricksSprites& operator= ( BlueBricksSprites&& ) = default;
	
};

#endif //BOB_THE_BLOB_IN_GAME_BLUE_BRICKS_SPRITES_H