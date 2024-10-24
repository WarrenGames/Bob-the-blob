#ifndef IN_GAME_GLOBAL_SOUND_SYSTEM_H
#define IN_GAME_GLOBAL_SOUND_SYSTEM_H

#include "soundSystem/soundsVolume.h"
#include "soundSystem/soundsListLoader.h"
#include "soundSystem/soundsPlayer.h"
#include "soundSystem/soundChannelsSystem.h"
#include "fileSystem/fileSystem.h"
#include <vector>

struct AppLogFiles;

struct SoundSystem
{
	SoundVolumeLoader soundsVolume;
	SoundsListLoader soundsListLoader;
	SoundPlayer soundPlayer;
	SoundChannelsSystem soundChannels;
	
	explicit SoundSystem(AppLogFiles& logs, const std::vector< fs::path >& pathsList, unsigned expectedSoundsNumber, int expectedGroupTagsNumber);
	~SoundSystem() = default;
	SoundSystem( const SoundSystem& ) = delete;
	SoundSystem& operator= ( const SoundSystem& ) = delete;
	SoundSystem( SoundSystem&& ) = default;
	SoundSystem& operator= ( SoundSystem&& ) = default;
	
	bool wasLoadingPerfect() const;
};

#endif //IN_GAME_GLOBAL_SOUND_SYSTEM_H