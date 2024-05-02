#include "pathsFunctions/getLanguageFromFile.h"
#include "logging/logsStruct.h"
#include "consts/filesAndPaths.h"

std::string getChosenLanguageFromFile(AppLogFiles& logs, const fs::path& filePath)
{
	if( std::ifstream file{ filePath } )
	{
		std::string line;
		if( file >> line )
		{
			return line;
		}
		else{
			logs.error << "Error: the file: '" << filePath.string() << "' has been open but reading it for 'language choice' failed.\n";
		}
	}
	else{
		logs.error.wrFileOpeningError(filePath, "language choice");
	}
	return std::string{ files::DefaultLanguage };
}