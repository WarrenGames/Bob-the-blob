#include "gameOptions/inputs/inputsInterface/inputsContext.h"
#include "gameOptions/inputs/inputsInterface/globalInterface.h"
#include "package/essentials.h"
#include "joystickContexts/joystickInfosInterface.h"
#include "pathsFunctions/pathsFunctions.h"
#include "gameOptions/consts/optionsConsts.h"
#include "consts/screenConsts.h"

void options::inputsMainContext(Essentials& essentials)
{
	options::InputsGlobalInterface interface{essentials};
	bool quitMenu{false};
	
	while( false == quitMenu )
	{
		essentials.inputs.updateEvents();
		interface.updateButtons(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
		interface.updateKeycodeWithUser(essentials);
		interface.updateJoystickConfig(essentials, essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
		options::quitInputsMenuContext(essentials, quitMenu);
		options::seeJoystickConfiguration(essentials, interface);
		options::runJoystickCalibration(essentials, interface);
		options::drawInputsMenuContext(essentials, interface);
		essentials.inputs.setMouseButtonFalse(SDL_BUTTON_LEFT);
	}
	interface.recordModificationsToFile(essentials);
}

void options::quitInputsMenuContext(Essentials& essentials, bool& quitMenu)
{
	if( essentials.inputs.getSdlQuit() || essentials.inputs.isKeyDown(KEY_ESCAPE) )
	{
		quitMenu = true;
		essentials.inputs.setKeyStateToFalse(KEY_ESCAPE);
	}
}

void options::drawInputsMenuContext(Essentials& essentials, const options::InputsGlobalInterface& optionsData)
{
	if( essentials.drawDelay.hasTimeElapsed( essentials.microSecondsDelay ) )
	{
		essentials.drawDelay.joinTimePoints();
		optionsData.drawEverything(essentials.rndWnd);
		essentials.rndWnd.displayRenderer();
	}
}

void options::seeJoystickConfiguration(Essentials& essentials, const options::InputsGlobalInterface& optionsData)
{
	if( optionsData.joystickInfosButton.buttonClicked() )
	{
		joyElementView::mainContext(essentials.logs, essentials.rndWnd, optionsData.arialFont, path::getLanguageFile(essentials.chosenLanguage, options::JoystickElementsTextsPath),
									optionsData.joystickEntity, SQR_SIZE );
	}
}

void options::runJoystickCalibration(Essentials& essentials, const options::InputsGlobalInterface& optionsData)
{
	if( optionsData.joystickCalibrate.buttonClicked() )
	{
		joyCalibrate::mainContext(essentials.logs, essentials.rndWnd, optionsData.arialFont, path::getLanguageFile(essentials.chosenLanguage, options::JoyCalibrationTextsPath),
									SQR_SIZE );
	}
}