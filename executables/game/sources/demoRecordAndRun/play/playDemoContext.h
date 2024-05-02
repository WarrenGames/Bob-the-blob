#ifndef BOB_THE_BLOB_GAME_PLAY_DEMO_CONTEXT_H
#define BOB_THE_BLOB_GAME_PLAY_DEMO_CONTEXT_H

#include "fileSystem/fileSystem.h"

struct Essentials;

namespace demosPlaying{
	struct DemoChoiceMenu;
	
	void demoChoice(Essentials& essentials);
	
	void seeNextPage(demosPlaying::DemoChoiceMenu& demoChoiceMenu);
	
	void seePrecedentPage(demosPlaying::DemoChoiceMenu& demoChoiceMenu);
	
	void quitDemosListMenu(Essentials& essentials, demosPlaying::DemoChoiceMenu& demoChoiceMenu, bool& quitMenu);
	
	void drawEverything(Essentials& essentials, const demosPlaying::DemoChoiceMenu& demoChoiceMenu);
	
	void runDemo(Essentials& essentials, const demosPlaying::DemoChoiceMenu& demoChoiceMenu);
	
	void loadData(Essentials& essentials, const fs::path& demoFilePath);
}

#endif //BOB_THE_BLOB_GAME_PLAY_DEMO_CONTEXT_H