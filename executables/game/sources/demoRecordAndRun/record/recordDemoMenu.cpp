#include "demoRecordAndRun/record/recordDemoMenu.h"
#include "package/essentials.h"
#include "pathsFunctions/pathsFunctions.h"
#include "texturing/texturePosition.h"
#include "levelChoiceMenu/levelChoiceMenuConsts.h"
#include "consts/fontsSizes.h"
#include "consts/screenConsts.h"
#include "consts/colors.h"

constexpr char TextsFile[] = "demosMenu/demosRecordingMenu.txt";

demosRecording::Menu::Menu(Essentials& essentials):
	menuTexts{ essentials.logs.error, path::getLanguageFile(essentials.chosenLanguage, TextsFile), demosRecording::TxtMax },
	menuFont{ essentials.logs.error, ArialFontPath, MediumFontSize },
	levelsListing{ essentials, menuFont, levelChoice::LevelsListFilePath },
	menuTitle{essentials.logs, essentials.rndWnd, menuFont, menuTexts[demosRecording::TxtTitle], GreenCol, TexturePosition{ GameScreenWidth / 2, SQR_SIZE, true, true } },
	precedentPageButton{ essentials.logs, essentials.rndWnd, menuFont, menuTexts[demosRecording::TxtPrecedent], levelChoice::SelectedButtonColor, levelChoice::OffButtonColor,
							TexturePosition{ SQR_SIZE * 2, GameScreenHeight - SQR_SIZE * 2, true, true } },
	nextPageButton{ essentials.logs, essentials.rndWnd, menuFont, menuTexts[demosRecording::TxtNext], levelChoice::SelectedButtonColor, levelChoice::OffButtonColor,
							TexturePosition{ GameScreenWidth - SQR_SIZE * 2, GameScreenHeight - SQR_SIZE * 2, true, true } },
	quitButton{ essentials.logs, essentials.rndWnd, menuFont, menuTexts[demosRecording::TxtQuit], levelChoice::SelectedButtonColor, levelChoice::OffButtonColor,
							TexturePosition{ GameScreenWidth - SQR_SIZE * 2, SQR_SIZE, true, true } },
	skillLevelCursor{ essentials, TexturePosition{ GameScreenWidth / 2, GameScreenHeight - SQR_SIZE, true, true } },
	skillTexts{ essentials, TexturePosition{ GameScreenWidth / 2, GameScreenHeight - SQR_SIZE * 2, true, true } }
{
	
}

void demosRecording::Menu::updateButtons(Essentials& essentials)
{
	levelsListing.updateCurrentPageButtons(essentials);
	precedentPageButton.updateButton(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
	nextPageButton.updateButton(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
	quitButton.updateButton(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
	skillLevelCursor.changeCursorPosition(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
}

void demosRecording::Menu::drawEverything(Essentials& essentials) const
{
	menuTitle.draw(essentials.rndWnd);
	levelsListing.drawCurrentPage(essentials);
	precedentPageButton.drawButton(essentials.rndWnd);
	nextPageButton.drawButton(essentials.rndWnd);
	quitButton.drawButton(essentials.rndWnd);
	skillLevelCursor.drawEverything(essentials);
	skillTexts.drawSelectedSkill(essentials, skillLevelCursor.getSkillLevel() );
}