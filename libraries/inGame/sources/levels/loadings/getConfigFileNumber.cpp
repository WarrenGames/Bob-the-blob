#include "levels/loadings/getConfigFileNumber.h"
#include "exceptions/readErrorExcept.h"
#include <fstream>

unsigned getUnsignedIntFromFile(const fs::path& filePath, const std::string& purpose)
{
	if( std::ifstream file{ filePath } )
	{
		unsigned data{0};
		if( file >> data )
		{
			return data;
		}
		else{
			throw ReadError{"The file '" + filePath.string() + "' has been open, but reading data for " + purpose + " failed."};
		}
	}
	else{
		throw ReadError{"The file '" + filePath.string() + "' couldn't be open for " + purpose + " ."};
	}
}