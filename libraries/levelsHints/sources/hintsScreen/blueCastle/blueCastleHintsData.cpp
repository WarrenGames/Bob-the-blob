#include "hintsScreen/blueCastle/blueCastleHintsData.h"
#include "paragraph/makeTextTextures.h"
#include "paragraph/paragraphData.h"
#include "package/essentials.h"
#include "pathsFunctions/pathsFunctions.h"
#include "texturing/texturePosition.h"
#include "consts/fontsSizes.h"
#include "consts/colors.h"
#include "consts/screenConsts.h"

constexpr char BackgroundImagePath[] = "textures/wallpapers/mainMenuScreen.png";

constexpr char LanguageInterfaceFile[] = "levelHints/blueCastleInterfaceTexts.txt";
constexpr char ParagraphSubPath[] = "levelHints/blueCastleLevelHint.txt";

constexpr int ExplanationsTextWidth = 11 * SQR_SIZE;

constexpr SDL_Color TextColor = { 255, 255, 255, 255 };

enum{ 	TXT_TITLE,
		TXT_OK_BUTTON,
		TXT_MAX
};

BlueCastleHintsScreen::BlueCastleHintsScreen(Essentials& essentials):
	helpTexts{ essentials.logs.error, path::getLanguageFile(essentials.chosenLanguage, LanguageInterfaceFile), TXT_MAX },
	font{ essentials.logs.error, ArialFontPath, MediumFontSize },
	background{ essentials.logs, essentials.rndWnd, BackgroundImagePath, TexturePosition{ 0, 0, false, false } },
	title{ essentials.logs, essentials.rndWnd, font, helpTexts[TXT_TITLE], TextColor, TexturePosition{ GameScreenWidth / 2, SQR_SIZE, true, true } },
	okButton{ essentials.logs, essentials.rndWnd, font, helpTexts[TXT_OK_BUTTON], WhiteCol, 
				SDL_Rect{ GameScreenWidth / 2 - SQR_SIZE, GameScreenHeight - SQR_SIZE * 2, SQR_SIZE * 2, SQR_SIZE}, GreenCol },
	quitScreen{ false }
{
	fillParagraphTexts(essentials);
	setTextPosition();
}

void BlueCastleHintsScreen::fillParagraphTexts(Essentials& essentials)
{
	ParagraphData paragraphData{ essentials.logs, path::getLanguageFile(essentials.chosenLanguage, ParagraphSubPath), ArialFontPath, MediumFontSize, TextColor, ExplanationsTextWidth };
	makeText::openFileForReading( essentials.logs, essentials.rndWnd, paragraphData, paragraphTexts );
}

void BlueCastleHintsScreen::drawEverything(Essentials& essentials) const
{
	background.draw(essentials.rndWnd);
	okButton.drawButton(essentials.rndWnd);
	title.draw(essentials.rndWnd);
	drawParagraph(essentials);
}

void BlueCastleHintsScreen::setTextPosition()
{
	for( int i{0} ; i < static_cast<int>( paragraphTexts.size() ) ; ++i )
	{
		paragraphTexts[i].sprite.setTexturePosition( TexturePosition{ SQR_SIZE * 4, SQR_SIZE * 10 + SQR_SIZE / 2 * i, false, true } );
	}
}

void BlueCastleHintsScreen::drawParagraph(Essentials& essentials) const
{
	for( auto const &txt : paragraphTexts )
	{
		txt.draw(essentials.rndWnd);
	}
}