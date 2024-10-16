#ifndef BOB_THE_BLOB_GAME_PLAY_DEMO_MENU_H
#define BOB_THE_BLOB_GAME_PLAY_DEMO_MENU_H

#include "levelChoiceMenu/levelsListing.h"
#include "texts/textLoader.h"

struct Essentials;

namespace demosPlaying{
	
struct DemoChoiceMenu
{
	const TextureCombo backgroundImage;
	const TextsBlocks interfaceTexts;
	const sdl2::Font font;
	LevelsListing demosFilesList;
	TextButton precedentPageButton;
	TextButton nextPageButton;
	TextButton quitButton;
	TextureCombo demosAbsenceInfos;
	TextureCombo menuTitle;
	unsigned demosDirectoryDisplayStatus;
	TextureCombo demosDirectoryText;
	TextureCombo demoDirDisplaying;
	
	explicit DemoChoiceMenu(Essentials& essentials);
	~DemoChoiceMenu() = default;
	DemoChoiceMenu( const DemoChoiceMenu& ) = delete;
	DemoChoiceMenu& operator= ( const DemoChoiceMenu& ) = delete;
	DemoChoiceMenu( DemoChoiceMenu&& ) = default;
	DemoChoiceMenu& operator= ( DemoChoiceMenu&& ) = default;
	
	void drawInterface(Essentials& essentials) const;
	void drawPageButtons(Essentials& essentials) const;
	
	void updateButtons(Essentials& essentials);
	void updateListPageButtons(Essentials& essentials);
	void updatePageButtons(Essentials& essentials);
	void drawDemosAbsenceInfo(Essentials& essentials) const;
	
	void readDemosDirectoryDisplayStatus(Essentials& essentials);
	void displayDemosDirectoryInfo(Essentials& essentials) const;
};

}

#endif //BOB_THE_BLOB_GAME_PLAY_DEMO_MENU_H