#include "gameStarting/openLogsFiles.h"
#include "setupFiles/createFoldersInPrefPath.h"
#include "gameStarting/initializeSDL_Modules.h"
#include "prefPath/prefPathFinder.h"
#include "logging/logsStruct.h"
#include "consts/gameConsts.h"

void openLogsFiles(const PrefPathFinder& prefPath)
{
	if( AppLogFiles logs{ prefPath.getFsPath(), ErrorFileName, WarningFileName } )
	{
		filesSetup::setupFiles(prefPath, logs);
		initializeSDL_Modules(prefPath, logs);
	}
}