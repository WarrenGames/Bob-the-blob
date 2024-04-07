#ifndef BOB_THE_BLOB_IN_GAME_INFO_GRADIENT_H
#define BOB_THE_BLOB_IN_GAME_INFO_GRADIENT_H

#include "texturing/horizontalGradientTexture.h"

struct Essentials;
struct SDL_Rect;
struct SDL_Color;
namespace sdl2{ class RendererWindow; }
class Ability;

class InfoGradient
{
private:
	TextureCombo gradientBackground;
	sdl2::HorizontalGradient gradient;
	
public:
	explicit InfoGradient(Essentials& essentials, const SDL_Rect& gradientRect, unsigned startingValue, unsigned maxValue, const SDL_Color& leftColor, const SDL_Color& rightColor);
	~InfoGradient() = default;
	InfoGradient( const InfoGradient& ) = delete;
	InfoGradient& operator= ( const InfoGradient& ) = delete;
	InfoGradient( InfoGradient&& ) = default;
	InfoGradient& operator= ( InfoGradient&& ) = default;
	
	void draw(sdl2::RendererWindow& rndWnd, const Ability& ability) const;
	void updateGradient(const Ability& ability);
};

#endif //BOB_THE_BLOB_IN_GAME_INFO_GRADIENT_H