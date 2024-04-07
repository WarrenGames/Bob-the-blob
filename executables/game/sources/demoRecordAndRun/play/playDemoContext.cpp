#include "demoRecordAndRun/play/playDemoContext.h"
#include "demoRecordAndRun/play/playDemoMenu.h"
#include "levels/gameContexts/levelContext.h"
#include "levels/gameContexts/mexicanZone.h"
#include "levels/playerAttributes/playerAttributes.h"
#include "package/essentials.h"
#include "demos/data/dataPackage.h"
#include "demos/demosFiles/loadDataFromFile.h"
#include "consts/levelsTypesConsts.h"
#include "consts/filesAndPaths.h"
#include "consts/fontsSizes.h"
#include "consts/colors.h"
#include <cassert>

void demosPlaying::demoChoice(Essentials& essentials)
{
	demosPlaying::DemoChoiceMenu demoChoiceMenu{essentials};
	bool quitMenu{false};
	
	while( false == quitMenu )
	{
		essentials.inputs.updateEvents();
		demoChoiceMenu.updateButtons(essentials);
		demosPlaying::quitDemosListMenu(essentials, demoChoiceMenu, quitMenu);
		demosPlaying::seeNextPage(demoChoiceMenu);
		demosPlaying::seePrecedentPage(demoChoiceMenu);
		demosPlaying::runDemo(essentials, demoChoiceMenu);
		demosPlaying::drawEverything(essentials, demoChoiceMenu);
		essentials.inputs.setMouseButtonFalse(SDL_BUTTON_LEFT);
	}
}

void demosPlaying::seeNextPage(demosPlaying::DemoChoiceMenu& demoChoiceMenu)
{
	if( demoChoiceMenu.nextPageButton.buttonClicked() )
	{
		demoChoiceMenu.demosFilesList.seeNextPageIfAny();
	}
}

void demosPlaying::seePrecedentPage(demosPlaying::DemoChoiceMenu& demoChoiceMenu)
{
	if( demoChoiceMenu.precedentPageButton.buttonClicked() )
	{
		demoChoiceMenu.demosFilesList.seePrecedentPageIfAny();
	}
}

void demosPlaying::quitDemosListMenu(Essentials& essentials, demosPlaying::DemoChoiceMenu& demoChoiceMenu, bool& quitMenu)
{
	if( essentials.inputs.getSdlQuit() || essentials.inputs.isKeyDown(KEY_ESCAPE) || demoChoiceMenu.quitButton.buttonClicked() )
	{
		quitMenu = true;
		essentials.inputs.setKeyStateToFalse(KEY_ESCAPE);
	}
}

void demosPlaying::drawEverything(Essentials& essentials, const demosPlaying::DemoChoiceMenu& demoChoiceMenu)
{
	if( essentials.drawDelay.hasTimeElapsed(essentials.microSecondsDelay) )
	{
		essentials.drawDelay.joinTimePoints();
		essentials.rndWnd.clearScreen(BlackCol);
		demoChoiceMenu.drawInterface(essentials);
		essentials.rndWnd.displayRenderer();
	}
}

void demosPlaying::runDemo(Essentials& essentials, const demosPlaying::DemoChoiceMenu& demoChoiceMenu)
{
	if( demoChoiceMenu.demosFilesList.size() > 0 )
	{
		for( auto const &demo : demoChoiceMenu.demosFilesList )
		{
			if( demo.textButton.buttonClicked() )
			{
				demosPlaying::loadData(essentials, demo.levelName);
			}
		}
	}
}

void demosPlaying::loadData(Essentials& essentials, const fs::path& demoFilePath)
{
	PlayerAttributes playerAttributes;
	demos::DataPackage demoDataPackage{essentials, "demo play type", demos::GameIsDemo, LevelBlueBrick};
	
	loadDemo::openFile(demoFilePath, demoDataPackage);
	
	switch( demoDataPackage.gameAmbience )
	{
		case LevelBlueBrick:
			standardLevel::levelContext(essentials, playerAttributes, demoDataPackage.levelName, &demoDataPackage);
			break;
		case LevelMexican:
			mexican::levelContext(essentials, playerAttributes, demoDataPackage.levelName, &demoDataPackage);
			break;
		default:
			assert( false && "Error: bad game ambience enum !" );
			break;
	}
}