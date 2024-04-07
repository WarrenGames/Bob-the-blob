#ifndef BOB_THE_BLOB_GAME_MINI_SCREEN_START_CONTEXT_H
#define BOB_THE_BLOB_GAME_MINI_SCREEN_START_CONTEXT_H

struct Essentials;

namespace gameStarting{
	class MiniScreenMenu;
	
	void context(Essentials& essentials, bool& quitGame);
	
	void contextLoop(Essentials& essentials, const gameStarting::MiniScreenMenu& miniScreenMenu, bool& quitGame);
	
	void userChooseFullScreenMode(Essentials& essentials, bool& quitMenu);
	
	void userChooseWindowedScreenMode(Essentials& essentials, bool& quitMenu);
	
	void userExitGame(Essentials& essentials, bool& quitGame, bool& quitMenu);
	
	void drawMiniScreen(Essentials& essentials, const gameStarting::MiniScreenMenu& miniScreenMenu);
}

#endif //BOB_THE_BLOB_GAME_MINI_SCREEN_START_CONTEXT_H