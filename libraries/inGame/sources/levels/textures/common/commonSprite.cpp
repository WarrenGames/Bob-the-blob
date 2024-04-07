#include "levels/textures/common/commonSprite.h"
#include "levels/textures/common/commonLoading.h"
#include "advancedDrawing/texturesLoading/2dimTexturesLoading.h"
#include "texturing/texturePosition.h"
#include "levels/textures/texturesConsts.h"
#include "consts/screenConsts.h"

CommonTexturesSprites::CommonTexturesSprites(const CommonTexturesLoading& loadedTextures, const Matrix2DTexturesLoading& bobsTextures):
	playerSprites{ loadedTextures.playerTexturesLoader },
	applesSprites{ loadedTextures.applesTextures },
	glassMarbleSprite{ loadedTextures.glassMarbleTexture },
	lightBulbSprites{ loadedTextures.lightBulbAnimation },
	magicOrbSprites{ loadedTextures.magicOrbTextures },
	bobsCanBeEatenIcon{ bobsTextures( 0, textures::BlobColorGreen ) },
	diamondsSprites{ loadedTextures.diamondsTextures },
	goldIngotSprites{ loadedTextures.goldIngotTextures }
{
	bobsCanBeEatenIcon.multiplyBoth(0.5);
	bobsCanBeEatenIcon.setTexturePosition( TexturePosition{ SQR_SIZE / 2, GameScreenHeight - SQR_SIZE / 2, true, true } );
}