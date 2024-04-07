#include "levels/textures/mexicanThings/mexicanSprites.h"
#include "levels/textures/mexicanThings/mexicanTextureLoader.h"
#include "levels/maps/gameMap.h"
#include "texturing/texturePosition.h"
#include "levels/textures/gradients.h"
#include <cassert>

constexpr std::size_t CactiGradientSpriteNumber = 2;

MexicanSpecificSprites::MexicanSpecificSprites(const MexicanSpecificTexturesLoader& loadedTextures):
	commonSprites{ loadedTextures.commonTextures, loadedTextures.mexicanBobTexturesLoader },
	bobSprites{ loadedTextures.mexicanBobTexturesLoader },
	mapSprites{ loadedTextures.mapTextures },
	hatSprite{ loadedTextures.bobHat },
	cactiSprites{ loadedTextures.cactiTextures },
	cactiCanBeEatenIcon{ loadedTextures.cactiTextures[CactiGradientSpriteNumber] }
{
	assert( CactiGradientSpriteNumber < loadedTextures.cactiTextures.size() );
	cactiCanBeEatenIcon.multiplyBoth(0.75);
	cactiCanBeEatenIcon.setTexturePosition( TexturePosition{ RightGradient.x - SQR_SIZE / 2, GameScreenHeight - SQR_SIZE / 2, true, true } );
}
