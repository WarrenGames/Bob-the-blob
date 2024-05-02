#ifndef BOB_THE_BLOB_GAME_LEVEL_CHOICE_LEVELS_LISTING_H
#define BOB_THE_BLOB_GAME_LEVEL_CHOICE_LEVELS_LISTING_H

#include "widgets/buttons/textButtonWidget.h"
#include "text/sdl2ttf_font.h"
#include "fileSystem/fileSystem.h"
#include <vector>

struct Essentials;
namespace sdl2{ class Font; }
struct TexturePosition;

struct LevelChunk
{
	TextButton textButton;
	std::string levelName;
	unsigned levelType;
	
	explicit LevelChunk(Essentials& essentials, const sdl2::Font& font, const std::string text, const TexturePosition& position, unsigned levelType_);
	~LevelChunk() = default;
	LevelChunk( const LevelChunk& ) = delete;
	LevelChunk& operator= ( const LevelChunk& ) = delete;
	LevelChunk( LevelChunk&& ) = default;
	LevelChunk& operator= ( LevelChunk&& ) = default;
};

class LevelsListing
{
private:
	std::vector< std::vector< LevelChunk > > levelsList;
	std::size_t listCurrentPage;
	
public:
	explicit LevelsListing(Essentials& essentials, const sdl2::Font& listFont, const fs::path& path);
	~LevelsListing() = default;
	LevelsListing( const LevelsListing& ) = delete;
	LevelsListing& operator= ( const LevelsListing& ) = delete;
	LevelsListing( LevelsListing&& ) = default;
	LevelsListing& operator= ( LevelsListing&& ) = default;
	
	void drawCurrentPage(Essentials& essentials) const;
	void seeNextPageIfAny();
	void seePrecedentPageIfAny();
	void updateCurrentPageButtons(Essentials& essentials);
	std::size_t size() const;
	
	std::vector< LevelChunk >::const_iterator begin() const;
	std::vector< LevelChunk >::const_iterator end() const;
	
private:
	void populateList(Essentials& essentials, const sdl2::Font& listFont, const fs::path& filesList);
	
	void createLevelChunk(Essentials& essentials, const sdl2::Font& listFont, std::istringstream& lineStream, int& levelsNumber, std::size_t fileLineNumber);
	
	void readDirectoryFiles(Essentials& essentials, const sdl2::Font& listFont, const fs::path& initialDirectory);
};

#endif //BOB_THE_BLOB_GAME_LEVEL_CHOICE_LEVELS_LISTING_H