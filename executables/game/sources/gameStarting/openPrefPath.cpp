#include "gameStarting/openPrefPath.h"
#include "gameStarting/openLogsFiles.h"
#include "prefPath/prefPathFinder.h"
#include "consts/gameConsts.h"
#include "consts/includeOptions.h"
#include <iostream>

void openPrefPath()
{
	if( const PrefPathFinder prefPath{CompanyName, GameName, SQR_SIZE} )
	{
		openLogsFiles(prefPath);
	}
	else{
		std::cout << "Error: couldn't open pref Path with SDL 2, because: " << prefPath.getError() << "\n";
	}
}