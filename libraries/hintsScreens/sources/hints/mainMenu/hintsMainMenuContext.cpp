#include "hints/mainMenu/hintsMainMenuContext.h"
#include "hints/mainMenu/hintsMainMenuElements.h"
#include "hints/fleeFoes/fleeFoesHintScreenContext.h"
#include "package/essentials.h"
#include "consts/colors.h"

void hintsScreens::mainMenuContext(Essentials& essentials)
{
	bool quitMenu{ false };
	hintsScreens::MainMenu mainMenu{ essentials };
	
	while( false == quitMenu )
	{
		essentials.inputs.updateEvents();
		mainMenu.updateEvents(essentials);
		hintsScreens::quitMenu(essentials, quitMenu);
		hintsScreens::runFleeEnemyMenu(essentials, mainMenu);
		hintsScreens::drawEverything(essentials, mainMenu);
		essentials.inputs.setMouseButtonFalse(SDL_BUTTON_LEFT);
		essentials.inputs.setKeyStateToFalse(KEY_ESCAPE);
	}
}

void hintsScreens::quitMenu(Essentials& essentials, bool& quitMenu)
{
	if( essentials.inputs.getSdlQuit() || essentials.inputs.isKeyDown(KEY_ESCAPE) )
	{
		quitMenu = true;
	}
}

void hintsScreens::runFleeEnemyMenu(Essentials& essentials, hintsScreens::MainMenu& mainMenuElements)
{
	if( mainMenuElements.escapeEnemyMenuButton.buttonClicked() )
	{
		essentials.inputs.setMouseButtonFalse(SDL_BUTTON_LEFT);
		hintsScreens::fleeFoes::screenContext(essentials);
	}
}

void hintsScreens::drawEverything(Essentials& essentials, hintsScreens::MainMenu& mainMenuElements)
{
	essentials.rndWnd.clearScreen( BlackCol );
	mainMenuElements.drawEverything(essentials);
	essentials.rndWnd.displayRenderer();
}