#include "levels/maps/bonusElement.h"
#include "levels/maps/bonusesConsts.h"

BonusElement::BonusElement():
	bonusIndex{ bonuses::BonusMax },
	bonusProperty{0},
	isPresent{false}
{
	
}

BonusElement::BonusElement(std::size_t index, std::size_t property):
	bonusIndex{ index },
	bonusProperty{ property },
	isPresent{ true }
{
	
}