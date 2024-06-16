#include "gameOptions/gameSettings/gameSettingsContext.h"
#include "gameOptions/gameSettings/gameSettingsInterface.h"
#include "package/essentials.h"
#include "consts/colors.h"

void options::settings::mainContext(Essentials& essentials)
{
	options::settings::Interface settingsInterface{essentials};
	bool quitMenu{false};
	
	while( false == quitMenu )
	{
		essentials.inputs.updateEvents();
		settingsInterface.updateInterface(essentials);
		options::settings::quitContext(essentials, settingsInterface, quitMenu);
		options::settings::drawEverything(essentials, settingsInterface);
		essentials.inputs.setMouseButtonFalse(SDL_BUTTON_LEFT);
	}
	settingsInterface.saveOptionsToFiles(essentials);
}

void options::settings::drawEverything(Essentials& essentials, const options::settings::Interface& settingsInterface)
{
	if( essentials.drawDelay.hasTimeElapsed( essentials.microSecondsDelay ) )
	{
		essentials.drawDelay.joinTimePoints();
		essentials.rndWnd.clearScreen( BlackCol );
		settingsInterface.drawInterface(essentials);
		essentials.rndWnd.displayRenderer();
	}
}

void options::settings::quitContext(Essentials& essentials, const options::settings::Interface& settingsInterface, bool& quitMenu)
{
	if( essentials.inputs.getSdlQuit() || essentials.inputs.isKeyDown(KEY_ESCAPE) || settingsInterface.quitMenuButton.buttonClicked() )
	{
		quitMenu = true;
		essentials.inputs.setKeyStateToFalse(KEY_ESCAPE);
	}
}