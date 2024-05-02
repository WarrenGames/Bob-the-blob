#include "levels/textures/drawing/explosionInfos.h"

ExplosionInfos::ExplosionInfos(bool playStatus, unsigned frameMillisDuration):
	frameNumber{ 0 },
	frameDuration{ frameMillisDuration },
	canPlayExplosion{ playStatus }
{
	
}

bool ExplosionInfos::isExplosionActive()
{
	return canPlayExplosion;
}

std::size_t ExplosionInfos::getCurrentFrame() const
{
	return frameNumber;
}

void ExplosionInfos::incrementFrame(std::size_t totalFrameNumber)
{
	if( animationTime.hasTimeElapsed( frameDuration ) )
	{
		animationTime.joinTimePoints();
		if( frameNumber + 1 < totalFrameNumber )
		{
			frameNumber++;
		}
		else{
			frameNumber = 0;
			canPlayExplosion = false;
		}
	}
}

void ExplosionInfos::resetExplosionDisplay()
{
	canPlayExplosion = true;
	frameNumber = 0;
}