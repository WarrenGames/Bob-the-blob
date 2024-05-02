#ifndef BOB_THE_BLOB_IN_GAME_GIVEN_ELEMENT_COUNT_H
#define BOB_THE_BLOB_IN_GAME_GIVEN_ELEMENT_COUNT_H

#include "text/sdl2ttf_font.h"
#include "texturing/texturesCombo.h"
#include "texturing/texturePosition.h"
#include "fileSystem/fileSystem.h"

struct Essentials;
struct SDL_Rect;
namespace sdl2{ class RendererWindow; }

class ElementCountDisplay
{
private:
	const sdl2::Font textFont;
	unsigned displayedItemNumber;
	TexturePosition textPosition;
	TextureCombo blackSquare;
	TextureCombo text;
	TextureCombo item;
	
public:
	explicit ElementCountDisplay(Essentials& essentials, const SDL_Rect& blackSquareRect, unsigned itemNumber, const fs::path& itemTexturePath);
	~ElementCountDisplay() = default;
	ElementCountDisplay( const ElementCountDisplay& ) = delete;
	ElementCountDisplay& operator= ( const ElementCountDisplay& ) = delete;
	ElementCountDisplay( ElementCountDisplay&& ) = default;
	ElementCountDisplay& operator= ( ElementCountDisplay&& ) = default;
	
	void updateText(Essentials& essentials, unsigned itemCount);
	
	void drawEverything(sdl2::RendererWindow& rndWnd) const;
};

#endif //BOB_THE_BLOB_IN_GAME_GIVEN_ELEMENT_COUNT_H