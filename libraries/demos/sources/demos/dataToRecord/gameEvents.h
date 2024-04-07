#ifndef DEMOS_LIB_GAME_EVENTS_STACK_DATA_H
#define DEMOS_LIB_GAME_EVENTS_STACK_DATA_H

#include <chrono>
#include <cstdlib>

namespace demos{

struct GameEvent
{
	std::chrono::duration<long double, std::micro> delay;
	unsigned category;//'Bob' 'OrbLife' 'CactusAndPlayer', 'CactusLife', 'PlayerPower'
	unsigned subType;
	std::size_t id;
	
	GameEvent();
	GameEvent(const std::chrono::duration<long double, std::micro>& newDelay, unsigned eventCategory, unsigned eventSubType, std::size_t newId);
	~GameEvent() = default;
	GameEvent( const GameEvent& ) = default;
	GameEvent& operator= ( const GameEvent& ) = default;
};

}

#endif //DEMOS_LIB_GAME_EVENTS_STACK_DATA_H