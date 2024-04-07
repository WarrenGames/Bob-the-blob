#ifndef SOUND_SYSTEM_CONFIG_FILES_PATHS_H
#define SOUND_SYSTEM_CONFIG_FILES_PATHS_H

#include "fileSystem/fileSystem.h"
#include <vector>

class PrefPathFinder;

class SoundSystemFilesPaths
{
private:
	std::vector< fs::path > configFilesPaths;

public:
	explicit SoundSystemFilesPaths(const PrefPathFinder& prefPath);
	~SoundSystemFilesPaths() = default;
	SoundSystemFilesPaths( const SoundSystemFilesPaths& ) = delete;
	SoundSystemFilesPaths& operator= ( const SoundSystemFilesPaths& ) = delete;
	SoundSystemFilesPaths( SoundSystemFilesPaths&& ) = default;
	SoundSystemFilesPaths& operator= ( SoundSystemFilesPaths&& ) = default;
	
	const std::vector< fs::path > & getPaths() const;

private:
	void setPaths(const PrefPathFinder& prefPath);
};

#endif //SOUND_SYSTEM_CONFIG_FILES_PATHS_H