#ifndef BOB_THE_BLOB_GAME_OPTIONS_KEYBOARD_DATA_H
#define BOB_THE_BLOB_GAME_OPTIONS_KEYBOARD_DATA_H

#include "inputsConfig/keyboardInputsConfig.h"
#include "widgets/buttons/highlightButtonWidget.h"
#include <vector>

struct Essentials;
struct AppLogFiles;
namespace sdl2{ class RendererWindow; class Font; }
class TextsBlocks;

class KeyboardOptions
{
private:
	KeyboardInputsConfig keyboardInputsConfig;
	std::vector< HighLightButton > keycodesButtons;
	TextureCombo pushNewKeyHint;
	
public:
	explicit KeyboardOptions(Essentials& essentials, const sdl2::Font& arialFont, const TextsBlocks keyboardMenusTexts);
	~KeyboardOptions() = default;
	KeyboardOptions( const KeyboardOptions& ) = delete;
	KeyboardOptions& operator= ( const KeyboardOptions& ) = delete;
	KeyboardOptions( KeyboardOptions&& ) = default;
	KeyboardOptions& operator= ( KeyboardOptions&& ) = default;
	
	void updateButtons(const Offset& mousePosition, bool mouseButtonState);
	void drawEverything(sdl2::RendererWindow& rndWnd) const;
	void updateKeycodeWithUser(Essentials& essentials, const sdl2::Font& arialFont);
	void recordModificationsToFiles(Essentials& essentials) const;
	
private:
	void createKeycodesButtons(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const sdl2::Font& arialFont);
	void drawButtons(sdl2::RendererWindow& rndWnd) const;
	
	void waitForKeycode(Essentials& essentials, const sdl2::Font& arialFont, std::size_t clickedButtonNumber);
	void checkKeyDown(Essentials& essentials, const sdl2::Font& arialFont, std::size_t clickedButtonNumber, SDL_Keycode newKeycode);
	void changeKeycode(Essentials& essentials, const sdl2::Font& arialFont, std::size_t keycodeNumber, SDL_Keycode newKeycode);
};

#endif //BOB_THE_BLOB_GAME_OPTIONS_KEYBOARD_DATA_H