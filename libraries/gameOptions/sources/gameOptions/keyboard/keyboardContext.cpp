#include "gameOptions/keyboard/keyboardContext.h"
#include "gameOptions/keyboard/keyboardOptions.h"
#include "package/essentials.h"
#include "consts/screenConsts.h"

void options::keyboardMainContext(Essentials& essentials)
{
	KeyboardOptions keyboardOptions{essentials};
	const TextureCombo background{essentials.logs, essentials.rndWnd, "textures/wallpapers/optionsScreen.png"};
	bool quitMenu{false};
	
	while( false == quitMenu )
	{
		essentials.inputs.updateEvents();
		keyboardOptions.updateButtons(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
		keyboardOptions.updateKeycodeWithUser(essentials.logs, essentials.rndWnd);
		options::quitKeyboardMenuContext(essentials, quitMenu);
		options::drawKeyboardMenuContext(essentials, keyboardOptions, background);
		essentials.inputs.setMouseButtonFalse(SDL_BUTTON_LEFT);
	}
	keyboardOptions.recordModificationsToFiles(essentials);
}

void options::quitKeyboardMenuContext(Essentials& essentials, bool& quitMenu)
{
	if( essentials.inputs.getSdlQuit() || essentials.inputs.isKeyDown(KEY_ESCAPE) )
	{
		quitMenu = true;
		essentials.inputs.setKeyStateToFalse(KEY_ESCAPE);
	}
}

void options::drawKeyboardMenuBackground(Essentials& essentials, const TextureCombo& background)
{
	background.draw(essentials.rndWnd);
}

void options::drawKeyboardMenuContext(Essentials& essentials, const KeyboardOptions& keyboardOptions, const TextureCombo& background)
{
	if( essentials.drawDelay.hasTimeElapsed( essentials.microSecondsDelay ) )
	{
		essentials.drawDelay.joinTimePoints();
		options::drawKeyboardMenuBackground(essentials, background);
		keyboardOptions.drawEverything(essentials.rndWnd);
		essentials.rndWnd.displayRenderer();
	}
}