#ifndef BOB_THE_BLOB_IN_GAME_INPUTS_STATES_H
#define BOB_THE_BLOB_IN_GAME_INPUTS_STATES_H

#include <vector>

struct InputsStates
{
	std::vector< bool > funcStates;
	bool escapeState;
	bool sdlQuitState;
	
	InputsStates();
	~InputsStates() = default;
	InputsStates( const InputsStates& ) = delete;
	InputsStates& operator= ( const InputsStates& ) = delete;
	InputsStates( InputsStates&& ) = default;
	InputsStates& operator= ( InputsStates&& ) = default;
	
	bool getState(std::size_t stateIndex) const;
	std::size_t size() const;
};

#endif //BOB_THE_BLOB_IN_GAME_INPUTS_STATES_H