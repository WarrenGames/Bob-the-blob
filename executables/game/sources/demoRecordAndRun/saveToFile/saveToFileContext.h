#ifndef BOB_THE_BLOB_GAME_SAVE_TO_FILE_CONTEXT_H
#define BOB_THE_BLOB_GAME_SAVE_TO_FILE_CONTEXT_H

struct Essentials;
namespace demos{ struct DataPackage; }

namespace saveDemo{
	struct FileMenu;
	
	void mainContext(Essentials& essentials, const demos::DataPackage& demoDataPackage);
	
	void drawScreen(Essentials& essentials, const saveDemo::FileMenu& fileMenu);
	
	void quitScreenWithoutSaving(Essentials& essentials, const saveDemo::FileMenu& fileMenu, bool& quitMenu);
	
	void saveDemoDataAndQuit(Essentials& essentials, const saveDemo::FileMenu& fileMenu, bool& quitMenu, const demos::DataPackage& demoDataPackage);
}

#endif //BOB_THE_BLOB_GAME_SAVE_TO_FILE_CONTEXT_H