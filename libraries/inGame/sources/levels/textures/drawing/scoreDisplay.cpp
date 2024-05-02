#include "levels/textures/drawing/scoreDisplay.h"
#include "package/essentials.h"
#include "levels/playerAttributes/playerAttributes.h"
#include "texturing/texturePosition.h"
#include "levels/maps/mapsConsts.h"
#include "consts/includeOptions.h"
#include "consts/fontsSizes.h"

ScoreDisplay::ScoreDisplay(Essentials& essentials, PlayerAttributes& playerAttributes):
	arial{ essentials.logs.error, ArialFontPath, SmallFontSize },
	background{ essentials.logs, essentials.rndWnd, SDL_Color{ 0, 0, 0, 255 }, SQR_SIZE * 2, SQR_SIZE / 2, 
			TexturePosition{ map::ClassicMapWidth * SQR_SIZE / 2, map::ClassicMapHeight * SQR_SIZE - SQR_SIZE / 2, true, true } }

{
	updateScoreText(essentials, playerAttributes);
}

void ScoreDisplay::updateScoreText(Essentials& essentials, PlayerAttributes& playerAttributes)
{
	if( playerAttributes.updateScore && arial )
	{
		scoreText.texture.loadBlendedText(essentials.logs, essentials.rndWnd, arial, std::to_string( playerAttributes.score ), SDL_Color{ 255, 255, 255, 255 } );
		scoreText.resetSpritePosition(TexturePosition{map::ClassicMapWidth * SQR_SIZE / 2, map::ClassicMapHeight * SQR_SIZE - SQR_SIZE / 2, true, true } );
		playerAttributes.updateScore = false;
	}
}

void ScoreDisplay::drawEverything(sdl2::RendererWindow& rndWnd) const
{
	background.draw(rndWnd);
	scoreText.draw(rndWnd);
}