#ifndef DEMOS_LIB_DATA_TO_RECORD_SOUND_PLAYING_H
#define DEMOS_LIB_DATA_TO_RECORD_SOUND_PLAYING_H

#include <chrono>

namespace demos{

struct SoundPlaying
{
	std::chrono::duration<long double, std::micro> delay;
	unsigned soundIndex;
	unsigned group;
	
	SoundPlaying();
	SoundPlaying(const std::chrono::duration<long double, std::micro>& newDelay, unsigned soundIndex_, unsigned group_);
	~SoundPlaying() = default;
	SoundPlaying( const SoundPlaying& ) = default;
	SoundPlaying& operator= ( const SoundPlaying& ) = default;
};

}

#endif //DEMOS_LIB_DATA_TO_RECORD_SOUND_PLAYING_H