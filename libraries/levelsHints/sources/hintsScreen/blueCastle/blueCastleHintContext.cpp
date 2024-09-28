#include "hintsScreen/blueCastle/blueCastleHintContext.h"
#include "hintsScreen/blueCastle/blueCastleHintsData.h"
#include "package/essentials.h"
#include "consts/colors.h"

void hintScreen::displayBlueCastleLevelHelp(Essentials& essentials)
{
	BlueCastleHintsScreen blueCastleHintsScreen{essentials};
	
	while( false == blueCastleHintsScreen.quitScreen )
	{
		essentials.inputs.updateEvents();
		blueCastleHintsScreen.okButton.updateButton(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
		hintScreen::carryOnToBlueCastleGame(essentials, blueCastleHintsScreen);
		hintScreen::drawBlueCastleScreenElements(essentials, blueCastleHintsScreen);
	}
}

void hintScreen::carryOnToBlueCastleGame(Essentials& essentials, BlueCastleHintsScreen& blueCastleHintsScreen)
{
	if( blueCastleHintsScreen.okButton.buttonClicked() || essentials.inputs.isKeyDown(KEY_ESCAPE) || essentials.inputs.getSdlQuit() )
	{
		blueCastleHintsScreen.quitScreen = true;
	}
}

void hintScreen::drawBlueCastleScreenElements(Essentials& essentials, const BlueCastleHintsScreen& blueCastleHintsScreen)
{
	if( essentials.drawDelay.hasTimeElapsed( std::chrono::microseconds{1000 / 60 * 1000} ) )
	{
		essentials.drawDelay.joinTimePoints();
		essentials.rndWnd.clearScreen(BlackCol);
		blueCastleHintsScreen.drawEverything(essentials);
		essentials.rndWnd.displayRenderer();
	}
}
