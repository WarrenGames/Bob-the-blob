#ifndef BOB_THE_BLOB_GAME_OPTIONS_KEYBOARD_CONTEXT_H
#define BOB_THE_BLOB_GAME_OPTIONS_KEYBOARD_CONTEXT_H

struct Essentials;
namespace options{ struct InputsGlobalInterface; }

namespace options{
	void inputsMainContext(Essentials& essentials);
	
	void quitInputsMenuContext(Essentials& essentials, bool& quitMenu);
	
	void drawInputsMenuContext(Essentials& essentials, const options::InputsGlobalInterface& optionsData);
	
	void seeJoystickConfiguration(Essentials& essentials, const options::InputsGlobalInterface& optionsData);
	
	void runJoystickCalibration(Essentials& essentials, const options::InputsGlobalInterface& optionsData);
}

#endif //BOB_THE_BLOB_GAME_OPTIONS_KEYBOARD_CONTEXT_H