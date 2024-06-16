#ifndef BOB_THE_BLOB_GAME_OPTIONS_GAME_SETTINGS_CONTEXT_H
#define BOB_THE_BLOB_GAME_OPTIONS_GAME_SETTINGS_CONTEXT_H

struct Essentials;

namespace options{

namespace settings{
	class Interface;
	
	void mainContext(Essentials& essentials);
	
	void drawEverything(Essentials& essentials, const options::settings::Interface& settingsInterface);
	
	void quitContext(Essentials& essentials, const options::settings::Interface& settingsInterface, bool& quitMenu);
}

}

#endif //BOB_THE_BLOB_GAME_OPTIONS_GAME_SETTINGS_CONTEXT_H