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
	Keyboard,
	Joystick,
	Audio,
	Language,
	Max
};

}

options::MainMenuGraphisms::MainMenuGraphisms(Essentials& essentials):
	languagesTexts{ essentials.logs.error, path::getLanguageFile(essentials.chosenLanguage, LanguageFile), options::Max },
	menuFont{ essentials.logs.error, ArialFontPath, BigFontSize },
	title{ essentials.logs, essentials.rndWnd, menuFont, languagesTexts[options::Title], WhiteCol, TexturePosition{ GameScreenWidth / 2, SQR_SIZE, true, true } },
	keyboardInputsVignette{ essentials.logs, essentials.rndWnd, "textures/gameGUI/optionsMenu/keyboardPanel.png", 
		TexturePosition{ GameScreenWidth / 4, SQR_SIZE * 2, true, false } },
	audioVignette{ essentials.logs, essentials.rndWnd, "textures/gameGUI/optionsMenu/audioVignette.png", 
		TexturePosition{ GameScreenWidth / 4, SQR_SIZE * 9, true, false } },
	keyboardInputsButton{ essentials.logs, essentials.rndWnd, menuFont, languagesTexts[options::Keyboard], GreenCol, WhiteCol, 
		TexturePosition{ GameScreenWidth / 4, SQR_SIZE * 5, true, true } },
	audioButton{ essentials.logs, essentials.rndWnd, menuFont, languagesTexts[options::Audio], GreenCol, WhiteCol,
		TexturePosition{ GameScreenWidth / 4, SQR_SIZE * 12, true, false } }
{
	
}

void options::MainMenuGraphisms::drawEverything(Essentials& essentials) const
{
	title.draw(essentials.rndWnd);
	keyboardInputsVignette.draw(essentials.rndWnd);
	audioVignette.draw(essentials.rndWnd);
	keyboardInputsButton.drawButton(essentials.rndWnd);
	audioButton.drawButton(essentials.rndWnd);
}

void options::MainMenuGraphisms::update(Essentials& essentials)
{
	keyboardInputsButton.updateButton(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
	audioButton.updateButton(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
}