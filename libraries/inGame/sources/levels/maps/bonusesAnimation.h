#ifndef BOB_THE_BLOB_IN_GAME_BONUSES_ANIMATION_DATA_H
#define BOB_THE_BLOB_IN_GAME_BONUSES_ANIMATION_DATA_H

#include "time/accurateTime.h"

class BonusesAnimationData
{
private:
	std::size_t textureIndex;
	std::size_t texturesNumber;
	AccurateTimeDelay timeDelayMesure;
	std::chrono::milliseconds delay;

public:
	explicit BonusesAnimationData(std::size_t texturesNumber_, unsigned millisecondsDelay_);
	~BonusesAnimationData() = default;
	BonusesAnimationData( const BonusesAnimationData& ) = default;
	BonusesAnimationData& operator= ( const BonusesAnimationData& ) = default;
	
	void animIndex();
	std::size_t getIndex() const;
};

#endif //BOB_THE_BLOB_IN_GAME_BONUSES_ANIMATION_DATA_H