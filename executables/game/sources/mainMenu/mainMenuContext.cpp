#include "mainMenu/mainMenuContext.h"
#include "package/essentials.h"
#include "mainMenu/mainMenuThings.h"
#include "gameOptions/optionsContext.h"
#include "levelChoiceMenu/levelChoiceMenuContext.h"
#include "demoRecordAndRun/play/playDemoContext.h"
#include "demoRecordAndRun/record/recordDemoContext.h"
#include "consts/filesAndPaths.h"
#include "SDL_events.h"

void mainMenu::context(Essentials& essentials)
{
	mainMenu::MenuThings menuThings{essentials};
	
	while( menuThings.quitMenu == false )
	{
		essentials.inputs.updateEvents();
		update(essentials, menuThings);
		mainMenu::runLevelChoiceMenu(essentials, menuThings);
		mainMenu::runDemoRecording(essentials, menuThings);
		mainMenu::runDemoPlaying(essentials, menuThings);
		mainMenu::runOptionsMenu(essentials, menuThings);
		mainMenu::quitMenu(essentials, menuThings);
		drawEverything(essentials, menuThings);
		essentials.inputs.setMouseButtonFalse(SDL_BUTTON_LEFT);
	}
	
}

void mainMenu::update(Essentials& essentials, MenuThings& menuThings)
{
	menuThings.updateButtons(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
}

void mainMenu::drawEverything(Essentials& essentials, const MenuThings& menuThings)
{
	if( essentials.drawDelay.hasTimeElapsed(std::chrono::milliseconds{16} ) )
	{
		essentials.drawDelay.joinTimePoints();
		menuThings.drawEverything(essentials);
		essentials.rndWnd.displayRenderer();
	}
}

void mainMenu::runLevelChoiceMenu(Essentials& essentials, const MenuThings& menuThings)
{
	if( menuThings.levelChoice.buttonClicked() )
	{
		essentials.inputs.setMouseButtonFalse(SDL_BUTTON_LEFT);
		levelChoice::mainContext(essentials);
	}
}

void mainMenu::runDemoRecording(Essentials& essentials, const MenuThings& menuThings)
{
	if( menuThings.recordDemo.buttonClicked() )
	{
		essentials.inputs.setMouseButtonFalse(SDL_BUTTON_LEFT);
		demosRecording::mainContext(essentials);
	}
}

void mainMenu::runDemoPlaying(Essentials& essentials, const MenuThings& menuThings)
{
	if( menuThings.playDemo.buttonClicked() )
	{
		essentials.inputs.setMouseButtonFalse(SDL_BUTTON_LEFT);
		demosPlaying::demoChoice(essentials);
	}
}

void mainMenu::runOptionsMenu(Essentials& essentials, const MenuThings& menuThings)
{
	if( menuThings.optionsMenu.buttonClicked() )
	{
		options::context(essentials);
	}
}

void mainMenu::quitMenu(Essentials& essentials, MenuThings& menuThings)
{
	if( essentials.inputs.getSdlQuit() || essentials.inputs.isKeyDown(KEY_ESCAPE) )
	{
		menuThings.quitMenu = true;
	}
}