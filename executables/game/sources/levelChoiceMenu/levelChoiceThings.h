#ifndef BOB_THE_BLOB_GAME_LEVEL_CHOICE_THINGS_H
#define BOB_THE_BLOB_GAME_LEVEL_CHOICE_THINGS_H

#include "levelChoiceMenu/levelsListing.h"
#include "texts/textLoader.h"

namespace levelChoice{
	
struct MenuElements
{
	const TextsBlocks interfaceTexts;
	const sdl2::Font listFont;
	LevelsListing levelsListing;
	TextButton precedentPageButton;
	TextButton nextPageButton;
	TextButton quitButton;
	
	explicit MenuElements(Essentials& essentials);
	~MenuElements() = default;
	MenuElements( const MenuElements& ) = delete;
	MenuElements& operator= ( const MenuElements& ) = delete;
	MenuElements( MenuElements&& ) = default;
	MenuElements& operator= ( MenuElements&& ) = default;
	
	void drawInterface(Essentials& essentials) const;
	
	void updateButtons(Essentials& essentials);
	void updateListPageButtons(Essentials& essentials);
};
	
}

#endif //BOB_THE_BLOB_GAME_LEVEL_CHOICE_THINGS_H