#include "levels/playerAttributes/playerAttributes.h"

PlayerAttributes::PlayerAttributes():
	score{ 0 },
	updateScore{ true }
{
	
}

void PlayerAttributes::addToScore(unsigned add)
{
	score += add;
	updateScore = true;
}