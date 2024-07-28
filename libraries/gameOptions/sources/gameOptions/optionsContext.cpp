#include "gameOptions/optionsContext.h"
#include "gameOptions/mainMenu/optionsMainMenuGraphisms.h"
#include "gameOptions/inputs/inputsInterface/inputsContext.h"
#include "gameOptions/gameSettings/gameSettingsContext.h"
#include "package/essentials.h"
#include "consts/colors.h"

void options::context(Essentials& essentials)
{
	options::MainMenuGraphisms mainMenuGraphisms{essentials};
	bool quitOptions{false};
	
	while( false == quitOptions )
	{
		essentials.inputs.updateEvents();
		mainMenuGraphisms.update(essentials);
		options::quitMenuWithEscape(essentials, quitOptions);
		options::closeWindowAsked(essentials, quitOptions);
		options::goToInputsPanel(essentials, mainMenuGraphisms);
		options::goToSettingsPanel(essentials, mainMenuGraphisms);
		options::drawOptionsMenu(essentials, mainMenuGraphisms);
		essentials.inputs.setMouseButtonFalse(SDL_BUTTON_LEFT);
	}
}

void options::drawOptionsMenu(Essentials& essentials, const options::MainMenuGraphisms& mainMenuGraphisms)
{
	if( essentials.drawDelay.hasTimeElapsed( essentials.microSecondsDelay ) )
	{
		essentials.drawDelay.joinTimePoints();
		essentials.rndWnd.clearScreen( BlackCol );
		mainMenuGraphisms.drawEverything(essentials);
		essentials.rndWnd.displayRenderer();
	}
}

void options::quitMenuWithEscape(Essentials& essentials, bool& quitMenu)
{
	if( essentials.inputs.isKeyDown(KEY_ESCAPE) )
	{
		quitMenu = true;
		essentials.inputs.setKeyStateToFalse(KEY_ESCAPE);
	}
}

void options::closeWindowAsked(Essentials& essentials, bool& quitMenu)
{
	if( essentials.inputs.getSdlQuit() )
	{
		quitMenu = true;
	}
}

void options::goToInputsPanel(Essentials& essentials, const options::MainMenuGraphisms& mainMenuGraphisms)
{
	if( mainMenuGraphisms.inputsButton.buttonClicked() )
	{
		essentials.inputs.setMouseButtonFalse(SDL_BUTTON_LEFT);
		options::inputsMainContext(essentials);
		essentials.inputs.setMouseButtonFalse(SDL_BUTTON_LEFT);
	}
}

void options::goToSettingsPanel(Essentials& essentials, const options::MainMenuGraphisms& mainMenuGraphisms)
{
	if( mainMenuGraphisms.settingsButton.buttonClicked() )
	{
		essentials.inputs.setMouseButtonFalse(SDL_BUTTON_LEFT);
		options::settings::mainContext(essentials);
		essentials.inputs.setMouseButtonFalse(SDL_BUTTON_LEFT);
	}
}