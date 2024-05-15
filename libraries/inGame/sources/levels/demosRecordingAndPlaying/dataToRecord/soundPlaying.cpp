#include "levels/demosRecordingAndPlaying/dataToRecord/soundPlaying.h"
#include "consts/soundsConsts.h"

demos::SoundPlaying::SoundPlaying():
	soundIndex{ sounds::Chunk_Max },
	group{ sounds::Channel_Max }
{
	
}

demos::SoundPlaying::SoundPlaying(const std::chrono::duration<long double, std::micro>& newDelay, unsigned soundIndex_, unsigned group_):
	delay{ newDelay },
	soundIndex{ soundIndex_ },
	group{ group_ }
{
	
}
	