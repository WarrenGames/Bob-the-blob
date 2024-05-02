#include "hintsScreen/mexican/mexicanHintsData.h"
#include "pathsFunctions/pathsFunctions.h"
#include "package/essentials.h"
#include "texturing/texturePosition.h"
#include "levels/textures/texturesConsts.h"
#include "levels/textures/mexicanTexturesConsts.h"
#include "consts/fontsSizes.h"
#include "consts/colors.h"
#include "consts/screenConsts.h"

constexpr char TextFileSubPath[] = "levelHints/mexicanLevelHint.txt";
constexpr char BackgroundImagePath[] = "textures/wallpapers/mexicanScreen.png";

enum : std::size_t {
	TXT_TITLE,
	TXT_APPLES_HINT,
	TXT_GREEN_ORBS_HINT,
	TXT_LVL_END_CONDITION,
	TXT_OK_BUTTON,
	TXT_MAX
};

MexicanHintsData::MexicanHintsData(Essentials& essentials):
	helpTexts{essentials.logs.error, path::getLanguageFile(essentials.chosenLanguage, TextFileSubPath), TXT_MAX},
	arial{ essentials.logs.error, ArialFontPath, MediumFontSize },
	background{ essentials.logs, essentials.rndWnd, BackgroundImagePath, TexturePosition{ 0, 0, false, false } },
	screenTitle{ essentials.logs, essentials.rndWnd, arial, helpTexts[TXT_TITLE], BlackCol, TexturePosition{ GameScreenWidth / 2, SQR_SIZE, true, true } },
	applesTextures{ essentials.logs, essentials.rndWnd, textures::ApplesTexturesFilePath },
	applesSprites{ applesTextures },
	appleHintText{ essentials.logs, essentials.rndWnd, arial, helpTexts[TXT_APPLES_HINT], BlackCol, TexturePosition{ SQR_SIZE, SQR_SIZE * 4, false, true } },
	greenOrb{ essentials.logs, essentials.rndWnd, "textures/sprites/items/orb_0.png", TexturePosition{SQR_SIZE, SQR_SIZE * 7, true, true} },
	cactiTextures{ essentials.logs, essentials.rndWnd, textures::mexican::CactiTexturesFilePath },
	cactiSprites{ cactiTextures },
	greenOrbHintTexts{ essentials.logs, essentials.rndWnd, arial, helpTexts[TXT_GREEN_ORBS_HINT], WhiteCol, TexturePosition{ SQR_SIZE * 2, SQR_SIZE * 7, false, true } },
	levelEndCondition{ essentials.logs, essentials.rndWnd, arial, helpTexts[TXT_LVL_END_CONDITION], BlackCol, TexturePosition{ SQR_SIZE, SQR_SIZE * 12, false, true } },
	okButton{ essentials.logs, essentials.rndWnd, arial, helpTexts[TXT_OK_BUTTON], BlackCol, 
				SDL_Rect{ GameScreenWidth / 2 - SQR_SIZE, GameScreenHeight - SQR_SIZE * 2, SQR_SIZE * 2, SQR_SIZE}, GreenCol },
	quitScreen{ false }
{
	placeApplesTextures();
	placeCactiTextures();
}

void MexicanHintsData::drawEverything(Essentials& essentials) const
{
	background.draw(essentials.rndWnd);
	screenTitle.draw(essentials.rndWnd);
	drawApples(essentials);
	drawCactiTextures(essentials);
	appleHintText.draw(essentials.rndWnd);
	greenOrbHintTexts.draw(essentials.rndWnd);
	greenOrb.draw(essentials.rndWnd);
	levelEndCondition.draw(essentials.rndWnd);
	okButton.drawButton(essentials.rndWnd);
}

void MexicanHintsData::placeApplesTextures()
{
	for( std::size_t i{0} ; i < applesSprites.size() ; ++i )
	{
		applesSprites[i].setTexturePosition( TexturePosition{SQR_SIZE + SQR_SIZE * static_cast<int>(i), SQR_SIZE * 3, true, true} );
	}
}

void MexicanHintsData::drawApples(Essentials& essentials) const
{
	for( auto const &apple: applesSprites )
	{
		apple.draw(essentials.rndWnd);
	}
}

void MexicanHintsData::placeCactiTextures()
{
	for( std::size_t i{0} ; i < cactiSprites.size() ; ++i )
	{
		cactiSprites[i].setTexturePosition( TexturePosition{SQR_SIZE + SQR_SIZE * static_cast<int>(i), SQR_SIZE * 6, true, true } );
	}
}

void MexicanHintsData::drawCactiTextures(Essentials& essentials) const
{
	for( auto const &cactus : cactiSprites )
	{
		cactus.draw(essentials.rndWnd);
	}
}