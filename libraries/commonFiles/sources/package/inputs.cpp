#include "package/inputs.h"
#include <cassert>

Inputs::Inputs():
	mousePosition{ 0, 0 },
	mouseButtonsStates( ButtonsNumber, false ),
	keysState( KEY_MAX, false ),
	sdlQuit{false}
{
	
}

void Inputs::updateEvents()
{
	while( SDL_PollEvent(&event) )
	{
		switch( event.type )
		{
			case SDL_QUIT:
				sdlQuit = true;
				break;
			case SDL_MOUSEMOTION:
				setMousePosition(event);
				break;
			case SDL_MOUSEBUTTONDOWN:
				setMouseButton(static_cast<std::size_t>(event.button.button), true);
				break;
			case SDL_MOUSEBUTTONUP:
				setMouseButton(static_cast<std::size_t>(event.button.button), false);
				break;
			case SDL_KEYDOWN:
				setKeysState(event.key.keysym.sym, true);
				break;
			case SDL_KEYUP:
				setKeysState(event.key.keysym.sym, false);
				break;
		}
	}
}

void Inputs::setMouseButton(std::size_t buttonType, bool state)
{
	if( buttonType < mouseButtonsStates.size() )
	{
		mouseButtonsStates[buttonType] = state;
	}
}

void Inputs::setMousePosition(const SDL_Event& e)
{
	mousePosition.x = e.motion.x;
	mousePosition.y = e.motion.y;
}

const Offset& Inputs::getMousePosition() const
{
	return mousePosition;
}

bool Inputs::getMouseButtonState(std::size_t buttonIndex) const
{
	assert( buttonIndex < mouseButtonsStates.size() );
	return mouseButtonsStates[buttonIndex];
}

void Inputs::setMouseButtonFalse(std::size_t buttonIndex)
{
	assert( buttonIndex < mouseButtonsStates.size() );
	mouseButtonsStates[buttonIndex] = false;
}

bool Inputs::getSdlQuit() const
{
	return sdlQuit;
}

bool Inputs::isKeyDown(std::size_t keyIndex) const
{
	assert( keyIndex < keysState.size() );
	return keysState[keyIndex];
}

void Inputs::setKeyStateToFalse(std::size_t keyIndex)
{
	assert( keyIndex < keysState.size() );
	keysState[keyIndex] = false;
}

void Inputs::setKeysState(SDL_Keycode keycode, bool stateToSet)
{
	switch( keycode )
	{
		case SDLK_ESCAPE:
			keysState[KEY_ESCAPE] = stateToSet;
			break;
		case SDLK_RETURN:
			keysState[KEY_RETURN] = stateToSet;
			break;
		case SDLK_F1:
			keysState[KEY_F1] = stateToSet;
			break;
		case SDLK_F5:
			keysState[KEY_F5] = stateToSet;
			break;
	}
}