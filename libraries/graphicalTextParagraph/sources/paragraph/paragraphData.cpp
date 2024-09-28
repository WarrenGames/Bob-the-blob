#include "paragraph/paragraphData.h"
#include "logging/logsStruct.h"

ParagraphData::ParagraphData(AppLogFiles& logs, const fs::path& textFilePath, const std::string& fontPath, unsigned fontSize, const SDL_Color& color, int textWidth_):
	inputFilePath{ textFilePath },
	font{ logs.error, fontPath, fontSize },
	textColor{ color },
	textWidth{ textWidth_ }
{
	
}

ParagraphMakeComponents::ParagraphMakeComponents():
	correctWords{},
	overflowWords{},
	wordsIndex{0},
	currentWidth{0},
	currentHeight{0},
	canCreateLine{false}
{

}

void ParagraphMakeComponents::initializeData(const sdl2::Font& font, const std::vector<std::string>& words)
{
	overflowWords = words[wordsIndex];
	correctWords.clear();
	TTF_SizeUTF8(font.get(), overflowWords.c_str(), &currentWidth, &currentHeight);
	canCreateLine = true;
}