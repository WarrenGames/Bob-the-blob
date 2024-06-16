#ifndef BOB_THE_BLOB_GAME_OPTIONS_GAME_SETTINGS_INTERFACE_H
#define BOB_THE_BLOB_GAME_OPTIONS_GAME_SETTINGS_INTERFACE_H

#include "widgets/buttons/textButtonWidget.h"
#include "widgets/editBoxes/uint_editBox.h"
#include "texturing/texturesCombo.h"
#include "text/sdl2ttf_font.h"
#include "texts/textLoader.h"

struct Essentials;

namespace options{

namespace settings{

class Interface
{
private:
	unsigned greenOrbCreationDelay;
	unsigned greenOrbDurationDelay;
	unsigned playerCanEatCactiDelay;
	const TextsBlocks languagesTexts;
	const sdl2::Font menuFont;
	const TextureCombo title;
	const TextureCombo background;
	const TextureCombo greenOrbCreationDelayText;
	const TextureCombo greenOrbDurationText;
	const TextureCombo playerEatCactiText;
	UintEditBox greenOrbCreationBox;
	UintEditBox greenOrbDurationBox;
	UintEditBox delayCactiEatableBox;

public:
	TextButton quitMenuButton;

	explicit Interface(Essentials& essentials);
	~Interface() = default;
	Interface( const Interface& ) = delete;
	Interface& operator= ( const Interface& ) = delete;
	Interface( Interface&& ) = default;
	Interface& operator= ( Interface&& ) = default;
	
	void updateInterface(Essentials& essentials);
	void drawInterface(Essentials& essentials) const;

	void saveOptionsToFiles(Essentials& essentials) const;

private:
	void saveSingleFileData(Essentials& essentials, const fs::path& filePath, unsigned toWriteData) const;

};

}

}

#endif //BOB_THE_BLOB_GAME_OPTIONS_GAME_SETTINGS_INTERFACE_H