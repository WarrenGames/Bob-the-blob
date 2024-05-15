#ifndef BOB_THE_BLOB_IN_GAME_BONUS_ELEMENT_H
#define BOB_THE_BLOB_IN_GAME_BONUS_ELEMENT_H

#include <cstdlib>

struct BonusElement
{
	std::size_t bonusIndex;
	std::size_t bonusProperty;//Sub category of bonus
	bool isPresent;
	
	explicit BonusElement();
	explicit BonusElement(std::size_t index, std::size_t property);
	~BonusElement() = default;
	BonusElement( const BonusElement& ) = default;
	BonusElement& operator= ( const BonusElement& ) = default;
};

#endif //BOB_THE_BLOB_IN_GAME_BONUS_ELEMENT_H