#include "gameStarting/createRenderer.h"
#include "gameStarting/packageEssentials.h"
#include "texturing/rendererWindow.h"
#include "prefPath/prefPathFinder.h"
#include "logging/logsStruct.h"
#include "consts/screenConsts.h"

constexpr char GameIconPath[] = "textures/sprites/bobPlayer/bobPlayer_0.png";

void createRenderer(const PrefPathFinder& prefPath, AppLogFiles& logs)
{
	if( sdl2::RendererWindow rndWnd{logs.error, MiniScreenWidth, MiniScreenHeight, "Bob the blob", GameIconPath} )
	{
		packageEssentials(prefPath, logs, rndWnd);
	}
}