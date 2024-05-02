#include "levels/gameActors/playerThings/characterAbility.h"

Ability::Ability(unsigned readDelay):
	delay{ readDelay },
	isActive{ false }
{
	
}

bool Ability::isAbilityActive() const
{
	return isActive;
}

void Ability::startAbility()
{
	isActive = true;
	delayMeasure.joinTimePoints();
}

void Ability::abortAbility()
{
	if( isActive )
	{
		if( delayMeasure.hasTimeElapsed(delay) )
		{
			isActive = false;
		}
	}
}

unsigned Ability::getMillisecondsStartDelay() const
{
	return static_cast<unsigned>( delay.count() );
}

unsigned Ability::getCurrentDelay() const
{
	return static_cast<unsigned>( delayMeasure.getCurrentElapsedMillisecondsTime().count() );
}