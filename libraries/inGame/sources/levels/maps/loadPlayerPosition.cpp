#include "levels/maps/loadPlayerPosition.h"
#include "levels/loadings/readStartPositionInFile.h"
#include "exceptions/readErrorExcept.h"
#include "levels/gameActors/playerThings/singlePlayerData.h"
#include "logging/logsStruct.h"
#include "demos/consts/demosConsts.h"

void loadPlayerPosition(AppLogFiles& logs, SinglePlayerData& playerObject, const fs::path& positionFilePath, bool& isLoadingPerfect, unsigned demoType)
{
	if( demoType == demos::GameHasPlayerInputs || demoType == demos::GameIsRecording )
	{
		try{
			loadPositionFromFile(playerObject.playerStartingPosition, positionFilePath, "player starting position");
			playerObject.resetPosition();
		}
		catch( const ReadError& readError )
		{
			logs.error << "Error at loading player starting position, because: " << readError.what() << '\n';
		}
		catch( const std::exception& e )
		{
			logs.error << "Error: unknown exception : " << e.what() << "\n";
			isLoadingPerfect = false;
		}
	}
}