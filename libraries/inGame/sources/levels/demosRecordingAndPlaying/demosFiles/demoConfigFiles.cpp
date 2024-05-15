#include "levels/demosRecordingAndPlaying/demosFiles/demoConfigFiles.h"
#include "logging/logsStruct.h"

std::size_t demos::fetchStackReservedSize(AppLogFiles& logs, const fs::path& filePath)
{
	if( std::ifstream demoConfigFile{ filePath } )
	{
		logs.warning << "The file: '" << filePath.string() << "' was opened with success in order to load demo reserved stack size.\n";
		std::size_t readSize{0};
		
		if( demoConfigFile >> readSize )
		{
			logs.warning << "The stack size in the '" << filePath.string() << "' file is " << readSize << " .\n";
			return readSize;
		}
		else{
			logs.error.wrReadErrorMessage(filePath, "demo reserved stack size"); 
			return 0;
		}
	}
	else{
		logs.error.wrFileOpeningError(filePath, "load demo reserved stack size");
		return 0;
	}
}