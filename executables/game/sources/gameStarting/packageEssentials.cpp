#include "gameStarting/packageEssentials.h"
#include "miniScreenStart/miniScreenStartContext.h"
#include "sdlLogoDisplay/logoDispContext.h"
#include "mainMenu/mainMenuContext.h"
#include "pathsFunctions/pathsFunctions.h"
#include "package/essentials.h"
#include "consts/filesAndPaths.h"
#include "consts/fontsSizes.h"
#include "consts/screenConsts.h"
#include "consts/colors.h"

void packageEssentials(const PrefPathFinder& prefPath, AppLogFiles& logs, sdl2::RendererWindow& rndWnd)
{
	Essentials essentials{logs, prefPath, rndWnd};
	bool quitGame{false};
	
	gameStarting::context(essentials, quitGame);
	
	if( false == quitGame )
	{
		essentials.rndWnd.changeScreenDefinition(GameScreenWidth, GameScreenHeight);
		essentials.rndWnd.centerWindow();
		
		logoDisplay::mainContext(logs, rndWnd, path::getPrefPathFilePath(prefPath, files::SdlLogoDisplayStatusFile), 
								path::getLanguageFile( essentials.chosenLanguage, files::SdlLogoDisplayLanguageFile),
								MediumFontSize, SQR_SIZE );
		essentials.rndWnd.clearScreen(BlackCol);
		mainMenu::context(essentials);
	}
}