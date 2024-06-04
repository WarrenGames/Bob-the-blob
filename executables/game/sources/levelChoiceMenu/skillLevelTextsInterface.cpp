#include "levelChoiceMenu/skillLevelTextsInterface.h"
#include "package/essentials.h"
#include "pathsFunctions/pathsFunctions.h"
#include "texturing/texturePosition.h"
#include "levelChoiceMenu/levelChoiceMenuConsts.h"
#include "consts/screenConsts.h"
#include "consts/skillLevelsConsts.h"
#include "consts/fontsSizes.h"
#include "consts/colors.h"
#include <cassert>

SkillLevelTextsInterface::SkillLevelTextsInterface(Essentials& essentials, const TexturePosition& texturePosition, const SDL_Color& textsColor):
	skillLevelsEnum{ essentials.logs.error, path::getLanguageFile(essentials.chosenLanguage, levelChoice::SkillLevelsTextsEnum), SkillLevelMax },
	listFont{ essentials.logs.error, ArialFontPath, MediumFontSize }
{
	for( auto const &txt : skillLevelsEnum )
	{
		skillsTexts.emplace_back( TextureCombo{essentials.logs, essentials.rndWnd, listFont, txt, textsColor, texturePosition } );
	}
}

void SkillLevelTextsInterface::drawSelectedSkill(Essentials& essentials, unsigned skillLevel) const
{
	assert( skillLevel < skillsTexts.size() );
	skillsTexts[skillLevel].draw( essentials.rndWnd );
}