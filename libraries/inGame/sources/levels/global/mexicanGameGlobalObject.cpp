#include "levels/global/mexicanGameGlobalObject.h"
#include "package/essentials.h"
#include "levels/textures/drawing/drawMap.h"
#include "levels/textures/drawing/drawElements.h"
#include "levels/textures/balloons/drawBalloons.h"
#include "levels/playerAttributes/playerAttributes.h"
#include "levels/loadings/gameComponentsLoading.h"
#include "levels/global/updateGame.h"
#include "levels/balloons/updateBalloons.h"
#include "levels/global/actWithBonuses.h"
#include "levels/gameActors/cactus/placeCactusOnMap.h"
#include "demos/data/dataPackage.h"
#include "demos/data/determineGameStatus.h"
#include "levels/gameActors/magicOrbs/handleOrbsCollection.h"
#include "levels/gameActors/magicOrbs/orbsPlayerPower.h"
#include "levels/gameActors/magicOrbs/orbsAndDemos.h"
#include "levels/gameActors/magicOrbs/orbsAndRecording.h"
#include "levels/gameActors/cactus/stackCactiEventsForDemo.h"
#include "pathsFunctions/pathsFunctions.h"
#include "levels/gameActors/playerActorsConsts.h"
#include "levels/maps/mapsConsts.h"
#include "levels/mapSubDivisions/subdivisionsConsts.h"
#include "levels/gameActors/cactus/cactiConsts.h"
#include "levels/textures/texturesConsts.h"
#include "levels/maps/bonusesConsts.h"
#include "consts/filesAndPaths.h"
#include "consts/screenConsts.h"
#include "demos/consts/gameEventsConsts.h"
#include <algorithm>

MexicanGameObject::MexicanGameObject(Essentials& essentials, PlayerAttributes& playerAttributes, const fs::path& levelPrefix, demos::DataPackage* demoDataPackage):
	levelData{ essentials, levelPrefix, demoDataPackage },
	greenOrbs{ essentials.prefPath, bonuses::OrbGreen, map::GreenOrbWorth, files::GreenOrbCreationDelay, files::GreenOrbDurationFile },
	mexicanTextures{ essentials.logs, essentials.rndWnd },
	mexicanSprites{ mexicanTextures },
	balloonsPack{ essentials.logs, essentials.rndWnd },
	mexicanInfosPanel{essentials, playerAttributes, levelData.bonusesMap}
{
	loadCactiPositions(demoDataPackage);
	recordCactiPositions(demoDataPackage);
	essentials.logs.error.flushLog();
	essentials.logs.warning.flushLog();
}

bool MexicanGameObject::wasLoadingPerfect() const
{
	return levelData.isLoadingPerfect && mexicanTextures.wasLoadingPerfect() && balloonsPack.loadedTextures.wasLoadingPerfect();
}

void MexicanGameObject::drawLevel(sdl2::RendererWindow& rndWnd)
{
	drawMapTransparentWallsBackground(rndWnd, mexicanSprites.mapSprites, levelData.gameMap, levelData.screenScrolling);
	drawMap(rndWnd, mexicanSprites.mapSprites, levelData.gameMap, levelData.screenScrolling);
	drawBonuses(rndWnd, mexicanSprites.commonSprites, levelData.bonusesMap, levelData.screenScrolling);
	drawMexicanBobs(rndWnd, mexicanSprites.bobSprites, mexicanSprites.hatSprite, levelData.bobsPackage, levelData.playerData.abilities[abilities::CanEatBob], levelData.screenScrolling);
	drawPlayerMoving(rndWnd, mexicanSprites.commonSprites.playerSprites, levelData.playerData, levelData.screenScrolling);
	drawBobsLightBulbs(rndWnd, mexicanSprites.commonSprites.lightBulbSprites, levelData.bobsPackage, levelData.screenScrolling);
	drawCacti(rndWnd, mexicanSprites.cactiSprites, cactiPackage, levelData.screenScrolling);
	drawOrbs(rndWnd, mexicanSprites.commonSprites.magicOrbSprites, greenOrbs, levelData.screenScrolling);
	drawBlueSmokeExplosion(rndWnd, mexicanSprites.commonSprites.blueSmokeSprites, levelData.bobsPackage, levelData.screenScrolling);
	drawBalloonsIfAny(rndWnd, balloonsPack.sprites, levelData.balloonsPositions);
	mexicanInfosPanel.drawEverything(rndWnd);
	drawRosterGradient(rndWnd, mexicanSprites.commonSprites.bobsCanBeEatenIcon, mexicanInfosPanel.canBeEatenBobsGradient, levelData.playerData.abilities[abilities::CanEatBob] );
	drawRosterGradient(rndWnd, mexicanSprites.cactiCanBeEatenIcon, mexicanInfosPanel.canBeEatenCactiGradient, levelData.playerData.abilities[abilities::CanEatCacti] );
	levelData.displayLevelEndMessage(rndWnd);
}

void MexicanGameObject::updateGame(Essentials& essentials, PlayerAttributes& playerAttributes, demos::DataPackage* demoDataPackage)
{
	update(essentials, playerAttributes, levelData, mexicanInfosPanel.scoreDisplay, demoDataPackage);
	levelData.actWithLevelEnd(demoDataPackage, isLevelComplete() );
	updateGreenOrbs(playerAttributes, demoDataPackage);
	updateMexicanBalloons(levelData, greenOrbs);
	updateInfoGradient(mexicanInfosPanel.canBeEatenBobsGradient, levelData.playerData.abilities[abilities::CanEatBob] );
	updateInfoGradient(mexicanInfosPanel.canBeEatenCactiGradient, levelData.playerData.abilities[abilities::CanEatCacti] );
	updateBonusesAnimation(levelData.bonusesMap, mexicanSprites.commonSprites);
	mexicanInfosPanel.goldIngotsCountDisplay.updateText(essentials, levelData.bonusesMap.getElementNumber(bonuses::BonusGoldIngot) );
	updateBobbysExplosionsIfAny(levelData.bobsPackage, mexicanSprites.commonSprites.blueSmokeSprites.size() );
}

void MexicanGameObject::updateGreenOrbs(PlayerAttributes& playerAttributes, demos::DataPackage* demoDataPackage)
{
	switch( demos::getGameStatus(demoDataPackage) )
	{
		case demos::GameHasPlayerInputs:
			browseColoredOrbCollection(levelData, greenOrbs, playerAttributes, demoDataPackage, abilities::CanEatCacti);
			cactiPackage.detectCollisionWithPlayer(levelData.playerData, playerAttributes, levelData.bobsPackage);
			break;
		case demos::GameIsRecording:
			browseColoredOrbCollection(levelData, greenOrbs, playerAttributes, demoDataPackage, abilities::CanEatCacti);
			cactiPackage.detectCollisionWithPlayer(levelData.playerData, playerAttributes, levelData.bobsPackage);
			recordOrb::stackOrbCreationAccordingToColorIndex(greenOrbs, demoDataPackage);
			recordOrb::stackOrbDestructionAccordingToColorIndex(greenOrbs, demoDataPackage);
			recordOrb::stackOrbPowerForPlayer(levelData.playerData.abilities, demoDataPackage->greenOrbRelatedItemsData.greenOrbsAndPlayer, 
												abilities::CanEatCacti, demos::playerPower::GreenOrb );
			recordCactiEvents::stackCactusEvent(cactiPackage, demoDataPackage->greenOrbRelatedItemsData.cactiLife);
			break;
		case demos::GameIsDemo:
			demosOrb::createOrbAccordingToColorIndex(greenOrbs, demoDataPackage);
			demosOrb::destroyOrbAccordingToColorIndex(greenOrbs, demoDataPackage);
			greenOrb::checkForPowerEvent(levelData.playerData, playerAttributes, demoDataPackage);
			demosCactiEvents::actWithCactiEvents(cactiPackage, demoDataPackage->greenOrbRelatedItemsData.cactiLife, levelData.playerData, playerAttributes, levelData.bobsPackage);
			break;
	}
}

bool MexicanGameObject::hasPlayerRequestedToExit() const
{
	return levelData.playerInputs.inputsStates.escapeState || levelData.playerInputs.inputsStates.sdlQuitState;
}

void MexicanGameObject::loadCactiPositions(const demos::DataPackage* demoDataPackage)
{
	switch( demos::getGameStatus(demoDataPackage) )
	{
		case demos::GameIsRecording:
			cacti::placeCactiInAllZones(cacti::PerZoneCactiNumber, levelData.zonesFences, cactiPackage, levelData.playerData.playerStartingPosition);
			break;
		case demos::GameIsDemo:
			demoDataPackage->spritesPositions.setCactiStartingPositions(cactiPackage);
			break;
		case demos::GameHasPlayerInputs:
			cacti::placeCactiInAllZones(cacti::PerZoneCactiNumber, levelData.zonesFences, cactiPackage, levelData.playerData.playerStartingPosition);
			break;
	}
}

void MexicanGameObject::recordCactiPositions(demos::DataPackage* demoDataPackage) const
{
	if( demos::getGameStatus(demoDataPackage) == demos::GameIsRecording )
	{
		demoDataPackage->spritesPositions.recordCactiStartingPositions(cactiPackage);
	}
}

bool MexicanGameObject::isLevelComplete() const
{
	return levelData.bonusesMap.getElementNumber(bonuses::BonusGoldIngot) == 0 
		&& std::all_of( std::cbegin(cactiPackage), std::cend(cactiPackage), [](auto const &cactus){ return cactus.isEffective == false; } );
}