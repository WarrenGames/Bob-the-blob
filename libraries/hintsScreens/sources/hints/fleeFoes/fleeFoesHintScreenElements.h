#ifndef HINTS_SCREENS_FLEE_FOES_HINTS_SCREEN_ELEMENTS_H
#define HINTS_SCREENS_FLEE_FOES_HINTS_SCREEN_ELEMENTS_H

#include "customTypes/positionTypes.h"
#include "levels/maps/gameMap.h"
#include "levels/textures/mappingTextures/mappingTextures.h"
#include "levels/textures/mappingTextures/mappingSprites.h"
#include "texts/textLoader.h"
#include "texturing/texturesCombo.h"

struct Essentials;

namespace hintsScreens{

class FleeFoes 
{
private:
	bool isLoadingPerfect;
	Offset mapLeftCorner;
	Offset mapCoords;
	GameMap miniMapData;
	TextsBlocks languagesTexts;
	MappingTextures miniMapTextures;
	MappingSprites miniMapSprites;
	std::vector< TextureCombo > infosText;
	sdl2::TextureLoader leftRightFleeArrows;
	sdl2::TextureLoader upDownFleeArrows;
	sdl2::Sprite topArrows;
	sdl2::Sprite bottomArrows;
	sdl2::Sprite leftArrows;
	sdl2::Sprite rightArrows;
	
public:
	explicit FleeFoes(Essentials& essentials);
	~FleeFoes() = default;
	FleeFoes( const FleeFoes& ) = delete;
	FleeFoes& operator= ( const FleeFoes& ) = delete;
	FleeFoes( FleeFoes&& ) = default;
	FleeFoes& operator= ( FleeFoes&& ) = default;
	
	void drawEverything(Essentials& essentials);
	
private:
	void drawMap(Essentials& essentials);
	void setTextPosition();
	void drawInfosText(Essentials& essentials) const;
	void drawArrows(Essentials& essentials) const;
};

}

#endif //HINTS_SCREENS_FLEE_FOES_HINTS_SCREEN_ELEMENTS_H