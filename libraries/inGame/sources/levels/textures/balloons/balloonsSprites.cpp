#include "levels/textures/balloons/balloonsSprites.h"
#include "levels/textures/balloons/balloonsTexturesLoader.h"

BalloonsSprites::BalloonsSprites(const BalloonsTexturesLoader& loadedTextures):
	balloonsSprites{ loadedTextures.balloonsTextures },
	enemyLogos{ loadedTextures.enemyLogos },
	orbsLogos{ loadedTextures.orbsLogos },
	hammerLogo{ loadedTextures.hammerLogo }
{
	
}
