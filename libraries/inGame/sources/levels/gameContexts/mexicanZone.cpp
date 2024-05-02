#include "levels/gameContexts/mexicanZone.h"
#include "levels/global/mexicanGameGlobalObject.h"
#include "package/essentials.h"
#include "exceptions/readErrorExcept.h"
#include "levels/playerAttributes/playerAttributes.h"
#include "levels/demos/transferDemoStacks.h"
#include "levels/demos/initializeDemoStacks.h"
#include "levels/demos/joinTimePoints.h"
#include "demos/data/dataPackage.h"
#include "levels/maps/mapsConsts.h"
#include "levels/maps/bonusesConsts.h"
#include "consts/colors.h"

void mexican::levelContext(Essentials& essentials, PlayerAttributes& playerAttributes, const fs::path& levelPrefix, demos::DataPackage *demoPackage)
{
	bool quitLevel{false};
	try{
		MexicanGameObject mexicanGameObject{essentials, playerAttributes, levelPrefix, demoPackage};
		demos::initializeStacksNumber(essentials, demoPackage, mexicanGameObject.levelData);
		demos::transferEventsStackInCaseOfDemo(demoPackage, mexicanGameObject.levelData.playerInputs.recordedEvents);
		demos::joinTimePoints(demoPackage, mexicanGameObject.levelData);
		
		while( false == quitLevel && false == mexicanGameObject.levelData.canQuitLevel() )
		{
			mexicanGameObject.updateGame(essentials, playerAttributes, demoPackage);
			mexican::quitContext(mexicanGameObject, quitLevel);
			mexican::drawEverything(essentials, mexicanGameObject);
		}
		demos::transferEventsStackInCaseOfRecording(demoPackage, mexicanGameObject.levelData.playerInputs.recordedEvents);
	}
	catch( const ReadError& readError )
	{
		essentials.logs.error << "Error: couldn't load mexican level: " << readError.what() << " .\n";
		essentials.logs.error.flushLog();
	}
}

void mexican::quitContext(const MexicanGameObject& mexicanGameObject, bool& quitLevel)
{
	if( mexicanGameObject.hasPlayerRequestedToExit() )
	{
		quitLevel = true;
	}
}

void mexican::drawEverything(Essentials& essentials, MexicanGameObject& mexicanGameObject)
{
	if( essentials.drawDelay.hasTimeElapsed(essentials.microSecondsDelay) )
	{
		essentials.drawDelay.joinTimePoints();
		essentials.rndWnd.clearScreen(BlackCol);
		mexicanGameObject.drawLevel(essentials.rndWnd);
		essentials.rndWnd.displayRenderer();
	}
}