#include "levels/textures/common/commonLoading.h"
#include "levels/textures/texturesConsts.h"

CommonTexturesLoading::CommonTexturesLoading(AppLogFiles& logs, sdl2::RendererWindow& rndWnd):
	playerTexturesLoader{ logs, rndWnd, textures::PlayerTexturesFilePath },
	applesTextures{ logs, rndWnd, textures::ApplesTexturesFilePath },
	glassMarbleTexture{ logs, rndWnd, textures::GlassMarbleTexturePath },
	lightBulbAnimation{ logs, rndWnd, textures::LightBulbTexturesFilePath },
	magicOrbTextures{ logs, rndWnd, textures::MagicOrbTexturesFilePath },
	diamondsTextures{ logs, rndWnd, textures::DiamondsTexturesFilePath },
	goldIngotTextures{ logs, rndWnd, textures::GoldIngotTexturesFilePath },
	blueSmokeTextures{ logs, rndWnd, textures::BlueSmokeTexturesFilePath }
{
	
}

bool CommonTexturesLoading::wasLoadingPerfect() const
{
	return playerTexturesLoader.wasLoadingPerfect()
		&& applesTextures.wasLoadingPerfect()
		&& glassMarbleTexture.wasLoadingPerfect()
		&& lightBulbAnimation.wasLoadingPerfect()
		&& magicOrbTextures.wasLoadingPerfect()
		&& diamondsTextures.wasLoadingPerfect();
}