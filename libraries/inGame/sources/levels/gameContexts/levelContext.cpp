#include "levels/gameContexts/levelContext.h"
#include "levels/global/gameGlobalObject.h"
#include "package/essentials.h"
#include "exceptions/readErrorExcept.h"
#include "levels/playerAttributes/playerAttributes.h"
#include "levels/loadings/gameConfigurationData.h"
#include "levels/benchmarks/benchmarkObject.h"
#include "levels/benchmarks/outputBenchmarkData.h"
#include "levels/demos/transferDemoStacks.h"
#include "levels/demos/initializeDemoStacks.h"
#include "levels/demos/joinTimePoints.h"
#include "levels/demosRecordingAndPlaying/data/dataPackage.h"
#include "levels/maps/mapsConsts.h"
#include "levels/maps/bonusesConsts.h"
#include "consts/colors.h"

void standardLevel::levelContext(Essentials& essentials, PlayerAttributes& playerAttributes, const fs::path& levelPrefix, std::optional<demos::DataPackage>& demoPackage)
{
	bool quitLevel{false};
	try{
		Benchs benchs{essentials.logs, essentials.prefPath, levelPrefix};
		GameConfigData gameConfigData{essentials, demoPackage};
		
		GameGlobalObject gameGlobalObject{essentials, playerAttributes, levelPrefix, demoPackage, gameConfigData};
		demos::initializeStacksNumber(essentials, demoPackage, gameGlobalObject.levelData);
		demos::transferEventsStackInCaseOfDemo(demoPackage, gameGlobalObject.levelData.playerInputs.recordedEvents);
		demos::joinTimePoints(demoPackage, gameGlobalObject.levelData);
		
		while( false == quitLevel && false == gameGlobalObject.levelData.canQuitLevel() )
		{
			benchs.cpuBench.setStartingPoint();
			gameGlobalObject.updateGame(essentials, playerAttributes, demoPackage);
			standardLevel::quitContext(gameGlobalObject, quitLevel);
			benchs.cpuBench.setFinalPoint();
			benchs.gpuBench.setStartingPoint();
			standardLevel::drawEverything(essentials, gameGlobalObject);
			benchs.gpuBench.setFinalPoint();
		}
		demos::transferEventsStackInCaseOfRecording(demoPackage, gameGlobalObject.levelData.playerInputs.recordedEvents);
		gameConfigData.setDataToDemoPackage(demoPackage);
		outputBenchmarkDataToFiles(essentials.logs, essentials.prefPath, benchs);
	}
	catch( const ReadError& readError )
	{
		essentials.logs.error << "Error: couldn't load standard level: " << readError.what() << " .\n";
		essentials.logs.error.flushLog();
	}
}

void standardLevel::quitContext(const GameGlobalObject& gameGlobalObject, bool& quitLevel)
{
	if( gameGlobalObject.hasPlayerRequestedToExit() )
	{
		quitLevel = true;
	}
}

void standardLevel::drawEverything(Essentials& essentials, GameGlobalObject& gameGlobalObject)
{
	if( essentials.drawDelay.hasTimeElapsed(essentials.microSecondsDelay) )
	{
		essentials.drawDelay.joinTimePoints();
		essentials.rndWnd.clearScreen(BlackCol);
		gameGlobalObject.drawLevel(essentials.rndWnd);
		essentials.rndWnd.displayRenderer();
	}
}