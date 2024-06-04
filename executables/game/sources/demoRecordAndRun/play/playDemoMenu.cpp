#include "demoRecordAndRun/play/playDemoMenu.h"
#include "pathsFunctions/pathsFunctions.h"
#include "package/essentials.h"
#include "consts/fontsSizes.h"
#include "consts/filesAndPaths.h"
#include "consts/screenConsts.h"
#include "levelChoiceMenu/levelChoiceMenuConsts.h"
#include "texturing/texturePosition.h"
#include "consts/colors.h"

constexpr char MenuTexts[] = "demosMenu/demosPlayingMenu.txt";

enum : std::size_t{
	TxtTitle,
	TxtPreviousPage,
	TxtNextPage,
	TxtQuitMenu,
	TxtNoDemoAvailable,
	TxtMax
};

constexpr SDL_Color ButtonOffColor = { 128, 128, 128, 255 };

demosPlaying::DemoChoiceMenu::DemoChoiceMenu(Essentials& essentials):
	backgroundImage{ essentials.logs, essentials.rndWnd, "textures/wallpapers/cave1.png", TexturePosition{ 0, 0 } },
	interfaceTexts{ essentials.logs.error, path::getLanguageFile(essentials.chosenLanguage, MenuTexts) },
	font{ essentials.logs.error, ArialFontPath, MediumFontSize },
	demosFilesList{essentials, font, essentials.prefPath.getFsPath() / files::DemosDir, ListOfDemosFilesInDir, ButtonOffColor },
	precedentPageButton{ essentials.logs, essentials.rndWnd, font, interfaceTexts[TxtPreviousPage], levelChoice::SelectedButtonColor, levelChoice::OffButtonColor,
							TexturePosition{ SQR_SIZE * 2, GameScreenHeight - SQR_SIZE, true, true } },
	nextPageButton{ essentials.logs, essentials.rndWnd, font, interfaceTexts[TxtNextPage], levelChoice::SelectedButtonColor, levelChoice::OffButtonColor,
							TexturePosition{ GameScreenWidth - SQR_SIZE * 2, GameScreenHeight - SQR_SIZE, true, true } },
	quitButton{ essentials.logs, essentials.rndWnd, font, interfaceTexts[TxtQuitMenu], levelChoice::SelectedButtonColor, levelChoice::OffButtonColor,
							TexturePosition{ GameScreenWidth - SQR_SIZE * 2, SQR_SIZE, true, true } },
	demosAbsenceInfos{ essentials.logs, essentials.rndWnd, font, interfaceTexts[TxtNoDemoAvailable], RedCol, 
		TexturePosition{ GameScreenWidth / 2, GameScreenHeight / 2, true, true } },
	menuTitle{ essentials.logs, essentials.rndWnd, font, interfaceTexts[TxtTitle], YellowCol, TexturePosition{ GameScreenWidth / 2, SQR_SIZE, true, true } }
{
	
}

void demosPlaying::DemoChoiceMenu::drawInterface(Essentials& essentials) const
{
	backgroundImage.draw(essentials.rndWnd);
	demosFilesList.drawCurrentPage(essentials);
	drawPageButtons(essentials);
	quitButton.drawButton(essentials.rndWnd);
	drawDemosAbsenceInfo(essentials);
	menuTitle.draw(essentials.rndWnd);
}

void demosPlaying::DemoChoiceMenu::drawPageButtons(Essentials& essentials) const
{
	if( demosFilesList.size() >= 2 )
	{
		precedentPageButton.drawButton(essentials.rndWnd);
		nextPageButton.drawButton(essentials.rndWnd);
	}
}

void demosPlaying::DemoChoiceMenu::updateButtons(Essentials& essentials)
{
	quitButton.updateButton(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
	updatePageButtons(essentials);
	updateListPageButtons(essentials);
}

void demosPlaying::DemoChoiceMenu::updateListPageButtons(Essentials& essentials)
{
	if( demosFilesList.size() > 0 )
	{
		demosFilesList.updateCurrentPageButtons(essentials);
	}
}

void demosPlaying::DemoChoiceMenu::updatePageButtons(Essentials& essentials)
{
	if( demosFilesList.size() >= 2 )
	{
		precedentPageButton.updateButton(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
		nextPageButton.updateButton(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
	}
}

void demosPlaying::DemoChoiceMenu::drawDemosAbsenceInfo(Essentials& essentials) const
{
	if( demosFilesList.size() == 0 )
	{
		demosAbsenceInfos.draw(essentials.rndWnd);
	}
}