#ifndef BOB_THE_BLOB_GAME_SKILL_LEVELS_TEXTS_INTERFACE_H
#define BOB_THE_BLOB_GAME_SKILL_LEVELS_TEXTS_INTERFACE_H

#include "texturing/texturesCombo.h"
#include "text/sdl2ttf_font.h"
#include "texts/textLoader.h"

struct Essentials;
struct TexturePosition;

class SkillLevelTextsInterface
{
private:
	const TextsBlocks skillLevelsEnum;
	const sdl2::Font listFont;
	std::vector< TextureCombo > skillsTexts;

public:
	explicit SkillLevelTextsInterface(Essentials& essentials, const TexturePosition& texturePosition, const SDL_Color& textsColor);
	~SkillLevelTextsInterface() = default;
	SkillLevelTextsInterface( const SkillLevelTextsInterface& ) = delete;
	SkillLevelTextsInterface& operator= ( const SkillLevelTextsInterface& ) = delete;
	SkillLevelTextsInterface( SkillLevelTextsInterface&& ) = default;
	SkillLevelTextsInterface& operator= ( SkillLevelTextsInterface&& ) = default;
	
	void drawSelectedSkill(Essentials& essentials, unsigned skillLevel) const;
};

#endif //BOB_THE_BLOB_GAME_SKILL_LEVELS_TEXTS_INTERFACE_H