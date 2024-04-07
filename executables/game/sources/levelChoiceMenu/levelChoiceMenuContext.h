#ifndef BOB_THE_BLOB_GAME_LEVEL_CHOICE_MENU_CONTEXT_H
#define BOB_THE_BLOB_GAME_LEVEL_CHOICE_MENU_CONTEXT_H

struct Essentials;
struct PlayerAttributes;

namespace levelChoice{
	struct MenuElements;
	
	void mainContext(Essentials& essentials);
	
	void updateInterface(Essentials& essentials, levelChoice::MenuElements& interface);
	
	void drawEverything(Essentials& essentials, const levelChoice::MenuElements& interface);
	
	void quitMenu(Essentials& essentials, const levelChoice::MenuElements& interface, bool& quitMenu);
	
	void seeNextPage(levelChoice::MenuElements& interface);
	
	void seePrecedentPage(levelChoice::MenuElements& interface);
	
	void runLevel(Essentials& essentials, const levelChoice::MenuElements& interface, PlayerAttributes& playerAttributes);
}

#endif //BOB_THE_BLOB_GAME_LEVEL_CHOICE_MENU_CONTEXT_H