#include "sounds/soundConfigFilesPaths.h"
#include "prefPath/prefPathFinder.h"
#include "logging/logsStruct.h"
#include "soundSystem/soundsPathsConsts.h"
#include "consts/soundsConsts.h"
#include "consts/filesAndPaths.h"

SoundSystemFilesPaths::SoundSystemFilesPaths(const PrefPathFinder& prefPath):
	configFilesPaths(sounds::PATH_SND_MAX)
{
	setPaths(prefPath);
}

const std::vector< fs::path > & SoundSystemFilesPaths::getPaths() const
{
	return configFilesPaths;
}

void SoundSystemFilesPaths::setPaths(const PrefPathFinder& prefPath)
{
	configFilesPaths[sounds::PATH_SND_VOLUME] = prefPath.getFsPath() / files::OptionsDir / sounds::SoundVolumeConfigFileName;
	configFilesPaths[sounds::PATH_SND_WAVEFORM_LIST] = sounds::WaveformSoundsList;
	configFilesPaths[sounds::PATH_SND_WAVEFORM_DIRECTORY] = sounds::WaveformsSoundsDirectory;
	configFilesPaths[sounds::PATH_SND_CHANNEL_CONFIG] = sounds::ChannelsConfigFilePath;
}