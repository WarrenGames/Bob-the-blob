#include "levels/textures/blueBricksThings/blueBricksTextures.h"
#include "levels/textures/texturesConsts.h"

BlueBricksTexturesLoader::BlueBricksTexturesLoader(AppLogFiles& logs, sdl2::RendererWindow& rndWnd):
	hammerTextures{ logs, rndWnd, textures::HammerTexturesFilePath },
	sparksTextures{ logs, rndWnd, textures::SparksTexturesFilePath }
{
	
}

bool BlueBricksTexturesLoader::wasLoadingPerfect() const
{
	return hammerTextures.wasLoadingPerfect()
		&& sparksTextures.wasLoadingPerfect();
}