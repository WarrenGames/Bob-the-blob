#ifndef HINTS_SCREENS_MAIN_MENU_CONTEXT_H
#define HINTS_SCREENS_MAIN_MENU_CONTEXT_H

struct Essentials;

namespace hintsScreens{
	struct MainMenu;
	
	void mainMenuContext(Essentials& essentials);
	
	void quitMenu(Essentials& essentials, bool& quitMenu);
	
	void runFleeEnemyMenu(Essentials& essentials, hintsScreens::MainMenu& mainMenuElements);
	
	void drawEverything(Essentials& essentials, hintsScreens::MainMenu& mainMenuElements);
}

#endif //HINTS_SCREENS_MAIN_MENU_CONTEXT_H