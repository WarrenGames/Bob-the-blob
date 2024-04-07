#include "levels/textures/balloons/balloonsTexturesLoader.h"
#include "levels/textures/balloonsConsts.h"

BalloonsTexturesLoader::BalloonsTexturesLoader(AppLogFiles& logs, sdl2::RendererWindow& rndWnd):
	balloonsTextures{ logs, rndWnd, BalloonsTexturesListFile },
	enemyLogos{ logs, rndWnd, BalloonsEnemyLogoListFile },
	orbsLogos{ logs, rndWnd, BalloonsOrbsLogoListFile }
{
	
}

bool BalloonsTexturesLoader::wasLoadingPerfect() const
{
	return balloonsTextures.wasLoadingPerfect() && enemyLogos.wasLoadingPerfect() && orbsLogos.wasLoadingPerfect();
}