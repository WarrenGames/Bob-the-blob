#include "hints/mainMenu/hintsMainMenuElements.h"
#include "package/essentials.h"
#include "pathsFunctions/pathsFunctions.h"
#include "texturing/texturePosition.h"
#include "consts/fontsSizes.h"
#include "consts/colors.h"
#include "consts/screenConsts.h"

constexpr char LanguageFileSubPath[] = "helpScreens/mainMenu.txt";

constexpr SDL_Color TextColor = { 255, 127, 0, 255 };

hintsScreens::MainMenu::MainMenu(Essentials& essentials):
	languagesTexts{ essentials.logs.error, path::getLanguageFile(essentials.chosenLanguage, LanguageFileSubPath), hintsScreens::MainMenuMax },
	menuFont{ essentials.logs.error, ArialFontPath, BigFontSize },
	title{ essentials.logs, essentials.rndWnd, menuFont, languagesTexts[hintsScreens::MainMenuTitle], TextColor, TexturePosition{ GameScreenWidth / 2, SQR_SIZE, true, true } },
	escapeEnemyMenuButton{ essentials.logs, essentials.rndWnd, menuFont, languagesTexts[hintsScreens::MainMenuFleeEnemy], WhiteCol, GrayCol, 
							TexturePosition{ GameScreenWidth / 2, SQR_SIZE * 4, true, true } }
{
	
}

void hintsScreens::MainMenu::updateEvents(Essentials& essentials)
{
	escapeEnemyMenuButton.updateButton(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
}

void hintsScreens::MainMenu::drawEverything(Essentials& essentials) const
{
	title.draw(essentials.rndWnd);
	escapeEnemyMenuButton.drawButton(essentials.rndWnd);
}