#include "miniScreenStart/miniScreenStartMenu.h"
#include "package/essentials.h"
#include "pathsFunctions/pathsFunctions.h"
#include "texturing/texturePosition.h"
#include "consts/fontsSizes.h"
#include "consts/screenConsts.h"
#include "consts/colors.h"

constexpr char LanguageFile[] = "gameStarting/miniScreen.txt";

enum : std::size_t{
	TxtTitle,
	TxtGameResolution,
	TxtF1_FullScreen,
	TxtF5_WindowedMode,
	TxtEscapeFirstPart,
	TxtEscapeSecondPart,
	TxtMax
};

constexpr int SquareValue = 64;

constexpr SDL_Color TextsColor = BlackCol;

gameStarting::MiniScreenMenu::MiniScreenMenu(Essentials& essentials):
	languagesTexts{ essentials.logs.error, path::getLanguageFile(essentials.chosenLanguage, LanguageFile), TxtMax },
	font{ essentials.logs.error, ArialFontPath, 22 },
	background{ essentials.logs, essentials.rndWnd, "textures/wallpapers/startScreen.png" }
{
	if( languagesTexts )
	{
		makeTextsTextures(essentials);
	}
}

gameStarting::MiniScreenMenu::operator bool() const
{
	return languagesTexts.wasReadingPerfect() && font && background;
}

void gameStarting::MiniScreenMenu::makeTextsTextures(Essentials& essentials)
{
	textsTextures.emplace_back( TextureCombo{ essentials.logs, essentials.rndWnd, font, languagesTexts[TxtTitle], TextsColor, 
		TexturePosition{ MiniScreenWidth / 2, SquareValue, true, true } } );
	textsTextures.emplace_back( TextureCombo{ essentials.logs, essentials.rndWnd, font, languagesTexts[TxtGameResolution] + gameStarting::getGameResolution(), TextsColor,
		TexturePosition{ SquareValue, SquareValue * 2 + SquareValue / 2, false, true } } );
	textsTextures.emplace_back( TextureCombo{ essentials.logs, essentials.rndWnd, font, languagesTexts[TxtF1_FullScreen], WhiteCol,
		TexturePosition{ SquareValue, SquareValue * 4, false, true } } );
	textsTextures.emplace_back( TextureCombo{ essentials.logs, essentials.rndWnd, font, languagesTexts[TxtF5_WindowedMode], WhiteCol,
		TexturePosition{ SquareValue, SquareValue * 4 + SquareValue / 2, false, true } } );
	textsTextures.emplace_back( TextureCombo{ essentials.logs, essentials.rndWnd, font, languagesTexts[TxtEscapeFirstPart], TextsColor,
		TexturePosition{ SquareValue, SquareValue * 6, false, true } } );
	textsTextures.emplace_back( TextureCombo{ essentials.logs, essentials.rndWnd, font, languagesTexts[TxtEscapeSecondPart], TextsColor,
		TexturePosition{ SquareValue, SquareValue * 6 + SquareValue / 2, false, true } } );
}

void gameStarting::MiniScreenMenu::drawEverything(Essentials& essentials) const
{
	background.draw(essentials.rndWnd);
	drawTexts(essentials);
}

void gameStarting::MiniScreenMenu::drawTexts(Essentials& essentials) const
{
	for( auto const &txt : textsTextures )
	{
		txt.draw(essentials.rndWnd);
	}
}

std::string gameStarting::getGameResolution()
{
	return std::string{ std::to_string( GameScreenWidth ) + " x " + std::to_string( GameScreenHeight ) };
}