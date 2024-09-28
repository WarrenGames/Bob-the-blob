#ifndef GRAPHICAL_TEXT_PARAGRAPH_DATA_H
#define GRAPHICAL_TEXT_PARAGRAPH_DATA_H

#include "text/sdl2ttf_font.h"
#include "fileSystem/fileSystem.h"
#include <string>
#include <vector>

struct AppLogFiles;

struct ParagraphData
{
	fs::path inputFilePath;
	sdl2::Font font;
	SDL_Color textColor;
	int textWidth;
	std::vector< std::string > paragraphWords;
	
	explicit ParagraphData(AppLogFiles& logs, const fs::path& textFilePath, const std::string& fontPath, unsigned fontSize, const SDL_Color& color, int textWidth_);
	~ParagraphData() = default;
	ParagraphData( const ParagraphData& ) = delete;
	ParagraphData& operator= ( const ParagraphData& ) = delete;
	ParagraphData( ParagraphData&& ) = default;
	ParagraphData& operator= ( ParagraphData&& ) = default;
};


//Is instanciated in 'makeText' namespace functions (you shouldn't create that structure by yourself)
struct ParagraphMakeComponents
{
	std::string correctWords;
	std::string overflowWords;
	std::size_t wordsIndex;
	int currentWidth;
	int currentHeight;
	bool canCreateLine;
	
	ParagraphMakeComponents();
	~ParagraphMakeComponents() = default;
	ParagraphMakeComponents( const ParagraphMakeComponents& ) = delete;
	ParagraphMakeComponents& operator= ( const ParagraphMakeComponents& ) = delete;
	ParagraphMakeComponents( ParagraphMakeComponents&& ) = default;
	ParagraphMakeComponents& operator= ( ParagraphMakeComponents&& ) = default;
	void initializeData(const sdl2::Font& font, const std::vector<std::string>& words);
};

#endif //GRAPHICAL_TEXT_PARAGRAPH_DATA_H