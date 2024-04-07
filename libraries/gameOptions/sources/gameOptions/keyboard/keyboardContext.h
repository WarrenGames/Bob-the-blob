#ifndef BOB_THE_BLOB_GAME_OPTIONS_KEYBOARD_CONTEXT_H
#define BOB_THE_BLOB_GAME_OPTIONS_KEYBOARD_CONTEXT_H

struct Essentials;
struct TextureCombo;
class KeyboardOptions;

namespace options{
	void keyboardMainContext(Essentials& essentials);
	
	void quitKeyboardMenuContext(Essentials& essentials, bool& quitMenu);
	
	void drawKeyboardMenuBackground(Essentials& essentials, const TextureCombo& background);
	
	void drawKeyboardMenuContext(Essentials& essentials, const KeyboardOptions& keyboardOptions, const TextureCombo& background);
}

#endif //BOB_THE_BLOB_GAME_OPTIONS_KEYBOARD_CONTEXT_H