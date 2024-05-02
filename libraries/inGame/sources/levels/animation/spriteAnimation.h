#ifndef BOB_THE_BLOB_IN_GAME_SPRITE_ANIMATION_H
#define BOB_THE_BLOB_IN_GAME_SPRITE_ANIMATION_H

#include "time/accurateTime.h"
#include <cstdlib>

class SpriteAnimation
{
private:
	std::size_t currentFrame;
	std::size_t maxFrame;
	AccurateTimeDelay delayMeasure;
	std::chrono::milliseconds delay;
	bool isAnimationForward;

public:
	explicit SpriteAnimation(std::size_t framesNumber, const std::chrono::milliseconds& animDelay);
	~SpriteAnimation() = default;
	SpriteAnimation( const SpriteAnimation& ) = delete;
	SpriteAnimation& operator= ( const SpriteAnimation& ) = delete;
	SpriteAnimation( SpriteAnimation&& ) = default;
	SpriteAnimation& operator= ( SpriteAnimation&& ) = default;
	
	void changeCurrentFrameWithBasicAnim();
	void backAndForthAnimation();
	
	std::size_t getCurrentFrame() const;

private:
	void forwardAnimation();
	void backwardAnimation();
};

#endif //BOB_THE_BLOB_IN_GAME_SPRITE_ANIMATION_H