#ifndef BOB_THE_BLOB_IN_GAME_INPUTS_CONFIG_H
#define BOB_THE_BLOB_IN_GAME_INPUTS_CONFIG_H

#include "fileSystem/fileSystem.h"
#include "SDL_keycode.h"
#include <vector>

struct AppLogFiles;

class KeyboardInputsConfig
{
private:
	std::vector< SDL_Keycode > keys;
	bool isLoadingPerfect;

public:
	explicit KeyboardInputsConfig(AppLogFiles& logs, const fs::path& keyboardInputsConfig);
	~KeyboardInputsConfig() = default;
	KeyboardInputsConfig( const KeyboardInputsConfig& ) = delete;
	KeyboardInputsConfig& operator= ( const KeyboardInputsConfig& ) = delete;
	KeyboardInputsConfig( KeyboardInputsConfig&& ) = default;
	KeyboardInputsConfig& operator= ( KeyboardInputsConfig&& ) = default;
	
	SDL_Keycode getKeycode(std::size_t keycodeIndex) const;
	void setKeycode(std::size_t keycodeIndex, SDL_Keycode newKeycode);
	std::size_t size() const;
	
	void loadKeycodesFromFile(AppLogFiles& logs, const fs::path& keyboardInputsConfig);
	void writeKeycodesInFile(AppLogFiles& logs, const fs::path& keyboardInputsConfig) const;
	
	bool wasLoadingPerfect() const;
};

#endif //BOB_THE_BLOB_IN_GAME_INPUTS_CONFIG_H