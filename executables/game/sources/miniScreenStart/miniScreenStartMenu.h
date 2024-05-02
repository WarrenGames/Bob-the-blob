#ifndef BOB_THE_BLOB_GAME_MINI_SCREEN_START_MENU_ELEMENTS_H
#define BOB_THE_BLOB_GAME_MINI_SCREEN_START_MENU_ELEMENTS_H

#include "texturing/texturesCombo.h"
#include "text/sdl2ttf_font.h"
#include "texts/textLoader.h"
#include <vector>

struct Essentials;

namespace gameStarting{

class MiniScreenMenu
{
private:
	const TextsBlocks languagesTexts;
	const sdl2::Font font;
	const TextureCombo background;
	std::vector< TextureCombo > textsTextures;
	
public:
	explicit MiniScreenMenu(Essentials& essentials);
	~MiniScreenMenu() = default;
	MiniScreenMenu( const MiniScreenMenu& ) = delete;
	MiniScreenMenu& operator= ( const MiniScreenMenu& ) = delete;
	MiniScreenMenu( MiniScreenMenu&& ) = default;
	MiniScreenMenu& operator= ( MiniScreenMenu&& ) = default;
	
	operator bool() const;
	
	void drawEverything(Essentials& essentials) const;

private:
	void drawTexts(Essentials& essentials) const;
	void makeTextsTextures(Essentials& essentials);
};

std::string getGameResolution();

}

#endif //BOB_THE_BLOB_GAME_MINI_SCREEN_START_MENU_ELEMENTS_H