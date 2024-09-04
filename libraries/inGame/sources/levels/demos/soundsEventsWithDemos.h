#ifndef BOB_THE_BLOB_IN_GAME_DEMOS_SOUNDS_EVENTS_H
#define BOB_THE_BLOB_IN_GAME_DEMOS_SOUNDS_EVENTS_H

#include <optional>

class SoundPlayer;

namespace demos{

struct DataPackage;
struct SoundPlaying;
	
void recordSoundEvent(std::optional<demos::DataPackage>& demoDataPackage, unsigned soundIndex, unsigned channel);

void playSoundIfAny(std::optional<demos::DataPackage>& demoDataPackage, const SoundPlayer& soundPlayer);

void playSoundChunk(const SoundPlayer& soundPlayer, const demos::SoundPlaying& soundData);

}

#endif //BOB_THE_BLOB_IN_GAME_DEMOS_SOUNDS_EVENTS_H