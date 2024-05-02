#ifndef BOB_THE_BLOB_GAME_SKILL_LEVEL_CURSOR_INTERFACE_H
#define BOB_THE_BLOB_GAME_SKILL_LEVEL_CURSOR_INTERFACE_H

#include "texturing/texturesCombo.h"

struct Essentials;
struct TexturePosition;
struct Offset;

class SkillLevelCursor
{
private:
	TextureCombo cursorTrack;
	TextureCombo cursor;
	unsigned selectedSkillLevel;
	
public:
	explicit SkillLevelCursor(Essentials& essentials, const TexturePosition& position);
	~SkillLevelCursor() = default;
	SkillLevelCursor( const SkillLevelCursor& ) = delete;
	SkillLevelCursor& operator= ( const SkillLevelCursor& ) = delete;
	SkillLevelCursor( SkillLevelCursor&& ) = default;
	SkillLevelCursor& operator= ( SkillLevelCursor&& ) = default;
	
	void changeCursorPosition(const Offset& mousePosition, bool mouseButtonState);
	void drawEverything(Essentials& essentials) const;
	unsigned getSkillLevel() const;
	
private:
	void setEasySkill(const Offset& mousePosition);
	void setMediumSkill(const Offset& mousePosition);
	void setHardSkill(const Offset& mousePosition);
};

#endif //BOB_THE_BLOB_GAME_SKILL_LEVEL_CURSOR_INTERFACE_H