#include "levels/textures/infosPanel/givenElementCount.h"
#include "package/essentials.h"
#include "consts/colors.h"
#include "consts/fontsSizes.h"

ElementCountDisplay::ElementCountDisplay(Essentials& essentials, const SDL_Rect& blackSquareRect, unsigned itemNumber, const fs::path& itemTexturePath):
	textFont{ essentials.logs.error, ArialFontPath, SmallFontSize },
	displayedItemNumber{ itemNumber },
	textPosition{ blackSquareRect.x + SQR_SIZE / 2, blackSquareRect.y + blackSquareRect.h / 2, true, true },
	blackSquare{ essentials.logs, essentials.rndWnd, BlackCol, blackSquareRect.w, blackSquareRect.h },
	text{ essentials.logs, essentials.rndWnd, textFont, std::to_string( itemNumber ), WhiteCol, textPosition },
	item{ essentials.logs, essentials.rndWnd, itemTexturePath.string() }
{
	item.sprite.setTexturePosition( TexturePosition{ blackSquareRect.x + blackSquareRect.w - SQR_SIZE / 2, blackSquareRect.y + blackSquareRect.h / 2, true, true } );
	blackSquare.sprite.setTexturePosition( TexturePosition{ blackSquareRect.x, blackSquareRect.y, false, false } );
}

void ElementCountDisplay::updateText(Essentials& essentials, unsigned itemCount)
{
	if( itemCount != displayedItemNumber )
	{
		displayedItemNumber = itemCount;
		text.texture.loadBlendedText(essentials.logs, essentials.rndWnd, textFont, std::to_string( displayedItemNumber ), WhiteCol );
		text.sprite.resetDimensions();
		text.sprite.resetSourceRect();
		text.sprite.setTexturePosition( textPosition );
	}
}

void ElementCountDisplay::drawEverything(sdl2::RendererWindow& rndWnd) const
{
	blackSquare.draw(rndWnd);
	text.draw(rndWnd);
	item.draw(rndWnd);
}