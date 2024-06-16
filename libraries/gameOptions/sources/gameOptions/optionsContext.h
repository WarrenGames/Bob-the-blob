#ifndef BOB_THE_BLOB_GAME_OPTIONS_MENU_CONTEXT_H
#define BOB_THE_BLOB_GAME_OPTIONS_MENU_CONTEXT_H

struct Essentials;
namespace options{ struct MainMenuGraphisms; }

namespace options{
	void context(Essentials& essentials);
	
	void drawOptionsMenu(Essentials& essentials, const options::MainMenuGraphisms& mainMenuGraphisms);
	
	void quitMenuWithEscape(Essentials& essentials, bool& quitMenu);
	
	void closeWindowAsked(Essentials& essentials, bool& quitMenu);
	
	void goToInputsPanel(Essentials& essentials, const options::MainMenuGraphisms& mainMenuGraphisms);
	
	void goToSettingsPanel(Essentials& essentials, const options::MainMenuGraphisms& mainMenuGraphisms);
}

#endif //BOB_THE_BLOB_GAME_OPTIONS_MENU_CONTEXT_H