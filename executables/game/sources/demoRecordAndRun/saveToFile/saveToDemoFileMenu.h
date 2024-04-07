#ifndef BOB_THE_BLOB_GAME_SAVE_DEMO_TO_FILE_MENU_H
#define BOB_THE_BLOB_GAME_SAVE_DEMO_TO_FILE_MENU_H

#include "widgets/editBoxes/stringEditBox.h"
#include "widgets/buttons/textButtonWidget.h"
#include "texts/textLoader.h"
#include <string>

struct Essentials;
namespace demos{ struct DataPackage; struct SpritesPositions; }

namespace saveDemo{

enum{ 
	TxtTitle,
	TxtSaveBtn,
	TxtQuitBtn,
	TxtFileNameHint,
	TxtMaxPlayerRecordedPoints,
	TxtMaxBobsRecordedPoints,
	TxtMax
};
	
struct FileMenu
{
	std::string fileName;
	const TextsBlocks menuTexts;
	const sdl2::Font arialFont;
	TextureCombo menuTitle;
	TextureCombo fileNameTextHint;
	TextureCombo recordedPlayerMoves;
	TextureCombo recordedBobsMoves;
	StringEditBox fileNameBox;
	TextButton saveToFileButton;
	TextButton quitWithoutSaving;
	
	explicit FileMenu(Essentials& essentials, const demos::DataPackage& demoDataPackage);
	~FileMenu() = default;
	FileMenu( const FileMenu& ) = delete;
	FileMenu& operator= ( const FileMenu& ) = delete;
	FileMenu( FileMenu&& ) = default;
	FileMenu& operator= ( FileMenu&& ) = default;
	
	void drawEverything(Essentials& essentials) const;
	void updateInterface(Essentials& essentials);
	
	std::string getMaxRecPlayerText(const demos::SpritesPositions& spritesPositions) const;
	std::string getMaxRecBobsText(const demos::SpritesPositions& spritesPositions) const;
};

}

#endif //BOB_THE_BLOB_GAME_SAVE_DEMO_TO_FILE_MENU_H