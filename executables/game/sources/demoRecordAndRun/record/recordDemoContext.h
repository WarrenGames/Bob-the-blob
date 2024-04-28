#ifndef BOB_THE_BLOB_GAME_RECORD_DEMO_CONTEXT_H
#define BOB_THE_BLOB_GAME_RECORD_DEMO_CONTEXT_H

#include <string>

struct Essentials;

namespace demosRecording{
	struct Menu;
	
	void mainContext(Essentials& essentials);
	
	void drawEverything(Essentials& essentials, const demosRecording::Menu& menu);
	
	void quitContext(Essentials& essentials, const demosRecording::Menu& menu, bool& quitMenu);
	
	void seePrecedentPage(demosRecording::Menu& menu);
	
	void seeNextPage(demosRecording::Menu& menu);
	
	void runDemoRecording(Essentials& essentials, const demosRecording::Menu& menu);
	
	void prepareStandardLevelData(Essentials& essentials, const std::string& levelName, unsigned skillLevel);
	
	void prepareMexicanLevelData(Essentials& essentials, const std::string& levelName, unsigned skillLevel);
}


#endif //BOB_THE_BLOB_GAME_RECORD_DEMO_CONTEXT_H