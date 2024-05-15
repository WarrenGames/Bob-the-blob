#include "demoRecordAndRun/saveToFile/saveToFileContext.h"
#include "package/essentials.h"
#include "demoRecordAndRun/saveToFile/saveToDemoFileMenu.h"
#include "levels/demosRecordingAndPlaying/demosFiles/saveDataToFile.h"
#include "consts/colors.h"
#include "consts/filesAndPaths.h"

void saveDemo::mainContext(Essentials& essentials, const demos::DataPackage& demoDataPackage)
{
	saveDemo::FileMenu fileMenu{ essentials, demoDataPackage };
	bool quitMenu{false};
	essentials.inputs.setMouseButtonFalse(SDL_BUTTON_LEFT);
	while( false == quitMenu )
	{
		essentials.inputs.updateEvents();
		fileMenu.updateInterface(essentials);
		saveDemo::saveDemoDataAndQuit(essentials, fileMenu, quitMenu, demoDataPackage);
		saveDemo::quitScreenWithoutSaving(essentials, fileMenu, quitMenu);
		saveDemo::drawScreen(essentials, fileMenu);
		essentials.inputs.setMouseButtonFalse(SDL_BUTTON_LEFT);
	}
}

void saveDemo::drawScreen(Essentials& essentials, const saveDemo::FileMenu& fileMenu)
{
	if( essentials.drawDelay.hasTimeElapsed( std::chrono::milliseconds{16} ) )
	{
		essentials.drawDelay.joinTimePoints();
		essentials.rndWnd.clearScreen( BlackCol );
		fileMenu.drawEverything(essentials);
		essentials.rndWnd.displayRenderer();
	}
}

void saveDemo::quitScreenWithoutSaving(Essentials& essentials, const saveDemo::FileMenu& fileMenu, bool& quitMenu)
{
	if( essentials.inputs.getSdlQuit() || essentials.inputs.isKeyDown(KEY_ESCAPE) || fileMenu.quitWithoutSaving.buttonClicked() )
	{
		quitMenu = true;
	}
}

void saveDemo::saveDemoDataAndQuit(Essentials& essentials, const saveDemo::FileMenu& fileMenu, bool& quitMenu, const demos::DataPackage& demoDataPackage)
{
	if( fileMenu.saveToFileButton.buttonClicked() )
	{
		saveDemo::openFile(essentials.prefPath.getFsPath() / files::DemosDir / fileMenu.fileName, demoDataPackage);
		quitMenu = true;
	}
}