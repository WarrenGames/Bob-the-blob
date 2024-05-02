#ifndef BOB_THE_BLOB_GAME_RECORD_DEMO_MENU_H
#define BOB_THE_BLOB_GAME_RECORD_DEMO_MENU_H

#include "levelChoiceMenu/skillLevelTextsInterface.h"
#include "levelChoiceMenu/skillLevelCursorInterface.h"
#include "levelChoiceMenu/levelsListing.h"
#include "texts/textLoader.h"

struct Essentials;

namespace demosRecording{

enum : std::size_t{
	TxtTitle,
	TxtPrecedent,
	TxtNext,
	TxtQuit,
	TxtMax
};
	
struct Menu
{
	const TextsBlocks menuTexts;
	const sdl2::Font menuFont;
	LevelsListing levelsListing;
	const TextureCombo menuTitle;
	TextButton precedentPageButton;
	TextButton nextPageButton;
	TextButton quitButton;
	SkillLevelCursor skillLevelCursor;
	SkillLevelTextsInterface skillTexts;
	
	explicit Menu(Essentials& essentials);
	~Menu() = default;
	Menu( const Menu& ) = delete;
	Menu& operator= ( const Menu& ) = delete;
	Menu( Menu&& ) = default;
	Menu& operator= ( Menu&& ) = default;
	
	void updateButtons(Essentials& essentials);
	void drawEverything(Essentials& essentials) const;
};

}

#endif //BOB_THE_BLOB_GAME_RECORD_DEMO_MENU_H