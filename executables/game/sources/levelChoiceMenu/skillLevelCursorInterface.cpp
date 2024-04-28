#include "levelChoiceMenu/skillLevelCursorInterface.h"
#include "package/essentials.h"
#include "texturing/texturePosition.h"
#include "consts/skillLevelsConsts.h"

SkillLevelCursor::SkillLevelCursor(Essentials& essentials, const TexturePosition& position):
	cursorTrack{essentials.logs, essentials.rndWnd, "textures/gameGUI/skillLevel/skillLevelCursorTrack.png", position },
	cursor{ essentials.logs, essentials.rndWnd, "textures/gameGUI/skillLevel/skillLevelCursor.png", position },
	selectedSkillLevel{ SkillLevelMedium }
{
	
}

void SkillLevelCursor::changeCursorPosition(const Offset& mousePosition, bool mouseButtonState)
{
	if( mouseButtonState )
	{
		if( mousePosition.x >= cursorTrack.sprite.x_pos() && mousePosition.x < cursorTrack.sprite.x_pos() + cursorTrack.sprite.width() 
			&& mousePosition.y >= cursorTrack.sprite.y_pos() && mousePosition.y < cursorTrack.sprite.y_pos() + cursorTrack.sprite.height() )
		{
			setEasySkill(mousePosition);
			setMediumSkill(mousePosition);
			setHardSkill(mousePosition);
		}
	}
}

void SkillLevelCursor::drawEverything(Essentials& essentials) const
{
	cursorTrack.draw(essentials.rndWnd);
	cursor.draw(essentials.rndWnd);
}

unsigned SkillLevelCursor::getSkillLevel() const
{
	return selectedSkillLevel;
}

void SkillLevelCursor::setEasySkill(const Offset& mousePosition)
{
	if( mousePosition.x < cursorTrack.sprite.x_pos() + cursorTrack.sprite.width() / 3 )
	{
		selectedSkillLevel = SkillLevelEasy;
		cursor.sprite.setTexturePosition(TexturePosition{cursorTrack.sprite.x_pos(), cursorTrack.sprite.y_pos(), false, false} );
	}
}

void SkillLevelCursor::setMediumSkill(const Offset& mousePosition)
{
	if( mousePosition.x >= cursorTrack.sprite.x_pos() + cursorTrack.sprite.width() / 3 && mousePosition.x < cursorTrack.sprite.x_pos() + cursorTrack.sprite.width() * 2 / 3 )
	{
		selectedSkillLevel = SkillLevelMedium;
		cursor.sprite.setTexturePosition(TexturePosition{cursorTrack.sprite.x_pos() + cursorTrack.sprite.width() / 2, cursorTrack.sprite.y_pos(), true, false} );
	}
}

void SkillLevelCursor::setHardSkill(const Offset& mousePosition)
{
	if( mousePosition.x >= cursorTrack.sprite.x_pos() + cursorTrack.sprite.width() * 2 / 3 && mousePosition.x < cursorTrack.sprite.x_pos() + cursorTrack.sprite.width() )
	{
		selectedSkillLevel = SkillLevelHard;
		cursor.sprite.setTexturePosition(TexturePosition{cursorTrack.sprite.x_pos() + cursorTrack.sprite.width() - cursor.sprite.width(), cursorTrack.sprite.y_pos(), false, false} );
	}
}