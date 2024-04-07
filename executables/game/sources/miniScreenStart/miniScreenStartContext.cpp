#include "miniScreenStart/miniScreenStartContext.h"
#include "miniScreenStart/miniScreenStartMenu.h"
#include "package/essentials.h"

void gameStarting::context(Essentials& essentials, bool& quitGame)
{
	if( const gameStarting::MiniScreenMenu miniScreenMenu{essentials} )
	{
		gameStarting::contextLoop(essentials, miniScreenMenu, quitGame);
	}
	else{
		essentials.logs.error << "Something wrong happened while trying to load mini screen game graphisms.\n";
		quitGame = true;
	}
}

void gameStarting::contextLoop(Essentials& essentials, const gameStarting::MiniScreenMenu& miniScreenMenu, bool& quitGame)
{
	bool quitMenu{false};
	while( false == quitMenu )
	{
		essentials.inputs.updateEvents();
		gameStarting::userChooseFullScreenMode(essentials, quitMenu);
		gameStarting::userChooseWindowedScreenMode(essentials, quitMenu);
		gameStarting::userExitGame(essentials, quitGame, quitMenu);
		gameStarting::drawMiniScreen(essentials, miniScreenMenu);
		SDL_Delay(16);
	}
}

void gameStarting::userChooseFullScreenMode(Essentials& essentials, bool& quitMenu)
{
	if( essentials.inputs.isKeyDown(KEY_F1) )
	{
		essentials.rndWnd.setWindowFullScreen(true);
		quitMenu = true;
	}
}

void gameStarting::userChooseWindowedScreenMode(Essentials& essentials, bool& quitMenu)
{
	if( essentials.inputs.isKeyDown(KEY_F5) )
	{
		essentials.rndWnd.setWindowFullScreen(false);
		quitMenu = true;
	}
}

void gameStarting::userExitGame(Essentials& essentials, bool& quitGame, bool& quitMenu)
{
	if( essentials.inputs.isKeyDown(KEY_ESCAPE) || essentials.inputs.getSdlQuit() )
	{
		quitGame = true;
		quitMenu = true;
	}
}

void gameStarting::drawMiniScreen(Essentials& essentials, const gameStarting::MiniScreenMenu& miniScreenMenu)
{
	miniScreenMenu.drawEverything(essentials);
	essentials.rndWnd.displayRenderer();
}