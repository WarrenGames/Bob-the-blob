#include "gameStarting/createRenderer.h"
#include "gameStarting/packageEssentials.h"
#include "texturing/rendererWindow.h"
#include "prefPath/prefPathFinder.h"
#include "logging/logsStruct.h"
#include "consts/screenConsts.h"

void createRenderer(const PrefPathFinder& prefPath, AppLogFiles& logs)
{
	if( sdl2::RendererWindow rndWnd{logs.error, MiniScreenWidth, MiniScreenHeight, "Bob the blob", ""} )
	{
		packageEssentials(prefPath, logs, rndWnd);
	}
}