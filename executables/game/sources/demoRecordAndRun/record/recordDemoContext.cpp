#include "demoRecordAndRun/record/recordDemoContext.h"
#include "demoRecordAndRun/record/recordDemoMenu.h"
#include "package/essentials.h"
#include "demos/data/dataPackage.h"
#include "levels/playerAttributes/playerAttributes.h"
#include "levels/gameContexts/levelContext.h"
#include "levels/gameContexts/mexicanZone.h"
#include "hintsScreen/mexican/mexicanHintScreen.h"
#include "demoRecordAndRun/saveToFile/saveToFileContext.h"
#include "consts/colors.h"
#include "demos/consts/demosConsts.h"
#include "consts/levelsTypesConsts.h"
#include "consts/skillLevelsConsts.h"

void demosRecording::mainContext(Essentials& essentials)
{
	demosRecording::Menu menu{essentials};
	bool quitMenu{false};
	
	while( false == quitMenu )
	{
		essentials.inputs.updateEvents();
		menu.updateButtons(essentials);
		demosRecording::quitContext(essentials, menu, quitMenu);
		demosRecording::seePrecedentPage(menu);
		demosRecording::seeNextPage(menu);
		demosRecording::runDemoRecording(essentials, menu);
		demosRecording::drawEverything(essentials, menu);
		essentials.inputs.setMouseButtonFalse(SDL_BUTTON_LEFT);
	}
}

void demosRecording::drawEverything(Essentials& essentials, const demosRecording::Menu& menu)
{
	if( essentials.drawDelay.hasTimeElapsed(essentials.microSecondsDelay) )
	{
		essentials.drawDelay.joinTimePoints();
		essentials.rndWnd.clearScreen(BlackCol);
		menu.drawEverything(essentials);
		essentials.rndWnd.displayRenderer();
	}
}

void demosRecording::quitContext(Essentials& essentials, const demosRecording::Menu& menu, bool& quitMenu)
{
	if( essentials.inputs.getSdlQuit() || menu.quitButton.buttonClicked() || essentials.inputs.isKeyDown(KEY_ESCAPE) )
	{
		essentials.inputs.setKeyStateToFalse(KEY_ESCAPE);
		quitMenu = true;
	}
}

void demosRecording::seePrecedentPage(demosRecording::Menu& menu)
{
	if( menu.precedentPageButton.buttonClicked() )
	{
		menu.levelsListing.seePrecedentPageIfAny();
	}
}

void demosRecording::seeNextPage(demosRecording::Menu& menu)
{
	if( menu.nextPageButton.buttonClicked() )
	{
		menu.levelsListing.seeNextPageIfAny();
	}
}

void demosRecording::runDemoRecording(Essentials& essentials, const demosRecording::Menu& menu)
{
	if( menu.levelsListing.size() > 0 )
	{
		for( auto const &level : menu.levelsListing )
		{
			if( level.textButton.buttonClicked() )
			{
				switch( level.levelType )
				{
					case LevelBlueBrick:
						demosRecording::prepareStandardLevelData(essentials, level.levelName, menu.skillLevelCursor.getSkillLevel() );
						break;
					case LevelMexican:
						demosRecording::prepareMexicanLevelData(essentials, level.levelName, menu.skillLevelCursor.getSkillLevel() );
						break;
				}
			}
		}
	}
}

void demosRecording::prepareStandardLevelData(Essentials& essentials, const std::string& levelName, unsigned skillLevel)
{
	PlayerAttributes playerAttributes{skillLevel};
	demos::DataPackage demoDataPackage{essentials, levelName, demos::GameIsRecording, LevelBlueBrick};
	
	standardLevel::levelContext(essentials, playerAttributes, levelName, &demoDataPackage);
	
	saveDemo::mainContext(essentials, demoDataPackage);
}

void demosRecording::prepareMexicanLevelData(Essentials& essentials, const std::string& levelName, unsigned skillLevel)
{
	PlayerAttributes playerAttributes{skillLevel};
	demos::DataPackage demoDataPackage{essentials, levelName, demos::GameIsRecording, LevelMexican};
	
	mexican::levelContext(essentials, playerAttributes, levelName, &demoDataPackage);
	
	saveDemo::mainContext(essentials, demoDataPackage);
}
