#ifndef BOB_THE_BLOB_IN_GAME_BOB_THE_BLOB_ABILITY_H
#define BOB_THE_BLOB_IN_GAME_BOB_THE_BLOB_ABILITY_H

#include "time/accurateTime.h"

class Ability
{
private:
	AccurateTimeDelay delayMeasure;
	std::chrono::milliseconds delay;
	bool isActive;

public:
	Ability(long long int readDelay);
	~Ability() = default;
	Ability( const Ability& ) = delete;
	Ability& operator= ( const Ability& ) = delete;
	Ability( Ability&& ) = default;
	Ability& operator= ( Ability&& ) = default;
	
	bool isAbilityActive() const;
	void startAbility();
	void abortAbility();
	unsigned getMillisecondsStartDelay() const;
	unsigned getCurrentDelay() const;
};

#endif //BOB_THE_BLOB_IN_GAME_BOB_THE_BLOB_ABILITY_H