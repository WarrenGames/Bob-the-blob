#include "levelChoiceMenu/levelChoiceThings.h"
#include "package/essentials.h"
#include "pathsFunctions/pathsFunctions.h"
#include "consts/screenConsts.h"
#include "levelChoiceMenu/levelChoiceMenuConsts.h"
#include "texturing/texturePosition.h"
#include "consts/fontsSizes.h"

levelChoice::MenuElements::MenuElements(Essentials& essentials):
	interfaceTexts{ essentials.logs.error, path::getLanguageFile(essentials.chosenLanguage, levelChoice::InterfaceTexts) },
	listFont{ essentials.logs.error, ArialFontPath, MediumFontSize },
	levelsListing{ essentials, listFont, levelChoice::LevelsListFilePath, ListOfLevels, levelChoice::OffButtonColor },
	precedentPageButton{ essentials.logs, essentials.rndWnd, listFont, interfaceTexts[levelChoice::TxtPrecedentBtn], levelChoice::SelectedButtonColor, levelChoice::OffButtonColor,
							TexturePosition{ SQR_SIZE * 2, GameScreenHeight - SQR_SIZE * 2, true, true } },
	nextPageButton{ essentials.logs, essentials.rndWnd, listFont, interfaceTexts[levelChoice::TxtNextBtn], levelChoice::SelectedButtonColor, levelChoice::OffButtonColor,
							TexturePosition{ GameScreenWidth - SQR_SIZE * 2, GameScreenHeight - SQR_SIZE * 2, true, true } },
	quitButton{ essentials.logs, essentials.rndWnd, listFont, interfaceTexts[levelChoice::TxtQuit], levelChoice::SelectedButtonColor, levelChoice::OffButtonColor,
							TexturePosition{ GameScreenWidth - SQR_SIZE * 2, SQR_SIZE, true, true } },
	skillLevelCursor{ essentials, TexturePosition{ GameScreenWidth / 2, GameScreenHeight - SQR_SIZE, true, true } },
	skillTexts{ essentials, TexturePosition{ GameScreenWidth / 2, GameScreenHeight - SQR_SIZE * 2, true, true }, levelChoice::OffButtonColor }
{
	
}

void levelChoice::MenuElements::drawInterface(Essentials& essentials) const
{
	levelsListing.drawCurrentPage(essentials);
	drawPagesButtonsIfNeeded(essentials);
	quitButton.drawButton(essentials.rndWnd);
	skillLevelCursor.drawEverything(essentials);
	skillTexts.drawSelectedSkill(essentials, skillLevelCursor.getSkillLevel() );
}

void levelChoice::MenuElements::drawPagesButtonsIfNeeded(Essentials& essentials) const
{
	if( levelsListing.size() >= 2 )
	{
		precedentPageButton.drawButton(essentials.rndWnd);
		nextPageButton.drawButton(essentials.rndWnd);
	}
}

void levelChoice::MenuElements::updateButtons(Essentials& essentials)
{
	updatePagesButtonsIfNeeded(essentials);
	quitButton.updateButton(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
	updateListPageButtons(essentials);
	skillLevelCursor.changeCursorPosition(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
}

void levelChoice::MenuElements::updateListPageButtons(Essentials& essentials)
{
	if( levelsListing.size() > 0 )
	{
		levelsListing.updateCurrentPageButtons(essentials);
	}
}

void levelChoice::MenuElements::updatePagesButtonsIfNeeded(Essentials& essentials)
{
	if( levelsListing.size() >= 2 )
	{
		precedentPageButton.updateButton(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
		nextPageButton.updateButton(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
	}
}