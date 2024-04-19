#ifndef BOB_THE_BLOB_IN_GAME_INPUTS_STATES_H
#define BOB_THE_BLOB_IN_GAME_INPUTS_STATES_H

#include <vector>

class InputsStates
{
private:
	std::vector< bool > funcStates;
	bool escapeState;
	bool sdlQuitState;

public:
	InputsStates();
	~InputsStates() = default;
	InputsStates( const InputsStates& ) = delete;
	InputsStates& operator= ( const InputsStates& ) = delete;
	InputsStates( InputsStates&& ) = default;
	InputsStates& operator= ( InputsStates&& ) = default;
	
	bool getEscapeState() const;
	bool getSdlQuit() const;
	void setEscapeKeyFlag(bool state);
	void setSdlQuitFlag(bool state);
	
	bool getState(std::size_t stateIndex) const;
	void setState(std::size_t stateIndex, bool state);
	std::size_t size() const;
};

#endif //BOB_THE_BLOB_IN_GAME_INPUTS_STATES_H