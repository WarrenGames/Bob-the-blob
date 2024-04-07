#ifndef BOB_THE_BLOB_COMMON_FILES_PACKAGE_ESSENTIALS_H
#define BOB_THE_BLOB_COMMON_FILES_PACKAGE_ESSENTIALS_H

#include "texturing/rendererWindow.h"
#include "prefPath/prefPathFinder.h"
#include "logging/logsStruct.h"
#include "time/accurateTime.h"
#include "package/inputs.h"

struct Essentials
{
	AccurateTimeDelay drawDelay;
	std::chrono::microseconds microSecondsDelay;
	sdl2::RendererWindow& rndWnd;
	const PrefPathFinder& prefPath;
	AppLogFiles& logs;
	Inputs inputs;
	const std::string chosenLanguage;
	
	explicit Essentials(AppLogFiles& logs_, const PrefPathFinder& prefPath_, sdl2::RendererWindow& rndWnd_);
	~Essentials() = default;
	Essentials( const Essentials& ) = delete;
	Essentials& operator= ( const Essentials& ) = delete;
	Essentials( Essentials&& ) = default;
	Essentials& operator= ( Essentials&& ) = default;
};

#endif //BOB_THE_BLOB_COMMON_FILES_PACKAGE_ESSENTIALS_H