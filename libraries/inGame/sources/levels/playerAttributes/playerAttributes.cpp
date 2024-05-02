#include "levels/playerAttributes/playerAttributes.h"
#include "consts/skillLevelsConsts.h"
#include <cassert>

PlayerAttributes::PlayerAttributes(unsigned selectedSkillLevel):
	score{ 0 },
	skillLevel{ selectedSkillLevel },
	updateScore{ true }
{
	assert( skillLevel < SkillLevelMax );
}

void PlayerAttributes::addToScore(unsigned add)
{
	score += add;
	updateScore = true;
}