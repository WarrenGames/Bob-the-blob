#include "sounds/gameSoundSystem.h"
#include "consts/soundsConsts.h"

GameSoundSystem::GameSoundSystem(AppLogFiles& logs, const PrefPathFinder& prefPath):
	soundSystemFilesPaths{ prefPath },
	soundSystem{ logs, soundSystemFilesPaths.getPaths(), sounds::Chunk_Max, sounds::Channel_Max }
{
	
}

bool GameSoundSystem::wasLoadingPerfect() const
{
	return soundSystem.wasLoadingPerfect();
}