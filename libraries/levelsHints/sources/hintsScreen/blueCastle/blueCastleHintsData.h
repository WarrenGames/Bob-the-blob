#ifndef LEVELS_HINTS_BLUE_CASTLE_HINTS_DATA_H
#define LEVELS_HINTS_BLUE_CASTLE_HINTS_DATA_H

#include "widgets/buttons/highlightButtonWidget.h"
#include "texturing/texturesCombo.h"
#include "text/sdl2ttf_font.h"
#include "texts/textLoader.h"

struct Essentials;

struct BlueCastleHintsScreen
{
	const TextsBlocks helpTexts;
	const sdl2::Font font;
	const TextureCombo background;
	const TextureCombo title;
	std::vector< TextureCombo > paragraphTexts;
	HighLightButton okButton;
	bool quitScreen;

	explicit BlueCastleHintsScreen(Essentials& essentials);
	~BlueCastleHintsScreen() = default;
	BlueCastleHintsScreen( const BlueCastleHintsScreen& ) = delete;
	BlueCastleHintsScreen& operator= ( const BlueCastleHintsScreen& ) = delete;
	BlueCastleHintsScreen( BlueCastleHintsScreen&& ) = default;
	BlueCastleHintsScreen& operator= ( BlueCastleHintsScreen&& ) = default;
	
	void drawEverything(Essentials& essentials) const;
	void fillParagraphTexts(Essentials& essentials);
	void setTextPosition();
	void drawParagraph(Essentials& essentials) const;
};

#endif //LEVELS_HINTS_BLUE_CASTLE_HINTS_DATA_H