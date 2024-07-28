cmake_minimum_required( VERSION 3.13 )

project( inGame LANGUAGES CXX )

set( HEADERS
	sources/levels/textures/infosPanel/stdLevelInfosPanel.h
	sources/levels/textures/infosPanel/infoGradient.h
	sources/levels/textures/infosPanel/givenElementCount.h
	sources/levels/textures/infosPanel/infosBoard.h
	sources/levels/textures/infosPanel/mexicanInfosPanel.h
	sources/levels/textures/mexicanThings/mexicanSprites.h
	sources/levels/textures/mexicanThings/mexicanTextureLoader.h
	sources/levels/textures/standardLevel/texturesSprites.h
	sources/levels/textures/standardLevel/texturesLoader.h
	sources/levels/textures/itemsCountConsts.h
	sources/levels/textures/mappingTextures/mappingSprites.h
	sources/levels/textures/mappingTextures/mappingTextures.h
	sources/levels/textures/common/commonSprite.h
	sources/levels/textures/common/commonLoading.h
	sources/levels/textures/balloonsConsts.h
	sources/levels/textures/gradients.h
	sources/levels/textures/balloons/balloonsSprites.h
	sources/levels/textures/balloons/drawBalloons.h
	sources/levels/textures/balloons/balloonsPack.h
	sources/levels/textures/balloons/balloonsTexturesLoader.h
	sources/levels/textures/drawing/drawElements.h
	sources/levels/textures/drawing/drawMap.h
	sources/levels/textures/drawing/screenScrolling.h
	sources/levels/textures/drawing/explosionInfos.h
	sources/levels/textures/drawing/scoreDisplay.h
	sources/levels/textures/drawing/inferDrawingPosition.h
	sources/levels/textures/drawing/axisScrolling.h
	sources/levels/textures/blueBricksThings/blueBricksTextures.h
	sources/levels/textures/blueBricksThings/blueBricksSprites.h
	sources/levels/textures/texturesConsts.h
	sources/levels/textures/mexicanTexturesConsts.h
	sources/levels/demos/joinTimePoints.h
	sources/levels/demos/transferDemoStacks.h
	sources/levels/demos/updatePlayerWithDemoData.h
	sources/levels/demos/updateEnemiesWithDemoData.h
	sources/levels/demos/soundsEventsWithDemos.h
	sources/levels/demos/initializeDemoStacks.h
	sources/levels/demos/actWithDemoGameEvents.h
	sources/levels/monstersMoves/collisionBetweenPlayerAndBobs.h
	sources/levels/monstersMoves/pathFinder.h
	sources/levels/monstersMoves/pathElement.h
	sources/levels/monstersMoves/detectingPlayer.h
	sources/levels/monstersMoves/crossRoadsRandoms.h
	sources/levels/monstersMoves/monstersMovesConsts.h
	sources/levels/maps/bonusesConsts.h
	sources/levels/maps/bonusesAnimation.h
	sources/levels/maps/gameMap.h
	sources/levels/maps/loadMapFromFile.h
	sources/levels/maps/bonusesMap.h
	sources/levels/maps/mapsConsts.h
	sources/levels/maps/bonusElement.h
	sources/levels/maps/mapElements.h
	sources/levels/maps/loadPlayerPosition.h
	sources/levels/maps/readBonusesPositionsAndProperties.h
	sources/levels/playerAttributes/playerAttributes.h
	sources/levels/global/levelMandatoryData.h
	sources/levels/global/actWithBonuses.h
	sources/levels/global/gameGlobalObject.h
	sources/levels/global/updateProtagonistsMoves.h
	sources/levels/global/mexicanGameGlobalObject.h
	sources/levels/global/updateGame.h
	sources/levels/mapSubDivisions/loadSubdivisionData.h
	sources/levels/mapSubDivisions/subDivFileData.h
	sources/levels/mapSubDivisions/zoneFences.h
	sources/levels/mapSubDivisions/functions/cutZones.h
	sources/levels/mapSubDivisions/coordinatesSet.h
	sources/levels/mapSubDivisions/subdivisionsConsts.h
	sources/levels/animation/spriteAnimation.h
	sources/levels/demosRecordingAndPlaying/demosFiles/demoConfigFiles.h
	sources/levels/demosRecordingAndPlaying/demosFiles/loadDataFromFile.h
	sources/levels/demosRecordingAndPlaying/demosFiles/saveDataToFile.h
	sources/levels/demosRecordingAndPlaying/consts/demoConfigFilesConsts.h
	sources/levels/demosRecordingAndPlaying/consts/gameEventsConsts.h
	sources/levels/demosRecordingAndPlaying/consts/dataRecordingConsts.h
	sources/levels/demosRecordingAndPlaying/consts/demosConsts.h
	sources/levels/demosRecordingAndPlaying/templates/stacksAlgorithms.h
	sources/levels/demosRecordingAndPlaying/templates/demoStack.h
	sources/levels/demosRecordingAndPlaying/data/greenOrbDemosData.h
	sources/levels/demosRecordingAndPlaying/data/positionElements.h
	sources/levels/demosRecordingAndPlaying/data/recordedInputsPlayerData.h
	sources/levels/demosRecordingAndPlaying/data/recordedMapElements.h
	sources/levels/demosRecordingAndPlaying/data/dataPackage.h
	sources/levels/demosRecordingAndPlaying/data/determineGameStatus.h
	sources/levels/demosRecordingAndPlaying/dataToRecord/playerMove.h
	sources/levels/demosRecordingAndPlaying/dataToRecord/soundPlaying.h
	sources/levels/demosRecordingAndPlaying/dataToRecord/moveAndPosition.h
	sources/levels/demosRecordingAndPlaying/dataToRecord/itemData.h
	sources/levels/demosRecordingAndPlaying/dataToRecord/gameEvents.h
	sources/levels/demosRecordingAndPlaying/dataToRecord/actionData.h
	sources/levels/demosRecordingAndPlaying/dataToRecord/startingPositions.h
	sources/levels/gameContexts/levelContext.h
	sources/levels/gameContexts/mexicanZone.h
	sources/levels/levelFinish/levelFinishConsts.h
	sources/levels/levelFinish/levelFinishInterface.h
	sources/levels/gameActors/playerThings/playerMoving.h
	sources/levels/gameActors/playerThings/playerMapRelativeAbilities.h
	sources/levels/gameActors/playerThings/characterAbility.h
	sources/levels/gameActors/playerThings/singlePlayerData.h
	sources/levels/gameActors/bobThings/bobTheBlob.h
	sources/levels/gameActors/bobThings/bobsPackage.h
	sources/levels/gameActors/bobThings/globalBob.h
	sources/levels/gameActors/playerActorsConsts.h
	sources/levels/gameActors/cactus/stackCactiEventsForDemo.h
	sources/levels/gameActors/cactus/cactiConsts.h
	sources/levels/gameActors/cactus/cactiPackage.h
	sources/levels/gameActors/cactus/placeCactusOnMap.h
	sources/levels/gameActors/cactus/cactusObstacle.h
	sources/levels/gameActors/magicOrbs/handleOrbsCollection.h
	sources/levels/gameActors/magicOrbs/orbsAndRecording.h
	sources/levels/gameActors/magicOrbs/orbsPackage.h
	sources/levels/gameActors/magicOrbs/orbsAndDemos.h
	sources/levels/gameActors/magicOrbs/singleOrb.h
	sources/levels/gameActors/magicOrbs/orbsPlayerPower.h
	sources/levels/benchmarks/benchTypes.h
	sources/levels/benchmarks/benchmarkObject.h
	sources/levels/benchmarks/outputBenchmarkData.h
	sources/levels/balloons/balloonInfo.h
	sources/levels/balloons/updateBalloons.h
	sources/levels/balloons/balloonsPositionsData.h
	sources/levels/loadings/gameConfigurationData.h
	sources/levels/loadings/getConfigFileNumber.h
	sources/levels/loadings/readStartPositionInFile.h
	sources/levels/loadings/gameComponentsLoading.h
	sources/levels/inputs/eventsRecording.h
	sources/levels/inputs/playerInputs.h
	sources/levels/inputs/inputsStates.h
)

set( SOURCES
	sources/levels/textures/infosPanel/infosBoard.cpp
	sources/levels/textures/infosPanel/stdLevelInfosPanel.cpp
	sources/levels/textures/infosPanel/infoGradient.cpp
	sources/levels/textures/infosPanel/givenElementCount.cpp
	sources/levels/textures/infosPanel/mexicanInfosPanel.cpp
	sources/levels/textures/mexicanThings/mexicanSprites.cpp
	sources/levels/textures/mexicanThings/mexicanTextureLoader.cpp
	sources/levels/textures/standardLevel/texturesSprites.cpp
	sources/levels/textures/standardLevel/texturesLoader.cpp
	sources/levels/textures/mappingTextures/mappingSprites.cpp
	sources/levels/textures/mappingTextures/mappingTextures.cpp
	sources/levels/textures/common/commonSprite.cpp
	sources/levels/textures/common/commonLoading.cpp
	sources/levels/textures/balloons/drawBalloons.cpp
	sources/levels/textures/balloons/balloonsTexturesLoader.cpp
	sources/levels/textures/balloons/balloonsSprites.cpp
	sources/levels/textures/balloons/balloonsPack.cpp
	sources/levels/textures/drawing/screenScrolling.cpp
	sources/levels/textures/drawing/drawElements.cpp
	sources/levels/textures/drawing/inferDrawingPosition.cpp
	sources/levels/textures/drawing/explosionInfos.cpp
	sources/levels/textures/drawing/scoreDisplay.cpp
	sources/levels/textures/drawing/drawMap.cpp
	sources/levels/textures/drawing/axisScrolling.cpp
	sources/levels/textures/blueBricksThings/blueBricksSprites.cpp
	sources/levels/textures/blueBricksThings/blueBricksTextures.cpp
	sources/levels/demos/updateEnemiesWithDemoData.cpp
	sources/levels/demos/transferDemoStacks.cpp
	sources/levels/demos/initializeDemoStacks.cpp
	sources/levels/demos/updatePlayerWithDemoData.cpp
	sources/levels/demos/soundsEventsWithDemos.cpp
	sources/levels/demos/actWithDemoGameEvents.cpp
	sources/levels/demos/joinTimePoints.cpp
	sources/levels/monstersMoves/detectingPlayer.cpp
	sources/levels/monstersMoves/crossRoadsRandoms.cpp
	sources/levels/monstersMoves/collisionBetweenPlayerAndBobs.cpp
	sources/levels/monstersMoves/pathElement.cpp
	sources/levels/monstersMoves/pathFinder.cpp
	sources/levels/maps/gameMap.cpp
	sources/levels/maps/loadMapFromFile.cpp
	sources/levels/maps/mapElements.cpp
	sources/levels/maps/bonusElement.cpp
	sources/levels/maps/bonusesMap.cpp
	sources/levels/maps/bonusesAnimation.cpp
	sources/levels/maps/loadPlayerPosition.cpp
	sources/levels/maps/readBonusesPositionsAndProperties.cpp
	sources/levels/playerAttributes/playerAttributes.cpp
	sources/levels/global/mexicanGameGlobalObject.cpp
	sources/levels/global/updateGame.cpp
	sources/levels/global/gameGlobalObject.cpp
	sources/levels/global/levelMandatoryData.cpp
	sources/levels/global/actWithBonuses.cpp
	sources/levels/global/updateProtagonistsMoves.cpp
	sources/levels/mapSubDivisions/subDivFileData.cpp
	sources/levels/mapSubDivisions/zoneFences.cpp
	sources/levels/mapSubDivisions/functions/cutZones.cpp
	sources/levels/mapSubDivisions/loadSubdivisionData.cpp
	sources/levels/mapSubDivisions/coordinatesSet.cpp
	sources/levels/animation/spriteAnimation.cpp
	sources/levels/demosRecordingAndPlaying/demosFiles/saveDataToFile.cpp
	sources/levels/demosRecordingAndPlaying/demosFiles/loadDataFromFile.cpp
	sources/levels/demosRecordingAndPlaying/demosFiles/demoConfigFiles.cpp
	sources/levels/demosRecordingAndPlaying/data/determineGameStatus.cpp
	sources/levels/demosRecordingAndPlaying/data/positionElements.cpp
	sources/levels/demosRecordingAndPlaying/data/dataPackage.cpp
	sources/levels/demosRecordingAndPlaying/data/greenOrbDemosData.cpp
	sources/levels/demosRecordingAndPlaying/data/recordedInputsPlayerData.cpp
	sources/levels/demosRecordingAndPlaying/data/recordedMapElements.cpp
	sources/levels/demosRecordingAndPlaying/dataToRecord/moveAndPosition.cpp
	sources/levels/demosRecordingAndPlaying/dataToRecord/actionData.cpp
	sources/levels/demosRecordingAndPlaying/dataToRecord/playerMove.cpp
	sources/levels/demosRecordingAndPlaying/dataToRecord/itemData.cpp
	sources/levels/demosRecordingAndPlaying/dataToRecord/soundPlaying.cpp
	sources/levels/demosRecordingAndPlaying/dataToRecord/startingPositions.cpp
	sources/levels/demosRecordingAndPlaying/dataToRecord/gameEvents.cpp
	sources/levels/gameContexts/mexicanZone.cpp
	sources/levels/gameContexts/levelContext.cpp
	sources/levels/levelFinish/levelFinishInterface.cpp
	sources/levels/gameActors/playerThings/characterAbility.cpp
	sources/levels/gameActors/playerThings/singlePlayerData.cpp
	sources/levels/gameActors/playerThings/playerMapRelativeAbilities.cpp
	sources/levels/gameActors/playerThings/playerMoving.cpp
	sources/levels/gameActors/bobThings/bobsPackage.cpp
	sources/levels/gameActors/bobThings/globalBob.cpp
	sources/levels/gameActors/bobThings/bobTheBlob.cpp
	sources/levels/gameActors/cactus/stackCactiEventsForDemo.cpp
	sources/levels/gameActors/cactus/placeCactusOnMap.cpp
	sources/levels/gameActors/cactus/cactusObstacle.cpp
	sources/levels/gameActors/cactus/cactiPackage.cpp
	sources/levels/gameActors/magicOrbs/handleOrbsCollection.cpp
	sources/levels/gameActors/magicOrbs/orbsAndRecording.cpp
	sources/levels/gameActors/magicOrbs/orbsPlayerPower.cpp
	sources/levels/gameActors/magicOrbs/singleOrb.cpp
	sources/levels/gameActors/magicOrbs/orbsPackage.cpp
	sources/levels/gameActors/magicOrbs/orbsAndDemos.cpp
	sources/levels/benchmarks/benchmarkObject.cpp
	sources/levels/benchmarks/outputBenchmarkData.cpp
	sources/levels/benchmarks/benchTypes.cpp
	sources/levels/balloons/balloonInfo.cpp
	sources/levels/balloons/balloonsPositionsData.cpp
	sources/levels/balloons/updateBalloons.cpp
	sources/levels/loadings/readStartPositionInFile.cpp
	sources/levels/loadings/gameConfigurationData.cpp
	sources/levels/loadings/getConfigFileNumber.cpp
	sources/levels/loadings/gameComponentsLoading.cpp
	sources/levels/inputs/inputsStates.cpp
	sources/levels/inputs/playerInputs.cpp
	sources/levels/inputs/eventsRecording.cpp
)

add_library(	
	${PROJECT_NAME} 
	STATIC 
	${SOURCES} 
	${HEADERS} 
	${INC_DIRS}
)

target_include_directories(
	${PROJECT_NAME}
	PRIVATE ${SDL2_INCLUDE_DIRS}
	PRIVATE ${SDL2_IMAGE_INCLUDE_DIRS}
	PRIVATE ${SDL2_TTF_INCLUDE_DIRS}
	PRIVATE ${SDL2_MIXER_INCLUDE_DIRS}
	PRIVATE sources
	PRIVATE ../genericLib/sources
	PRIVATE ../sdl2_wrapper/sources
	PRIVATE ../soundSystem/sources
	PRIVATE ../commonFiles/sources
)

target_link_libraries(
	${PROJECT_NAME} 
	PRIVATE genericLib
	PRIVATE sdl2_wrapper
	PRIVATE soundSystem
	PRIVATE commonFiles
)

set_target_properties(	
	${PROJECT_NAME} 
	PROPERTIES 
	CXX_STANDARD 20 
	CXX_STANDARD_REQUIRED YES 
	CXX_EXTENSIONS ON
	LINKER_LANGUAGE CXX
)

