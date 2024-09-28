#include "mainMenu/mainMenuThings.h"
#include "package/essentials.h"
#include "pathsFunctions/pathsFunctions.h"
#include "texturing/texturePosition.h"
#include "consts/fontsSizes.h"
#include "consts/colors.h"
#include "consts/screenConsts.h"

constexpr char WallpaperImagePath[] = "textures/wallpapers/mainMenuScreen.png";

constexpr char TextFile[] = "mainMenu/interface.txt";

mainMenu::MenuThings::MenuThings(Essentials& essentials):
	menuTexts{ essentials.logs.error, path::getLanguageFile(essentials.chosenLanguage, TextFile), TxtMax },
	arial{ essentials.logs.error, ArialFontPath, BigFontSize },
	wallpaper{ essentials.logs, essentials.rndWnd, WallpaperImagePath },
	gameTitle{ essentials.logs, essentials.rndWnd, arial, menuTexts[TxtTitle], GrayCol, TexturePosition{ GameScreenWidth / 2, SQR_SIZE, true, true } },
	levelChoice{essentials.logs, essentials.rndWnd, arial, menuTexts[TxtLevelMenu], GreenCol, WhiteCol, TexturePosition{ GameScreenWidth / 2, SQR_SIZE * 6, true, true } },
	recordDemo{essentials.logs, essentials.rndWnd, arial, menuTexts[TxtRecordDemo], GreenCol, WhiteCol, TexturePosition{ GameScreenWidth / 2, SQR_SIZE * 8, true, true } },
	playDemo{essentials.logs, essentials.rndWnd, arial, menuTexts[TxtPlayDemo], GreenCol, WhiteCol, TexturePosition{ GameScreenWidth / 2, SQR_SIZE * 10, true, true } },
	optionsMenu{essentials.logs, essentials.rndWnd, arial, menuTexts[TxtOptionsMenu], GreenCol, WhiteCol, TexturePosition{ GameScreenWidth / 2, SQR_SIZE * 12, true, true } },
	helpMenu{essentials.logs, essentials.rndWnd, arial, menuTexts[mainMenu::TxtHelp], GreenCol, WhiteCol, TexturePosition{ GameScreenWidth / 2, SQR_SIZE * 14, true, true } },
	quitMenu{ false }
{
	
}

void mainMenu::MenuThings::updateButtons(const Offset& mousePosition, bool isMouseButtonPushed)
{
	levelChoice.updateButton(mousePosition, isMouseButtonPushed);
	recordDemo.updateButton(mousePosition, isMouseButtonPushed);
	playDemo.updateButton(mousePosition, isMouseButtonPushed);
	optionsMenu.updateButton(mousePosition, isMouseButtonPushed);
	helpMenu.updateButton(mousePosition, isMouseButtonPushed);
}

void mainMenu::MenuThings::drawEverything(Essentials& essentials) const
{
	wallpaper.draw(essentials.rndWnd);
	gameTitle.draw(essentials.rndWnd);
	levelChoice.drawButton(essentials.rndWnd);
	recordDemo.drawButton(essentials.rndWnd);
	playDemo.drawButton(essentials.rndWnd);
	optionsMenu.drawButton(essentials.rndWnd);
	helpMenu.drawButton(essentials.rndWnd);
}
