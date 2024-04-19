#include "levels/global/updateGame.h"
#include "levels/global/levelMandatoryData.h"
#include "levels/textures/drawing/scoreDisplay.h"
#include "levels/textures/infosPanel/infoGradient.h"
#include "levels/global/actWithBonuses.h"
#include "levels/global/updateProtagonistsMoves.h"
#include "levels/monstersMoves/detectingPlayer.h"
#include "levels/demos/updatePlayerWithDemoData.h"
#include "levels/demos/updateEnemiesWithDemoData.h"
#include "levels/demos/soundsEventsWithDemos.h"
#include "levels/demos/actWithDemoGameEvents.h"
#include "demos/data/dataPackage.h"
#include "demos/data/determineGameStatus.h"
#include "levels/gameActors/playerActorsConsts.h"
#include "levels/maps/bonusesConsts.h"
#include "demos/consts/demosConsts.h"

void update(Essentials& essentials, PlayerAttributes& playerAttributes, LevelMandatoryData& levelData, ScoreDisplay& scoreDisplay, demos::DataPackage* demoDataPackage)
{
	updateWithSoundsEventsStack(levelData, demoDataPackage);
	levelData.updateLevelExiting();
	updatePlayerThings(levelData, demoDataPackage);
	updateEnemyProtagonists(levelData, demoDataPackage, playerAttributes);
	eatBonusWithPlayer(levelData.playerData, levelData.bonusesMap, levelData.bobsPackage, playerAttributes);
	scoreDisplay.updateScoreText(essentials, playerAttributes);
	levelData.playerData.abilities.abortAbilities();
	updateScreenScrolling(levelData.playerData, levelData.screenScrolling);
	demos::handleGameEvents(levelData, demoDataPackage, playerAttributes);
}

void updateScreenScrolling(const SinglePlayerData& player, ScreenScrolling& screenScrolling)
{
	screenScrolling.setScrollingOffset(player.move.getRealPosition() );
}

void updatePlayerThings(LevelMandatoryData& levelData, demos::DataPackage* demoDataPackage)
{
	levelData.playerInputs.actAccordingToDemoStatus();
	switch( demos::getGameStatus(demoDataPackage) )
	{
		case demos::GameHasPlayerInputs:
			bothRecordAndStandardGamePlaying(levelData, demoDataPackage);
			break;
		case demos::GameIsRecording:
			demos::recordNewPlayerMove(levelData.playerData, demoDataPackage->spritesPositions.playersMoves[0]);
			demos::recordNewPlayerStop(levelData.playerData, demoDataPackage->spritesPositions.playersMoves[0]);
			bothRecordAndStandardGamePlaying(levelData, demoDataPackage);
			break;
		case demos::GameIsDemo:
			demos::checkNewPlayerPositionEvent(levelData.playerData, demoDataPackage->spritesPositions.playersMoves[0]);
			demos::stopPlayerAccordingToMap(levelData.playerData.move, levelData.gameMap);
			levelData.playerData.move.checkMoveDelayToMove();
			levelData.playerData.anim.changeCurrentFrameWithBasicAnim();
			updateBobbysDetectionWithSound(levelData.playerData, levelData.bobsPackage, levelData.gameMap, levelData.gameSoundSystem.soundSystem.soundPlayer, demoDataPackage);
			levelData.bobsPackage.spawnBobWithDemoStack(demoDataPackage);
			exitDemo(levelData);
			break;
	}
}

void bothRecordAndStandardGamePlaying(LevelMandatoryData& levelData, demos::DataPackage* demoDataPackage)
{
	if( levelData.hasLevelEnded == false )
	{
		levelData.playerData.move.checkMoveDelayToMove();
	}
	changeWantedNextDirection(levelData.playerInputs, levelData.playerData.move);
	levelData.playerData.move.changePlayerDirection(levelData.gameMap);
	levelData.playerData.move.setNewMatrixPosition();
	levelData.playerData.anim.changeCurrentFrameWithBasicAnim();
	wrapPlayerThatHasLeftOnWest(levelData.playerData.move, levelData.bobsPackage, levelData.gameMap);
	wrapPlayerThatHasLeftOnEast(levelData.playerData.move, levelData.bobsPackage, levelData.gameMap);
	wrapPlayerThatHasLeftOnNorth(levelData.playerData.move, levelData.bobsPackage, levelData.gameMap);
	wrapPlayerThatHasLeftOnSouth(levelData.playerData.move, levelData.bobsPackage, levelData.gameMap);
	resetPlayerDirectionChangementPossibility(levelData.playerData.move);
	updateBobbysDetectionWithSound(levelData.playerData, levelData.bobsPackage, levelData.gameMap, levelData.gameSoundSystem.soundSystem.soundPlayer, demoDataPackage);
	levelData.bobsPackage.spawnBobIfAny(levelData.playerData.move, demoDataPackage);
}

void updateEnemyProtagonists(LevelMandatoryData& levelData, demos::DataPackage* demoDataPackage, PlayerAttributes& playerAttributes)
{
	switch( demos::getGameStatus(demoDataPackage) )
	{
		case demos::GameHasPlayerInputs:
			bothRecordAndStandardPlayingEnemyProtagonists(levelData, demoDataPackage, playerAttributes);
			break;
		case demos::GameIsRecording:
			demos::recordBobbysPackagePosition(levelData.demoType, levelData.bobsPackage, demoDataPackage->spritesPositions.enemyBobsMoves);
			bothRecordAndStandardPlayingEnemyProtagonists(levelData, demoDataPackage, playerAttributes);
			break;
		case demos::GameIsDemo:
			demoGameEnemyUpdate(levelData, demoDataPackage);
			break;
	}
}

void bothRecordAndStandardPlayingEnemyProtagonists(LevelMandatoryData& levelData, demos::DataPackage* demoDataPackage, PlayerAttributes& playerAttributes)
{
	levelData.bobsPackage.animatePackage();
	levelData.bobsPackage.movePackage();
	levelData.bobsPackage.changeDirectionIfAny(levelData.crossRoadsRandoms, levelData.gameMap, levelData.playerData.move);
	levelData.bobsPackage.detectCollisionWithPlayer(levelData.playerData, playerAttributes, levelData.playerData.abilities[abilities::CanEatBob], demoDataPackage);
}

void updateInfoGradient(InfoGradient& infoGradient, Ability& ability)
{
	if( ability.isAbilityActive() )
	{
		infoGradient.updateGradient(ability);
	}
}

void updateWithSoundsEventsStack(LevelMandatoryData& levelData, demos::DataPackage* demoDataPackage)
{
	demos::playSoundIfAny(demoDataPackage, levelData.gameSoundSystem.soundSystem.soundPlayer);
}

void demoGameEnemyUpdate(LevelMandatoryData& levelData, demos::DataPackage* demoDataPackage)
{
	demos::checkNewBobbyPositionEvent(levelData.bobsPackage, demoDataPackage->spritesPositions.enemyBobsMoves);
	levelData.bobsPackage.movePackage();
	levelData.bobsPackage.animatePackage();
	demos::makeBobbysStartMoving(levelData.bobsPackage, demoDataPackage->spritesPositions.enemyBobsMoves, demoDataPackage->haveBobbysStartMoving);
}

void updateBobbysExplosionsIfAny(BobsPackage& bobsPackage, std::size_t explosionFramesNumber)
{
	bobsPackage.updateExplosionIfAny(explosionFramesNumber);
}

void exitDemo(LevelMandatoryData& levelData)
{
	if( levelData.playerInputs.inputsStates.getSdlQuit() || levelData.playerInputs.inputsStates.getEscapeState() )
	{
		levelData.quitLevel = true;
	}
}