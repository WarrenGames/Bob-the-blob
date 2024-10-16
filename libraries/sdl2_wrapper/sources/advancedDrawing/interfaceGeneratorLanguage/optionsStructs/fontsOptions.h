#ifndef INTERFACE_GENERATOR_LANGUAGE_FONTS_OPTIONS_H
#define INTERFACE_GENERATOR_LANGUAGE_FONTS_OPTIONS_H

#include "fileSystem/fileSystem.h"
#include <string>

namespace igl{

namespace font{
	
	struct Description
	{
		fs::path scriptFilePath;
		std::string fileLine;
		std::string identifier;
		fs::path fontPath;
		int fontSize;
		unsigned fileLineNumber;
		int squareSize;
		bool isLoadingPerfect;
		
		explicit Description(const fs::path& toOpenFile, int squareSize_);
		~Description() = default;
		Description( const Description& ) = delete;
		Description& operator= ( const Description& ) = delete;
		Description( Description&& ) = default;
		Description& operator= ( Description&& ) = default;
		
	};

}

}

#endif //INTERFACE_GENERATOR_LANGUAGE_FONTS_OPTIONS_H