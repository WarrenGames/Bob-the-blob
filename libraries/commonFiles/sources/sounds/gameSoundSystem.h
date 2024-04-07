#ifndef COMMON_FILES_GAME_SOUND_SYSTEM_H
#define COMMON_FILES_GAME_SOUND_SYSTEM_H

#include "sounds/soundConfigFilesPaths.h"
#include "soundSystem/soundSystem.h"

struct GameSoundSystem
{
	SoundSystemFilesPaths soundSystemFilesPaths;
	SoundSystem soundSystem;
	
	explicit GameSoundSystem(AppLogFiles& logs, const PrefPathFinder& prefPath);
	~GameSoundSystem() = default;
	GameSoundSystem( const GameSoundSystem& ) = delete;
	GameSoundSystem& operator= ( const GameSoundSystem& ) = delete;
	GameSoundSystem( GameSoundSystem&& ) = default;
	GameSoundSystem& operator= ( GameSoundSystem&& ) = default;
	
	bool wasLoadingPerfect() const;
};

#endif //COMMON_FILES_GAME_SOUND_SYSTEM_H