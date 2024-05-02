#include "levels/textures/balloons/balloonsPack.h"

BalloonsPack::BalloonsPack(AppLogFiles& logs, sdl2::RendererWindow& rndWnd):
	loadedTextures{ logs, rndWnd },
	sprites{ loadedTextures }
{
	
}