#ifndef BOB_THE_BLOB_GAME_MAIN_MENU_THINGS_H
#define BOB_THE_BLOB_GAME_MAIN_MENU_THINGS_H

#include "widgets/buttons/textButtonWidget.h"
#include "text/sdl2ttf_font.h"
#include "texts/textLoader.h"

struct Essentials;

namespace mainMenu{

enum{
	TxtTitle,
	TxtLevelMenu,
	TxtRecordDemo,
	TxtPlayDemo,
	TxtOptionsMenu,
	TxtMax
};
	
struct MenuThings
{
	const TextsBlocks menuTexts;
	const sdl2::Font arial;
	const TextureCombo wallpaper;
	const TextureCombo gameTitle;
	TextButton levelChoice;
	TextButton recordDemo;
	TextButton playDemo;
	TextButton optionsMenu;
	bool quitMenu;
	
	explicit MenuThings(Essentials& essentials);
	~MenuThings() = default;
	MenuThings( const MenuThings& ) = delete;
	MenuThings& operator= ( const MenuThings& ) = delete;
	MenuThings( MenuThings&& ) = default;
	MenuThings& operator= ( MenuThings&& ) = default;
	
	void updateButtons(const Offset& mousePosition, bool isMouseButtonPushed);
	void drawEverything(Essentials& essentials) const;
};

}

#endif //BOB_THE_BLOB_GAME_MAIN_MENU_THINGS_H