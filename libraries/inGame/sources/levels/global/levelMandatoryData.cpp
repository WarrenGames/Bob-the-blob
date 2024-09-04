#include "levels/global/levelMandatoryData.h"
#include "levels/loadings/gameComponentsLoading.h"
#include "levels/loadings/gameConfigurationData.h"
#include "levels/mapSubDivisions/functions/cutZones.h"
#include "levels/playerAttributes/playerAttributes.h"
#include "levels/demosRecordingAndPlaying/data/dataPackage.h"
#include "levels/demosRecordingAndPlaying/data/determineGameStatus.h"
#include "package/essentials.h"
#include "pathsFunctions/pathsFunctions.h"
#include "consts/screenConsts.h"
#include "consts/filesAndPaths.h"
#include "levels/demosRecordingAndPlaying/consts/demosConsts.h"
#include "levels/demosRecordingAndPlaying/consts/gameEventsConsts.h"
#include "levels/levelFinish/levelFinishConsts.h"
#include "levels/maps/bonusesConsts.h"
#include <cassert>

LevelMandatoryData::LevelMandatoryData(Essentials& essentials, PlayerAttributes& playerAttributes, const fs::path& levelPrefix, std::optional<demos::DataPackage>& demoDataPackage,
										const GameConfigData& gameConfigData):
	isLoadingPerfect{ true },
	hasLevelEnded{ false },
	quitLevel{ false },
	demoType{ demos::getGameStatus(demoDataPackage) },
	gameMap{ essentials.logs, path::getGameConfigFilePath(levelPrefix, files::DefaultMapsExtension), isLoadingPerfect, demos::getGameStatus(demoDataPackage) },
	bonusesMap{ gameMap, levelPrefix, demos::getGameStatus(demoDataPackage) },
	playerData{ gameConfigData, 0 },
	bobsPackage{ path::getGameConfigFilePath(levelPrefix, files::DefaultEnemyBobsFileSuffix), demos::getGameStatus(demoDataPackage), playerAttributes.skillLevel, gameConfigData },
	crossRoadsRandoms{ gameMap },
	playerInputs{ essentials.logs, essentials.prefPath, demos::getGameStatus(demoDataPackage) },
	gameSoundSystem{ essentials.logs, essentials.prefPath },
	screenScrolling{ getGameMapSize(demoDataPackage), GameScreenWidth, GameScreenHeight - SQR_SIZE },
	zonesFences{ gameMap, path::getGameConfigFilePath(levelPrefix, files::DefaultMapSubDivisionSuffix), demos::getGameStatus(demoDataPackage) },
	levelFinishInterface{ essentials }
{
	loadAndInitializeGameComponents(essentials, *this, levelPrefix, demoDataPackage);
	actWithDemoStatus(demoDataPackage);
	
	if( demoType != demos::GameIsDemo )
	{
		bobsPackage.initFirstDirection(crossRoadsRandoms);
	}
}

void LevelMandatoryData::recordStartingData(demos::DataPackage& demoDataPackage) const
{
	if( demoType == demos::GameIsRecording )
	{
		demoDataPackage.mapsElements.recordPlayedMatrix(gameMap.matrix, demoType);
		demoDataPackage.mapsElements.recordBonusesMap(bonusesMap, demoType);
		demoDataPackage.spritesPositions.recordPlayerStartingPosition(playerData, demoType);
		demoDataPackage.spritesPositions.recordProtagonistsStartingPosition(bobsPackage, demoType);
	}
}

void LevelMandatoryData::setLevelDataFromRecordedDemo(const demos::DataPackage& demoDataPackage)
{
	if( demoType == demos::GameIsDemo )
	{
		demoDataPackage.mapsElements.setLevelMatrix(gameMap.matrix, demoType);
		demoDataPackage.mapsElements.setBonusesMap(bonusesMap, demoType);
		zonesFences.subDivisionFileData = demoDataPackage.mapsElements.subDivisionFileData;
		//CutSubdivision  not needed here since we record in demo file the item's coordinates appearance.
		bonusesMap.countAllBonuses();
		demoDataPackage.spritesPositions.setBobbysLevelDataFromDemoData(bobsPackage, demoType);
		demoDataPackage.spritesPositions.setPlayerLevelDataFromDemoData(playerData, demoType);
		playerData.resetPosition();
	}
}

void LevelMandatoryData::actWithDemoStatus(std::optional<demos::DataPackage>& demoDataPackage)
{
	switch( demos::getGameStatus(demoDataPackage) )
	{
		case demos::GameIsRecording:
			recordStartingData(*demoDataPackage);
			break;
		case demos::GameIsDemo:
			setLevelDataFromRecordedDemo(*demoDataPackage);
			break;
	}
}

Coord2D LevelMandatoryData::getGameMapSize(const std::optional<demos::DataPackage>& demoDataPackage) const
{
	switch( demos::getGameStatus(demoDataPackage) )
	{
		case demos::GameIsDemo:
			return demoDataPackage->mapsElements.gameMap.getCoordSize();
			break;
		case demos::GameIsRecording:
			return gameMap.matrix.getCoordSize();
			break;
		case demos::GameHasPlayerInputs:
			return gameMap.matrix.getCoordSize();
			break;
		default:
			assert( false && "Error: bad demos game status !" );
			return gameMap.matrix.getCoordSize();
			break;
	}
}

void LevelMandatoryData::displayLevelEndMessage(sdl2::RendererWindow& rndWnd)
{
	if( hasLevelEnded )
	{
		levelFinishInterface.updateWaves();
		levelFinishInterface.drawLevelEndMessage(rndWnd);
	}
}

void LevelMandatoryData::actWithLevelEnd(std::optional<demos::DataPackage>& demoDataPackage, bool externWinningCondition)
{
	switch( demos::getGameStatus(demoDataPackage) )
	{
		case demos::GameIsDemo:
			checkLevelEndCondition(demoDataPackage);
			break;
		case demos::GameIsRecording:
			checkLevelEndCondition(demoDataPackage, externWinningCondition);
			break;
		case demos::GameHasPlayerInputs:
			checkLevelEndCondition(externWinningCondition);
			break;
		default:
			assert( false && "Error: bad demos game status !" );
			break;
	}
}

void LevelMandatoryData::checkLevelEndCondition(bool externWinningCondition)
{
	if( hasLevelEnded == false && externWinningCondition)
	{
		claimVictory();
	}
}

void LevelMandatoryData::checkLevelEndCondition(std::optional<demos::DataPackage>& demoDataPackage, bool externWinningCondition)
{
	if( hasLevelEnded == false && externWinningCondition)
	{
		claimVictory();
		demoDataPackage->setLevelIsWon();
	}
}

void LevelMandatoryData::checkLevelEndCondition(std::optional<demos::DataPackage>& demoDataPackage)
{
	if( demos::getGameStatus(demoDataPackage) == demos::GameIsDemo )
	{
		if( demoDataPackage->levelWonEvents.getCommandsNumber() > 0 && demoDataPackage->levelWonEvents.hasLastTimeElapsed() )
		{
			claimVictory();
			demoDataPackage->levelWonEvents.pop_back();
		}
	}
}

void LevelMandatoryData::updateLevelExiting()
{
	if( ( hasLevelEnded && levelFinishDelay.hasTimeElapsed( std::chrono::milliseconds{ LevelFinishDisplayMicroSecDelay } ) ) ||
		playerInputs.inputsStates.getSdlQuit() || playerInputs.inputsStates.getEscapeState() )
	{
		quitLevel = true;
	}
}

bool LevelMandatoryData::canQuitLevel() const
{
	return quitLevel;
}

void LevelMandatoryData::claimVictory()
{
	bobsPackage.disableAllBobs();
	playerData.move.stopPlayer();
	levelFinishDelay.joinTimePoints();
	hasLevelEnded = true;
}

void LevelMandatoryData::claimVictoryWithRecordedDemoData(std::optional<demos::DataPackage>& demoDataPackage)
{
	if( demos::getGameStatus(demoDataPackage) == demos::GameIsDemo )
	{
		if( demoDataPackage->gameEvents.getCommandsNumber() > 0 )
		{
			if( demoDataPackage->gameEvents.getLastElement().category == demos::eventCat::GameWon )
			{
				claimVictory();
				demoDataPackage->gameEvents.pop_back();
			}
		}
	}
}