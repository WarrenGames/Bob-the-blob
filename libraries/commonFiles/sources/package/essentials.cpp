#include "package/essentials.h"
#include "pathsFunctions/pathsFunctions.h"
#include "pathsFunctions/getLanguageFromFile.h"
#include "consts/filesAndPaths.h"

Essentials::Essentials(AppLogFiles& logs_, const PrefPathFinder& prefPath_, sdl2::RendererWindow& rndWnd_):
	microSecondsDelay{ 1000 * 1000 / 60 },
	rndWnd{ rndWnd_ },
	prefPath{ prefPath_ },
	logs{ logs_ },
	chosenLanguage{ getChosenLanguageFromFile( logs_, path::getPrefPathFilePath( prefPath_, files::ChosenLanguageFile ) ) } 
{
	
}