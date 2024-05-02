#include "levels/textures/mappingTextures/mappingTextures.h"
#include "logging/logsStruct.h"
#include <string>
#include <fstream>
#include <algorithm>

MappingTextures::MappingTextures(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const fs::path& texturesListFile):
	isLoadingPerfect{true}
{
	openMainFile(logs, rndWnd, texturesListFile);
}

bool MappingTextures::wasLoadingPerfect() const
{
	return std::all_of( std::cbegin( textures ), std::cend( textures ), [](auto const &pack){ return pack.wasLoadingPerfect(); } );
}

std::vector< TexturesFilesList >::const_iterator MappingTextures::begin() const
{
	return textures.cbegin();
}

std::vector< TexturesFilesList >::const_iterator MappingTextures::end() const
{
	return textures.cend();
}

void MappingTextures::openMainFile(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const fs::path& texturesListFile)
{
	if( std::ifstream listFile{ texturesListFile } )
	{
		std::string listFileLine;
		while( std::getline( listFile, listFileLine ) )
		{
			textures.emplace_back( TexturesFilesList{ logs, rndWnd, listFileLine } );
		}
	}
	else{
		logs.error << "Error: couldn't load '" << texturesListFile.string() << "' main textures list file.\n";
		isLoadingPerfect = false;
	}
}