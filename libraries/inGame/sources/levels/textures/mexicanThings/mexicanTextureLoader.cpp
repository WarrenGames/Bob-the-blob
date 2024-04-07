#include "levels/textures/mexicanThings/mexicanTextureLoader.h"
#include "levels/textures/texturesConsts.h"
#include "levels/textures/mexicanTexturesConsts.h"

MexicanSpecificTexturesLoader::MexicanSpecificTexturesLoader(AppLogFiles& logs, sdl2::RendererWindow& rndWnd):
	commonTextures{ logs, rndWnd },
	mexicanBobTexturesLoader{ logs, rndWnd, Coord2D{ textures::BlobFramesNumber, textures::BlobColorMax }, textures::mexican::BobMexicanTexturesListFile },
	mapTextures{ logs, rndWnd, textures::mexican::MexicanMapTexturesListFile },
	bobHat{ logs, rndWnd, textures::mexican::BobHatTexturePath },
	cactiTextures{ logs, rndWnd, textures::mexican::CactiTexturesFilePath }
{
	
}

bool MexicanSpecificTexturesLoader::wasLoadingPerfect() const
{
	return commonTextures.wasLoadingPerfect()
		&& mexicanBobTexturesLoader.wasLoadingPerfect() 
		&& mapTextures.wasLoadingPerfect()
		&& bobHat.wasLoadingPerfect()
		&& cactiTextures.wasLoadingPerfect();
}