#ifndef HINTS_SCREENS_MAIN_MENU_ELEMENTS_H
#define HINTS_SCREENS_MAIN_MENU_ELEMENTS_H

#include "texturing/texturesCombo.h"
#include "widgets/buttons/textButtonWidget.h"
#include "text/sdl2ttf_font.h"
#include "texts/textLoader.h"

struct Essentials;

namespace hintsScreens{

enum : std::size_t{ 
	MainMenuTitle, 
	MainMenuFleeEnemy, 
	MainMenuMax 
};

struct MainMenu
{
	const TextsBlocks languagesTexts;
	const sdl2::Font menuFont;
	const TextureCombo title;
	TextButton escapeEnemyMenuButton;
	
	explicit MainMenu(Essentials& essentials);
	~MainMenu() = default;
	MainMenu( const MainMenu& ) = delete;
	MainMenu& operator= ( const MainMenu& ) = delete;
	MainMenu( MainMenu&& ) = default;
	MainMenu& operator= ( MainMenu&& ) = default;
	
	void updateEvents(Essentials& essentials);
	void drawEverything(Essentials& essentials) const;
};

}

#endif //HINTS_SCREENS_MAIN_MENU_ELEMENTS_H