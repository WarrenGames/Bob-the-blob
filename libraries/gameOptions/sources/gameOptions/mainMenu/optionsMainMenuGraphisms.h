#ifndef BOB_THE_BLOB_GAME_OPTIONS_MAIN_MENU_GRAPHISMS_H
#define BOB_THE_BLOB_GAME_OPTIONS_MAIN_MENU_GRAPHISMS_H

#include "texts/textLoader.h"
#include "text/sdl2ttf_font.h"
#include "texturing/texturesCombo.h"
#include "widgets/buttons/textButtonWidget.h"

struct Essentials;

namespace options{

struct MainMenuGraphisms
{
	const TextsBlocks languagesTexts;
	const sdl2::Font menuFont;
	TextureCombo title;
	TextureCombo keyboardInputsVignette;
	TextureCombo audioVignette;
	TextButton keyboardInputsButton;
	TextButton audioButton;
	
	explicit MainMenuGraphisms(Essentials& essentials);
	~MainMenuGraphisms() = default;
	MainMenuGraphisms( const MainMenuGraphisms& ) = delete;
	MainMenuGraphisms& operator= ( const MainMenuGraphisms& ) = delete;
	MainMenuGraphisms( MainMenuGraphisms&& ) = default;
	MainMenuGraphisms& operator= ( MainMenuGraphisms&& ) = default;
	
	void drawEverything(Essentials& essentials) const;
	
	void update(Essentials& essentials);
};

}

#endif //BOB_THE_BLOB_GAME_OPTIONS_MAIN_MENU_GRAPHISMS_H