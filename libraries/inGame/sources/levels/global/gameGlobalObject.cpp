#include "levels/global/gameGlobalObject.h"
#include "package/essentials.h"
#include "levels/textures/drawing/drawMap.h"
#include "levels/textures/drawing/drawElements.h"
#include "levels/textures/balloons/drawBalloons.h"
#include "levels/global/updateGame.h"
#include "levels/global/actWithBonuses.h"
#include "levels/balloons/updateBalloons.h"
#include "levels/loadings/gameComponentsLoading.h"
#include "pathsFunctions/pathsFunctions.h"
#include "levels/maps/mapsConsts.h"
#include "levels/gameActors/playerActorsConsts.h"
#include "levels/maps/bonusesConsts.h"
#include "consts/playerInputsConsts.h"
#include "consts/includeOptions.h"
#include "consts/filesAndPaths.h"
#include "consts/screenConsts.h"

GameGlobalObject::GameGlobalObject(Essentials& essentials, PlayerAttributes& playerAttributes, const fs::path& levelPrefix, demos::DataPackage* demoDataPackage):
	levelData{ essentials, playerAttributes, levelPrefix, demoDataPackage },
	texturesLoader{ essentials.logs, essentials.rndWnd },
	texturesSprites{ texturesLoader },
	balloonsPack{ essentials.logs, essentials.rndWnd },
	infosPanel{ essentials, playerAttributes, levelData.bonusesMap }
{
	essentials.logs.error.flushLog();
	essentials.logs.warning.flushLog();
}

bool GameGlobalObject::wasLoadingPerfect() const
{
	return levelData.isLoadingPerfect && texturesLoader.wasLoadingPerfect() && balloonsPack.loadedTextures.wasLoadingPerfect();
}

void GameGlobalObject::drawLevel(sdl2::RendererWindow& rndWnd)
{
	drawMap(rndWnd, texturesSprites.mapSprites, levelData.gameMap, levelData.screenScrolling);
	drawBonuses(rndWnd, texturesSprites.commonSprites, levelData.bonusesMap, levelData.screenScrolling);
	drawBobs(rndWnd, texturesSprites.blobSprites, levelData.bobsPackage, levelData.playerData.abilities[abilities::CanEatBob], levelData.screenScrolling);
	drawPlayerMoving(rndWnd, texturesSprites.commonSprites.playerSprites, levelData.playerData, levelData.screenScrolling);
	drawBobsLightBulbs(rndWnd, texturesSprites.commonSprites.lightBulbSprites, levelData.bobsPackage, levelData.screenScrolling);
	drawBlueSmokeExplosion(rndWnd, texturesSprites.commonSprites.blueSmokeSprites, levelData.bobsPackage, levelData.screenScrolling);
	drawBalloonsIfAny(rndWnd, balloonsPack.sprites, levelData.balloonsPositions);
	infosPanel.drawEverything(rndWnd);
	drawRosterGradient(rndWnd, texturesSprites.commonSprites.bobsCanBeEatenIcon, infosPanel.canBeEatenBobsGradient, levelData.playerData.abilities[abilities::CanEatBob] );
	levelData.displayLevelEndMessage(rndWnd);
}

void GameGlobalObject::updateGame(Essentials& essentials, PlayerAttributes& playerAttributes, demos::DataPackage* demoDataPackage)
{
	update(essentials, playerAttributes, levelData, infosPanel.scoreDisplay, demoDataPackage);
	levelData.actWithLevelEnd(demoDataPackage, isLevelComplete() );
	updateBalloons(levelData);//Can be a different function according to level items and level theme
	updateInfoGradient(infosPanel.canBeEatenBobsGradient, levelData.playerData.abilities[abilities::CanEatBob] );
	updateBonusesAnimation(levelData.bonusesMap, texturesSprites.commonSprites);
	infosPanel.goldIngotsCountDisplay.updateText(essentials, levelData.bonusesMap.getElementNumber(bonuses::BonusGoldIngot) );
	updateBobbysExplosionsIfAny(levelData.bobsPackage, texturesSprites.commonSprites.blueSmokeSprites.size() );
}

bool GameGlobalObject::hasPlayerRequestedToExit() const
{
	return levelData.playerInputs.inputsStates.getEscapeState() || levelData.playerInputs.inputsStates.getSdlQuit();
}

bool GameGlobalObject::isLevelComplete() const
{
	return levelData.bonusesMap.getElementNumber(bonuses::BonusGoldIngot) == 0;
}