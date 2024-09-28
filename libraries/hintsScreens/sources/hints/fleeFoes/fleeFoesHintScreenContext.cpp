#include "hints/fleeFoes/fleeFoesHintScreenContext.h"
#include "hints/fleeFoes/fleeFoesHintScreenElements.h"
#include "package/essentials.h"
#include "consts/colors.h"

void hintsScreens::fleeFoes::screenContext(Essentials& essentials)
{
	hintsScreens::FleeFoes fleeFoes{essentials};
	bool quit{false};
	
	while( false == quit )
	{
		essentials.inputs.updateEvents();
		hintsScreens::fleeFoes::quitScreen(essentials, quit);
		hintsScreens::fleeFoes::drawEverything(essentials, fleeFoes);
	}
	essentials.inputs.setKeyStateToFalse(KEY_ESCAPE);
}

void hintsScreens::fleeFoes::drawEverything(Essentials& essentials, hintsScreens::FleeFoes& fleeFoes)
{
	if( essentials.drawDelay.hasTimeElapsed( essentials.microSecondsDelay ) )
	{
		essentials.drawDelay.joinTimePoints();
		essentials.rndWnd.clearScreen(BlackCol);
		fleeFoes.drawEverything(essentials);
		essentials.rndWnd.displayRenderer();
	}
}

void hintsScreens::fleeFoes::quitScreen(Essentials& essentials, bool& quit)
{
	if( essentials.inputs.getSdlQuit() || essentials.inputs.isKeyDown(KEY_ESCAPE) )
	{
		quit = true;
	}
}