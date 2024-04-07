#include "levels/inputs/inputsStates.h"
#include "consts/playerInputsConsts.h"
#include <cassert>

InputsStates::InputsStates():
	funcStates( MoveMax, false ),
	escapeState{false},
	sdlQuitState{false}
{

}

bool InputsStates::getState(std::size_t stateIndex) const
{
	assert( stateIndex < funcStates.size() );
	return funcStates[stateIndex];
}

std::size_t InputsStates::size() const
{
	return funcStates.size();
}