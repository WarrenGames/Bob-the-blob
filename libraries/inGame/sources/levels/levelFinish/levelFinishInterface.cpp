#include "levels/levelFinish/levelFinishInterface.h"
#include "package/essentials.h"
#include "pathsFunctions/pathsFunctions.h"
#include "texturing/texturePosition.h"
#include "consts/colors.h"
#include "consts/fontsSizes.h"
#include "consts/screenConsts.h"
#include "levels/levelFinish/levelFinishConsts.h"

constexpr char LanguageFile[] = "levelComplete/levelComplete.txt";

enum : std::size_t
{
	Txt_LevelComplete,
	Txt_Max
};

LevelFinishInterface::LevelFinishInterface(Essentials& essentials):
	languagesTexts{ essentials.logs.error, path::getLanguageFile(essentials.chosenLanguage, LanguageFile), Txt_Max },
	font{ essentials.logs.error, ArialFontPath, BigFontSize },
	levelComplete{ essentials.logs, essentials.rndWnd, font, languagesTexts[Txt_LevelComplete], OrangeCol, TexturePosition{ GameScreenWidth / 2, GameScreenHeight / 2, true, true } },
	frameNumber{ 0 },
	grayWavesTextures{ essentials.logs, essentials.rndWnd, "data/textures/gameGUI/grayWavesTextures.txt" },
	grayWavesSprites{ grayWavesTextures }
{
	grayWavesSprites.setAllCoordinates( TexturePosition{ GameScreenWidth / 2, GameScreenHeight / 2, true, true } );
}

void LevelFinishInterface::drawLevelEndMessage(sdl2::RendererWindow& rndWnd) const
{
	grayWavesSprites.draw( rndWnd, frameNumber );
	levelComplete.draw(rndWnd);
}

void LevelFinishInterface::updateWaves()
{
	if( wavesDelay.hasTimeElapsed(std::chrono::milliseconds{ GrayWavesAnimDelay } ) )
	{
		wavesDelay.joinTimePoints();
		if( frameNumber + 1 < grayWavesSprites.size() )
		{
			frameNumber++;
		}
		else{
			frameNumber = 0;
		}
	}
}