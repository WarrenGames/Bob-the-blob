#ifndef BOB_THE_BLOB_IN_GAME_EXPLOSION_INFOS_H
#define BOB_THE_BLOB_IN_GAME_EXPLOSION_INFOS_H

#include "time/accurateTime.h"
#include <cstdlib>

class ExplosionInfos
{
private:
	AccurateTimeDelay animationTime;
	std::size_t frameNumber;
	std::chrono::milliseconds frameDuration;
	bool canPlayExplosion;

public:
	explicit ExplosionInfos(bool playStatus, unsigned frameMillisDuration);
	~ExplosionInfos() = default;
	ExplosionInfos( const ExplosionInfos& ) = default;
	ExplosionInfos& operator= ( const ExplosionInfos& ) = default;
	
	bool isExplosionActive();
	std::size_t getCurrentFrame() const;
	void incrementFrame(std::size_t totalFrameNumber);
	void resetExplosionDisplay();
};

#endif //BOB_THE_BLOB_IN_GAME_EXPLOSION_INFOS_H