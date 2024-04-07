#ifndef MEXICAN_LEVEL_HINTS_DATA_H
#define MEXICAN_LEVEL_HINTS_DATA_H

#include "advancedDrawing/texturesLoading/fileTexturesList.h"
#include "advancedDrawing/texturesDrawing/constAnimationDrawing.h"
#include "widgets/buttons/highlightButtonWidget.h"
#include "texturing/texturesCombo.h"
#include "text/sdl2ttf_font.h"
#include "texts/textLoader.h"

struct Essentials;

struct MexicanHintsData
{
	const TextsBlocks helpTexts;
	const sdl2::Font arial;
	const TextureCombo background;
	const TextureCombo screenTitle;
	TexturesFilesList applesTextures;
	ConstAnimDraw applesSprites;
	TextureCombo appleHintText;
	TextureCombo greenOrb;
	TexturesFilesList cactiTextures;
	ConstAnimDraw cactiSprites;
	TextureCombo greenOrbHintTexts;
	TextureCombo levelEndCondition;
	HighLightButton okButton;
	bool quitScreen;

	explicit MexicanHintsData(Essentials& essentials);
	~MexicanHintsData() = default;
	MexicanHintsData( const MexicanHintsData& ) = delete;
	MexicanHintsData& operator= ( const MexicanHintsData& ) = delete;
	MexicanHintsData( MexicanHintsData&& ) = default;
	MexicanHintsData& operator= ( MexicanHintsData&& ) = default;
	
	void drawEverything(Essentials& essentials) const;
	void placeApplesTextures();
	void drawApples(Essentials& essentials) const;
	void placeCactiTextures();
	void drawCactiTextures(Essentials& essentials) const;
};

#endif //MEXICAN_LEVEL_HINTS_DATA_H