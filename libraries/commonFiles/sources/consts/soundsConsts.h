#ifndef BOB_THE_BLOB_COMMONFILES_SOUNDS_CONSTS_H
#define BOB_THE_BLOB_COMMONFILES_SOUNDS_CONSTS_H

namespace sounds{

constexpr char WaveformsSoundsDirectory[] = "sounds";

constexpr char SoundVolumeConfigFileName[] = "soundVolumeConfig.txt";

constexpr char WaveformSoundsList[] = "data/sounds/soundsList.txt";

constexpr char ChannelsConfigFilePath[] = "data/sounds/channelsConfig.txt";

enum : unsigned{
	Chunk_FluxWow,
	Chunk_UhOh,
	Chunk_Max
};

enum : unsigned{
	Channel_Bobs,
	Channel_ItemsAppearance,
	Channel_ItemsEating,
	Channel_Max
};

}

#endif //BOB_THE_BLOB_COMMONFILES_SOUNDS_CONSTS_H