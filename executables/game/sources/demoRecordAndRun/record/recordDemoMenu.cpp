#include "demoRecordAndRun/record/recordDemoMenu.h"
#include "package/essentials.h"
#include "pathsFunctions/pathsFunctions.h"
#include "texturing/texturePosition.h"
#include "levelChoiceMenu/levelChoiceMenuConsts.h"
#include "consts/fontsSizes.h"
#include "consts/screenConsts.h"
#include "consts/colors.h"

constexpr char TextsFile[] = "demosMenu/demosRecordingMenu.txt";
constexpr char BackgroundImageFilePath[] = "textures/wallpapers/mexicanScreen2.png";

demosRecording::Menu::Menu(Essentials& essentials):
	menuTexts{ essentials.logs.error, path::getLanguageFile(essentials.chosenLanguage, TextsFile), demosRecording::TxtMax },
	menuFont{ essentials.logs.error, ArialFontPath, MediumFontSize },
	levelsListing{ essentials, menuFont, levelChoice::LevelsListFilePath, ListOfLevels, BlackCol },
	menuTitle{essentials.logs, essentials.rndWnd, menuFont, menuTexts[demosRecording::TxtTitle], BlackCol, TexturePosition{ GameScreenWidth / 2, SQR_SIZE, true, true } },
	precedentPageButton{ essentials.logs, essentials.rndWnd, menuFont, menuTexts[demosRecording::TxtPrecedent], levelChoice::SelectedButtonColor, levelChoice::OffButtonColor,
							TexturePosition{ SQR_SIZE * 2, GameScreenHeight - SQR_SIZE * 2, true, true } },
	nextPageButton{ essentials.logs, essentials.rndWnd, menuFont, menuTexts[demosRecording::TxtNext], levelChoice::SelectedButtonColor, levelChoice::OffButtonColor,
							TexturePosition{ GameScreenWidth - SQR_SIZE * 2, GameScreenHeight - SQR_SIZE * 2, true, true } },
	quitButton{ essentials.logs, essentials.rndWnd, menuFont, menuTexts[demosRecording::TxtQuit], levelChoice::SelectedButtonColor, levelChoice::OffButtonColor,
							TexturePosition{ GameScreenWidth - SQR_SIZE * 2, SQR_SIZE, true, true } },
	skillLevelCursor{ essentials, TexturePosition{ GameScreenWidth / 2, GameScreenHeight - SQR_SIZE, true, true } },
	skillTexts{ essentials, TexturePosition{ GameScreenWidth / 2, GameScreenHeight - SQR_SIZE * 2, true, true }, BlackCol },
	backgroundImage{ essentials.logs, essentials.rndWnd, BackgroundImageFilePath, TexturePosition{ 0, 0, false, false } }
{
	
}

void demosRecording::Menu::updateButtons(Essentials& essentials)
{
	levelsListing.updateCurrentPageButtons(essentials);
	updatePagesButtonsIfNeeded(essentials);
	quitButton.updateButton(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
	skillLevelCursor.changeCursorPosition(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
}

void demosRecording::Menu::drawEverything(Essentials& essentials) const
{
	backgroundImage.draw(essentials.rndWnd);
	menuTitle.draw(essentials.rndWnd);
	levelsListing.drawCurrentPage(essentials);
	drawPagesButtonsIfNeeded(essentials);
	quitButton.drawButton(essentials.rndWnd);
	skillLevelCursor.drawEverything(essentials);
	skillTexts.drawSelectedSkill(essentials, skillLevelCursor.getSkillLevel() );
}

void demosRecording::Menu::drawPagesButtonsIfNeeded(Essentials& essentials) const
{
	if( levelsListing.size() >= 2 )
	{
		precedentPageButton.drawButton(essentials.rndWnd);
		nextPageButton.drawButton(essentials.rndWnd);
	}
}

void demosRecording::Menu::updatePagesButtonsIfNeeded(Essentials& essentials)
{
	if( levelsListing.size() >= 2 )
	{
		precedentPageButton.updateButton(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
		nextPageButton.updateButton(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
	}
}