#include "fileDataFetch/fileDataFetch.h"
#include <fstream>

unsigned fileDataFetch::getUnsignedInt(const fs::path& filePath)
{
	if( std::ifstream file{ filePath } )
	{
		unsigned data{0};
		if( file >> data )
		{
			return data;
		}
	}
	return 0;
}