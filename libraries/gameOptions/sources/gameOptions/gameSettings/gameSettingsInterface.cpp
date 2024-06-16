#include "gameOptions/gameSettings/gameSettingsInterface.h"
#include "pathsFunctions/pathsFunctions.h"
#include "fileDataFetch/fileDataFetch.h"
#include "package/essentials.h"
#include "texturing/texturePosition.h"
#include "consts/fontsSizes.h"
#include "consts/screenConsts.h"
#include "consts/colors.h"
#include "consts/filesAndPaths.h"
#include <fstream>

constexpr char LanguageFile[] = "optionsMenu/settingsMenu.txt";

enum : std::size_t{
	TxtTitle,
	TxtGreenOrbCreation,
	TxtGreenOrbDuration,
	TxtPlayerCanEatCactiDelay,
	TxtQuitSettings,
	TxtGreenOrbMax
};

constexpr int BoxWidth = SQR_SIZE * 2;
constexpr int BoxHeight = SQR_SIZE / 2;

options::settings::Interface::Interface(Essentials& essentials):
	greenOrbCreationDelay{ fileDataFetch::getUnsignedInt( path::getOptionFilePath(essentials.prefPath, files::GreenOrbCreationDelay) ) },
	greenOrbDurationDelay{ fileDataFetch::getUnsignedInt( path::getOptionFilePath(essentials.prefPath, files::GreenOrbDurationFile) ) },
	playerCanEatCactiDelay{ fileDataFetch::getUnsignedInt( path::getOptionFilePath(essentials.prefPath, files::PlayerCanEatCacti) ) },
	languagesTexts{ essentials.logs.error, path::getLanguageFile(essentials.chosenLanguage, LanguageFile), TxtGreenOrbMax },
	menuFont{ essentials.logs.error, ArialFontPath, MediumFontSize },
	title{ essentials.logs, essentials.rndWnd, menuFont, languagesTexts[TxtTitle], WhiteCol, TexturePosition{ GameScreenWidth / 2, SQR_SIZE, true, true } },
	background{ essentials.logs, essentials.rndWnd, "textures/wallpapers/optionsScreen.png" },
	greenOrbCreationDelayText{ essentials.logs, essentials.rndWnd, menuFont, languagesTexts[TxtGreenOrbCreation], BlackCol, TexturePosition{ SQR_SIZE / 2, SQR_SIZE * 3, false, true } },
	greenOrbDurationText{ essentials.logs, essentials.rndWnd, menuFont, languagesTexts[TxtGreenOrbDuration], BlackCol, TexturePosition{ SQR_SIZE / 2, SQR_SIZE * 5, false, true } },
	playerEatCactiText{ essentials.logs, essentials.rndWnd, menuFont, languagesTexts[TxtPlayerCanEatCactiDelay], BlackCol, TexturePosition{ SQR_SIZE / 2, SQR_SIZE * 7, false, true } },
	greenOrbCreationBox{ essentials.logs, essentials.rndWnd, 
		SDL_Rect{ greenOrbCreationDelayText.sprite.x_pos() + greenOrbCreationDelayText.sprite.width() + SQR_SIZE / 2, 
			greenOrbCreationDelayText.sprite.y_pos() + greenOrbCreationDelayText.sprite.height() / 2 - BoxHeight / 2, BoxWidth, BoxHeight }, 
		MediumFontSize, greenOrbCreationDelay },
	greenOrbDurationBox{ essentials.logs, essentials.rndWnd, 
		SDL_Rect{ greenOrbDurationText.sprite.x_pos() + greenOrbDurationText.sprite.width() + SQR_SIZE / 2, 
			greenOrbDurationText.sprite.y_pos() + greenOrbDurationText.sprite.height() / 2 - BoxHeight / 2, BoxWidth, BoxHeight },
		MediumFontSize, greenOrbDurationDelay },
	delayCactiEatableBox{ essentials.logs, essentials.rndWnd,
		SDL_Rect{ playerEatCactiText.sprite.x_pos() + playerEatCactiText.sprite.width() + SQR_SIZE / 2,
			playerEatCactiText.sprite.y_pos() + playerEatCactiText.sprite.height() / 2 - BoxHeight / 2, BoxWidth, BoxHeight },
		MediumFontSize, playerCanEatCactiDelay },
	quitMenuButton{ essentials.logs, essentials.rndWnd, menuFont, languagesTexts[TxtQuitSettings], GreenCol, WhiteCol, 
		TexturePosition{ GameScreenWidth - SQR_SIZE * 3, GameScreenHeight - SQR_SIZE, true, true } }
{
	
}

void options::settings::Interface::updateInterface(Essentials& essentials)
{
	greenOrbCreationBox.catchUserFocus(essentials.logs, essentials.rndWnd, essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
	greenOrbDurationBox.catchUserFocus(essentials.logs, essentials.rndWnd, essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
	delayCactiEatableBox.catchUserFocus(essentials.logs, essentials.rndWnd, essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
	quitMenuButton.updateButton( essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
}

void options::settings::Interface::drawInterface(Essentials& essentials) const
{
	background.draw(essentials.rndWnd);
	title.draw(essentials.rndWnd);
	greenOrbCreationDelayText.draw(essentials.rndWnd);
	greenOrbDurationText.draw(essentials.rndWnd);
	playerEatCactiText.draw(essentials.rndWnd);
	greenOrbCreationBox.drawBoxWithoutFocus(essentials.rndWnd);
	greenOrbDurationBox.drawBoxWithoutFocus(essentials.rndWnd);
	delayCactiEatableBox.drawBoxWithoutFocus(essentials.rndWnd);
	quitMenuButton.drawButton(essentials.rndWnd);
}

void options::settings::Interface::saveOptionsToFiles(Essentials& essentials) const
{
	saveSingleFileData(essentials, path::getOptionFilePath(essentials.prefPath, files::GreenOrbCreationDelay), greenOrbCreationDelay);
	saveSingleFileData(essentials, path::getOptionFilePath(essentials.prefPath, files::GreenOrbDurationFile), greenOrbDurationDelay);
	saveSingleFileData(essentials, path::getOptionFilePath(essentials.prefPath, files::PlayerCanEatCacti), playerCanEatCactiDelay);
}

void options::settings::Interface::saveSingleFileData(Essentials& essentials, const fs::path& filePath, unsigned toWriteData) const
{
	if( std::ofstream file{ filePath } )
	{
		if( ! ( file << toWriteData ) )
		{
			essentials.logs.error << "Error: the file '" << filePath.string() << "' was open but writing failed in game settings.\n";
		}
	}
	else{
		essentials.logs.error << "Error: couldn't open '" << filePath.string() << "' file in game settings.\n";
	}
}