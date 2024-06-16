#include "gameOptions/mainMenu/optionsMainMenuGraphisms.h"
#include "pathsFunctions/pathsFunctions.h"
#include "package/essentials.h"
#include "texturing/texturePosition.h"
#include "consts/fontsSizes.h"
#include "consts/screenConsts.h"
#include "consts/colors.h"

namespace options{

constexpr char LanguageFile[] = "optionsMenu/mainMenu.txt";

enum : std::size_t{
	Title,
	Inputs,
	Settings,
	Audio,
	Language,
	Max
};

}

options::MainMenuGraphisms::MainMenuGraphisms(Essentials& essentials):
	languagesTexts{ essentials.logs.error, path::getLanguageFile(essentials.chosenLanguage, LanguageFile), options::Max },
	menuFont{ essentials.logs.error, ArialFontPath, BigFontSize },
	title{ essentials.logs, essentials.rndWnd, menuFont, languagesTexts[options::Title], WhiteCol, TexturePosition{ GameScreenWidth / 2, SQR_SIZE, true, true } },
	inputsVignette{ essentials.logs, essentials.rndWnd, "textures/gameGUI/optionsMenu/keyboardPanel.png", TexturePosition{ GameScreenWidth / 4, SQR_SIZE * 2, true, false } },
	audioVignette{ essentials.logs, essentials.rndWnd, "textures/gameGUI/optionsMenu/audioVignette.png", TexturePosition{ GameScreenWidth / 4, SQR_SIZE * 9, true, false } },
	settingsVignette{ essentials.logs, essentials.rndWnd, "textures/gameGUI/optionsMenu/settingsPanel.png", TexturePosition{ GameScreenWidth * 3 / 4, SQR_SIZE * 2, true, false } },
	inputsButton{ essentials.logs, essentials.rndWnd, menuFont, languagesTexts[options::Inputs], GreenCol, WhiteCol, 
		TexturePosition{ GameScreenWidth / 4, SQR_SIZE * 5, true, true } },
	audioButton{ essentials.logs, essentials.rndWnd, menuFont, languagesTexts[options::Audio], GreenCol, WhiteCol,
		TexturePosition{ GameScreenWidth / 4, SQR_SIZE * 12, true, true } },
	settingsButton{ essentials.logs, essentials.rndWnd, menuFont, languagesTexts[options::Settings], GreenCol, WhiteCol,
		TexturePosition{ GameScreenWidth * 3 / 4, SQR_SIZE * 5, true, true } }
{
	
}

void options::MainMenuGraphisms::drawEverything(Essentials& essentials) const
{
	title.draw(essentials.rndWnd);
	inputsVignette.draw(essentials.rndWnd);
	audioVignette.draw(essentials.rndWnd);
	settingsVignette.draw(essentials.rndWnd);
	inputsButton.drawButton(essentials.rndWnd);
	audioButton.drawButton(essentials.rndWnd);
	settingsButton.drawButton(essentials.rndWnd);
}

void options::MainMenuGraphisms::update(Essentials& essentials)
{
	inputsButton.updateButton(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
	audioButton.updateButton(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
	settingsButton.updateButton(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
}