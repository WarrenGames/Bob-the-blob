#include "hintsScreen/mexican/mexicanHintScreen.h"
#include "hintsScreen/mexican/mexicanHintsData.h"
#include "package/essentials.h"
#include "consts/includeOptions.h"
#include "consts/colors.h"

void hintScreen::displayMexicanLevelHelp(Essentials& essentials)
{
	MexicanHintsData mexicanHintsData{essentials};
	
	while( false == mexicanHintsData.quitScreen )
	{
		essentials.inputs.updateEvents();
		mexicanHintsData.okButton.updateButton(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
		hintScreen::carryOnToMexicanGame(essentials, mexicanHintsData);
		hintScreen::drawScreenElements(essentials, mexicanHintsData);
	}
}

void hintScreen::carryOnToMexicanGame(Essentials& essentials, MexicanHintsData& mexicanHintsData)
{
	if( mexicanHintsData.okButton.buttonClicked() || essentials.inputs.isKeyDown(KEY_ESCAPE) || essentials.inputs.getSdlQuit() )
	{
		mexicanHintsData.quitScreen = true;
	}
}

void hintScreen::drawScreenElements(Essentials& essentials, const MexicanHintsData& mexicanHintsData)
{
	if( essentials.drawDelay.hasTimeElapsed( std::chrono::microseconds{1000 / 60 * 1000} ) )
	{
		essentials.drawDelay.joinTimePoints();
		essentials.rndWnd.clearScreen(BlackCol);
		mexicanHintsData.drawEverything(essentials);
		essentials.rndWnd.displayRenderer();
	}
}