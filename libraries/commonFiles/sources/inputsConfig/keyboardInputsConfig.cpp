#include "inputsConfig/keyboardInputsConfig.h"
#include "consts/playerInputsConsts.h"
#include "logging/logsStruct.h"
#include <fstream>
#include <cassert>

KeyboardInputsConfig::KeyboardInputsConfig(AppLogFiles& logs, const fs::path& keyboardInputsConfig):
	keys( MoveMax, SDLK_UNKNOWN ),
	isLoadingPerfect{ true }
{
	loadKeycodesFromFile(logs, keyboardInputsConfig);
}

SDL_Keycode KeyboardInputsConfig::getKeycode(std::size_t keycodeIndex) const
{
	assert( keycodeIndex < keys.size() );
	return keys[keycodeIndex];
}

void KeyboardInputsConfig::setKeycode(std::size_t keycodeIndex, SDL_Keycode newKeycode)
{
	assert( keycodeIndex < keys.size() );
	keys[keycodeIndex] = newKeycode;
}

std::size_t KeyboardInputsConfig::size() const
{
	return keys.size();
}

void KeyboardInputsConfig::loadKeycodesFromFile(AppLogFiles& logs, const fs::path& keyboardInputsConfig)
{
	if( std::ifstream keycodesFile{ keyboardInputsConfig } )
	{
		assert( keys.size() == MoveMax );
		SDL_Keycode keycode{ SDLK_UNKNOWN };
		for( std::size_t i{0} ; i < keys.size() ; ++i )
		{
			if( keycodesFile >> keycode )
			{
				keys[i] = keycode;
			}
			else{
				isLoadingPerfect = false;
				logs.error << "Error: reading keycode number " << i << " failed in '" << keyboardInputsConfig.string() << "' keyboard game configuration file.\n";
			}
		}
	}
	else{
		isLoadingPerfect = false;
		logs.error << "Error: couldn't open '" << keyboardInputsConfig.string() << "' file in order to load keyboard game configuration.\n";
	}
}

void KeyboardInputsConfig::writeKeycodesInFile(AppLogFiles& logs, const fs::path& keyboardInputsConfig) const
{
	if( std::ofstream keycodesFile{ keyboardInputsConfig } )
	{
		for( auto const &keycode : keys )
		{
			if( ! ( keycodesFile << keycode << " " ) )
			{
				logs.error << "Error: couldn't write '" << keycode << "' in '" << keyboardInputsConfig.string() << "' file.\n";
			}
		}
	}
	else{
		logs.error << "Error: couldn't open '" << keyboardInputsConfig.string() << "' file in order to write keyboard game configuration.\n";
	}
}

bool KeyboardInputsConfig::wasLoadingPerfect() const
{
	return isLoadingPerfect;
}