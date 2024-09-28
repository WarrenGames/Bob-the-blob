#include "levelChoiceMenu/levelChoiceMenuContext.h"
#include "levelChoiceMenu/levelChoiceThings.h"
#include "package/essentials.h"
#include "levels/gameContexts/levelContext.h"
#include "levels/gameContexts/mexicanZone.h"
#include "hintsScreen/blueCastle/blueCastleHintContext.h"
#include "hintsScreen/mexican/mexicanHintScreen.h"
#include "levels/playerAttributes/playerAttributes.h"
#include "levels/demosRecordingAndPlaying/data/dataPackage.h"
#include "consts/colors.h"
#include "consts/levelsTypesConsts.h"
#include "consts/skillLevelsConsts.h"
#include <cassert>
#include <optional>

void levelChoice::mainContext(Essentials& essentials)
{
	levelChoice::MenuElements interface{essentials};
	PlayerAttributes playerAttributes{SkillLevelMedium};
	bool quitMenu{false};
	essentials.inputs.setMouseButtonFalse(SDL_BUTTON_LEFT);
	
	while( false == quitMenu )
	{
		essentials.inputs.updateEvents();
		levelChoice::updateInterface(essentials, interface);
		levelChoice::runLevel(essentials, interface, playerAttributes);
		levelChoice::quitMenu(essentials, interface, quitMenu);
		levelChoice::seePrecedentPage(interface);
		levelChoice::seeNextPage(interface);
		levelChoice::drawEverything(essentials, interface);
		essentials.inputs.setMouseButtonFalse(SDL_BUTTON_LEFT);
	}
}

void levelChoice::updateInterface(Essentials& essentials, levelChoice::MenuElements& interface)
{
	interface.updateButtons(essentials);
}

void levelChoice::drawEverything(Essentials& essentials, const levelChoice::MenuElements& interface)
{
	if( essentials.drawDelay.hasTimeElapsed(essentials.microSecondsDelay) )
	{
		essentials.drawDelay.joinTimePoints();
		essentials.rndWnd.clearScreen( BlackCol );
		interface.drawInterface(essentials);
		essentials.rndWnd.displayRenderer();
	}
}

void levelChoice::quitMenu(Essentials& essentials, const levelChoice::MenuElements& interface, bool& quitMenu)
{
	if( essentials.inputs.getSdlQuit() || essentials.inputs.isKeyDown(KEY_ESCAPE) || interface.quitButton.buttonClicked() )
	{
		quitMenu = true;
		essentials.inputs.setKeyStateToFalse(KEY_ESCAPE);
	}
}

void levelChoice::seeNextPage(levelChoice::MenuElements& interface)
{
	if( interface.nextPageButton.buttonClicked() )
	{
		interface.levelsListing.seeNextPageIfAny();
	}
}

void levelChoice::seePrecedentPage(levelChoice::MenuElements& interface)
{
	if( interface.precedentPageButton.buttonClicked() )
	{
		interface.levelsListing.seePrecedentPageIfAny();
	}
}

void levelChoice::runLevel(Essentials& essentials, const levelChoice::MenuElements& interface, PlayerAttributes& playerAttributes)
{
	if( interface.levelsListing.size() > 0 )
	{
		for( auto const &level : interface.levelsListing )
		{
			if( level.textButton.buttonClicked() )
			{
				playerAttributes.skillLevel = interface.skillLevelCursor.getSkillLevel();
				std::optional<demos::DataPackage> demoPackage;
				switch( level.levelType )
				{
					case LevelBlueBrick:
						hintScreen::displayBlueCastleLevelHelp(essentials);
						standardLevel::levelContext(essentials, playerAttributes, level.levelName, demoPackage);
						break;
					case LevelMexican:
						hintScreen::displayMexicanLevelHelp(essentials);
						mexican::levelContext(essentials, playerAttributes, level.levelName, demoPackage);
						break;
					default:
						assert( false && "Error: bad level type value!" );
						break;
				}
				essentials.inputs.setMouseButtonFalse(SDL_BUTTON_LEFT);
			}
		}
	}
}