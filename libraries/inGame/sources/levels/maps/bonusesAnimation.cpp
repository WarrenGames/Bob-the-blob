#include "levels/maps/bonusesAnimation.h"

BonusesAnimationData::BonusesAnimationData(std::size_t texturesNumber_, unsigned millisecondsDelay_):
	textureIndex{0},
	texturesNumber{ texturesNumber_ },
	delay{ millisecondsDelay_ }
{
	
}

void BonusesAnimationData::animIndex()
{
	if( texturesNumber >= 2 )
	{
		if( timeDelayMesure.hasTimeElapsed( delay ) )
		{
			timeDelayMesure.joinTimePoints();
			if( textureIndex + 1 < texturesNumber )
			{
				textureIndex++;
			}
			else{
				textureIndex = 0;
			}
		}
	}
}

std::size_t BonusesAnimationData::getIndex() const
{
	return textureIndex;
}