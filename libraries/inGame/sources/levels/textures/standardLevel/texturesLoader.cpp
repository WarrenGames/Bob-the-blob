#include "levels/textures/standardLevel/texturesLoader.h"
#include "levels/textures/texturesConsts.h"

StandardLevelTexturesLoader::StandardLevelTexturesLoader(AppLogFiles& logs, sdl2::RendererWindow& rndWnd):
	commonTextures{ logs, rndWnd },
	blobTexturesLoader{ logs, rndWnd, Coord2D{ textures::BlobFramesNumber, textures::BlobColorMax }, textures::BlobTexturesFilePath },
	mapTextures{ logs, rndWnd, textures::WallsTexturesFilePath }
{
	
}

bool StandardLevelTexturesLoader::wasLoadingPerfect() const
{
	return commonTextures.wasLoadingPerfect()
		&& blobTexturesLoader.wasLoadingPerfect() 
		&& mapTextures.wasLoadingPerfect();
}