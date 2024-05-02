#include "levels/inputs/inputsStates.h"
#include "consts/playerInputsConsts.h"
#include <cassert>

InputsStates::InputsStates():
	funcStates( MoveMax, false ),
	escapeState{false},
	sdlQuitState{false}
{

}

bool InputsStates::getEscapeState() const
{
	return escapeState;
}

bool InputsStates::getSdlQuit() const
{
	return sdlQuitState;
}

void InputsStates::setEscapeKeyFlag(bool state)
{
	escapeState = state;
}

void InputsStates::setSdlQuitFlag(bool state)
{
	sdlQuitState = state;
}

bool InputsStates::getState(std::size_t stateIndex) const
{
	assert( stateIndex < funcStates.size() );
	return funcStates[stateIndex];
}

void InputsStates::setState(std::size_t stateIndex, bool state)
{
	assert( stateIndex < funcStates.size() );
	funcStates[stateIndex] = state;
}

std::size_t InputsStates::size() const
{
	return funcStates.size();
}