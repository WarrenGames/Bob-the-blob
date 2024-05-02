#include "gameStarting/initializeSDL_Modules.h"
#include "gameStarting/createRenderer.h"
#include "initialization/sdl2ModuleInit.h"
#include "initialization/sdl2MixerInit.h"
#include "initialization/sdl2TTF_Init.h"
#include "prefPath/prefPathFinder.h"
#include "logging/logsStruct.h"
#include "SDL.h"

void initializeSDL_Modules(const PrefPathFinder& prefPath, AppLogFiles& logs)
{
	sdl2::ModuleInit sdlInit{ SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER | SDL_INIT_HAPTIC, logs.error };
	sdl2::TTFModule ttfInit{logs.error};
	sdl2::MixerModule mixerInit{logs.error};
	
	if( sdlInit.wasLoadingPerfect() && ttfInit.wasLoadingPerfect() && mixerInit.wasLoadingPerfect() )
	{
		createRenderer(prefPath, logs);
	}
}