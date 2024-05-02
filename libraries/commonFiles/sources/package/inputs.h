#ifndef BOB_THE_BLOB_COMMON_FILES_MENUS_INPUTS_H
#define BOB_THE_BLOB_COMMON_FILES_MENUS_INPUTS_H

#include "customTypes/positionTypes.h"
#include "SDL_events.h"
#include <vector>

constexpr std::size_t ButtonsNumber = 3;
enum : std::size_t { KEY_ESCAPE, KEY_RETURN, KEY_F1, KEY_F5, KEY_MAX };

class Inputs
{
private:
	SDL_Event event;
	Offset mousePosition;
	std::vector< bool > mouseButtonsStates;
	std::vector< bool > keysState;
	bool sdlQuit;
	
public:
	Inputs();
	~Inputs() = default;
	Inputs( const Inputs& ) = delete;
	Inputs& operator= ( const Inputs& ) = delete;
	Inputs( Inputs&& ) = default;
	Inputs& operator= ( Inputs&& ) = default;
	
	void updateEvents();
	const Offset& getMousePosition() const;
	bool getMouseButtonState(std::size_t buttonIndex) const;
	void setMouseButtonFalse(std::size_t buttonIndex);
	bool getSdlQuit() const;
	bool isKeyDown(std::size_t keyIndex) const;
	void setKeyStateToFalse(std::size_t keyIndex);
	
private:
	void setMouseButton(std::size_t buttonType, bool state);
	void setMousePosition(const SDL_Event& e);
	void setKeysState(SDL_Keycode keycode, bool stateToSet);
};

#endif //BOB_THE_BLOB_COMMON_FILES_MENUS_INPUTS_H