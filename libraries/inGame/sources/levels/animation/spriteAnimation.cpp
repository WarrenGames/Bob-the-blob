#include "levels/animation/spriteAnimation.h"

SpriteAnimation::SpriteAnimation(std::size_t framesNumber, const std::chrono::milliseconds& animDelay):
	currentFrame{ 0 },
	maxFrame{ framesNumber },
	delay{ animDelay }
{
	
}

void SpriteAnimation::changeCurrentFrameWithBasicAnim()
{
	if( delayMeasure.hasTimeElapsed( delay ) )
	{
		if( currentFrame + 1 < maxFrame )
		{
			currentFrame++;
		}
		else{
			currentFrame = 0;
		}
		delayMeasure.joinTimePoints();
	}
}

std::size_t SpriteAnimation::getCurrentFrame() const
{
	return currentFrame;
}

void SpriteAnimation::backAndForthAnimation()
{
	if( delayMeasure.hasTimeElapsed(delay) )
	{
		if( isAnimationForward )
		{
			forwardAnimation();
		}
		else{
			backwardAnimation();
		}
		delayMeasure.joinTimePoints();
	}
}

void SpriteAnimation::forwardAnimation()
{
	if( currentFrame + 1 < maxFrame )
	{
		currentFrame++;
	}
	else{
		isAnimationForward = false;
	}
}

void SpriteAnimation::backwardAnimation()
{
	if( currentFrame > 0 )
	{
		currentFrame--;
	}
	else{
		isAnimationForward = true;
	}
}