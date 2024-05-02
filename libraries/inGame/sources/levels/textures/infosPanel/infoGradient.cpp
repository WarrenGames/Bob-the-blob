#include "levels/textures/infosPanel/infoGradient.h"
#include "levels/gameActors/playerThings/characterAbility.h"
#include "package/essentials.h"
#include "texturing/texturePosition.h"
#include "levels/textures/gradients.h"

InfoGradient::InfoGradient(Essentials& essentials, const SDL_Rect& gradientRect, unsigned startingValue, unsigned maxValue, const SDL_Color& leftColor, const SDL_Color& rightColor):
	gradientBackground{ essentials.logs, essentials.rndWnd, Black, gradientRect.w + GradientBorder * 2, gradientRect.h + GradientBorder * 2, 
						TexturePosition{ gradientRect.x - GradientBorder, gradientRect.y - GradientBorder, false, false } },
	gradient{ essentials.logs, essentials.rndWnd, startingValue, maxValue, gradientRect, leftColor, rightColor, false }
{

}

void InfoGradient::draw(sdl2::RendererWindow& rndWnd, const Ability& ability) const
{
	if( ability.isAbilityActive() )
	{
		gradientBackground.draw(rndWnd);
		gradient.draw(rndWnd);
	}
}

void InfoGradient::updateGradient(const Ability& ability)
{
	gradient.setNewCounterValue(ability.getCurrentDelay() );
}