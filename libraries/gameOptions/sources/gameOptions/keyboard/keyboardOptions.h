#ifndef BOB_THE_BLOB_GAME_OPTIONS_KEYBOARD_DATA_H
#define BOB_THE_BLOB_GAME_OPTIONS_KEYBOARD_DATA_H

#include "inputsConfig/keyboardInputsConfig.h"
#include "widgets/buttons/highlightButtonWidget.h"
#include "text/sdl2ttf_font.h"
#include "texts/textLoader.h"
#include <vector>

struct Essentials;
struct AppLogFiles;
namespace sdl2{ class RendererWindow; }

class KeyboardOptions
{
private:
	const TextsBlocks keyboardFunctionsTexts;
	const TextsBlocks keyboardMenusTexts;
	const sdl2::Font arialFont;
	KeyboardInputsConfig keyboardInputsConfig;
	std::vector< HighLightButton > keycodesButtons;
	std::vector< TextureCombo > buttonsInfos;
	TextureCombo functionsColumn;
	TextureCombo keycodesColumn;
	TextureCombo pushNewKeyHint;
	
public:
	explicit KeyboardOptions(Essentials& essentials);
	~KeyboardOptions() = default;
	KeyboardOptions( const KeyboardOptions& ) = delete;
	KeyboardOptions& operator= ( const KeyboardOptions& ) = delete;
	KeyboardOptions( KeyboardOptions&& ) = default;
	KeyboardOptions& operator= ( KeyboardOptions&& ) = default;
	
	void createKeycodesButtons(AppLogFiles& logs, sdl2::RendererWindow& rndWnd);
	
	void updateButtons(const Offset& mousePosition, bool mouseButtonState);
	void drawButtons(sdl2::RendererWindow& rndWnd) const;
	void drawInfosTexts(sdl2::RendererWindow& rndWnd) const;
	void drawEverything(sdl2::RendererWindow& rndWnd) const;
	
	void updateKeycodeWithUser(AppLogFiles& logs, sdl2::RendererWindow& rndWnd);
	void waitForKeycode(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, std::size_t clickedButtonNumber);
	void checkKeyDown(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, std::size_t clickedButtonNumber, SDL_Keycode newKeycode);
	void changeKeycode(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, std::size_t keycodeNumber, SDL_Keycode newKeycode);
	
	void recordModificationsToFiles(Essentials& essentials) const;
};

#endif //BOB_THE_BLOB_GAME_OPTIONS_KEYBOARD_DATA_H