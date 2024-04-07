cmake_minimum_required( VERSION 3.13 )

project( demos LANGUAGES CXX )

set( HEADERS
	sources/demos/demosFiles/demoConfigFiles.h
	sources/demos/demosFiles/loadDataFromFile.h
	sources/demos/demosFiles/saveDataToFile.h
	sources/demos/consts/demoConfigFilesConsts.h
	sources/demos/consts/gameEventsConsts.h
	sources/demos/consts/dataRecordingConsts.h
	sources/demos/consts/demosConsts.h
	sources/demos/templates/stacksAlgorithms.h
	sources/demos/templates/demoStack.h
	sources/demos/data/greenOrbDemosData.h
	sources/demos/data/positionElements.h
	sources/demos/data/recordedInputsPlayerData.h
	sources/demos/data/recordedMapElements.h
	sources/demos/data/dataPackage.h
	sources/demos/data/determineGameStatus.h
	sources/demos/dataToRecord/playerMove.h
	sources/demos/dataToRecord/soundPlaying.h
	sources/demos/dataToRecord/moveAndPosition.h
	sources/demos/dataToRecord/itemData.h
	sources/demos/dataToRecord/gameEvents.h
	sources/demos/dataToRecord/actionData.h
	sources/demos/dataToRecord/startingPositions.h
)

set( SOURCES
	sources/demos/demosFiles/saveDataToFile.cpp
	sources/demos/demosFiles/loadDataFromFile.cpp
	sources/demos/demosFiles/demoConfigFiles.cpp
	sources/demos/data/determineGameStatus.cpp
	sources/demos/data/positionElements.cpp
	sources/demos/data/dataPackage.cpp
	sources/demos/data/greenOrbDemosData.cpp
	sources/demos/data/recordedInputsPlayerData.cpp
	sources/demos/data/recordedMapElements.cpp
	sources/demos/dataToRecord/moveAndPosition.cpp
	sources/demos/dataToRecord/actionData.cpp
	sources/demos/dataToRecord/playerMove.cpp
	sources/demos/dataToRecord/itemData.cpp
	sources/demos/dataToRecord/soundPlaying.cpp
	sources/demos/dataToRecord/startingPositions.cpp
	sources/demos/dataToRecord/gameEvents.cpp
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
	PRIVATE ${WARREN_LIBS_INCLUDES_PATH}/genericLib
	PRIVATE ${WARREN_LIBS_INCLUDES_PATH}/sdl2_wrapper
	PRIVATE ../../libraries/commonFiles/sources
	PRIVATE ../../libraries/inGame/sources
)

target_link_libraries(
	${PROJECT_NAME} 
	PRIVATE genericLib
	PRIVATE sdl2_wrapper
	PRIVATE commonFiles
	PRIVATE inGame
)

set_target_properties(	
	${PROJECT_NAME} 
	PROPERTIES 
	CXX_STANDARD 20 
	CXX_STANDARD_REQUIRED YES 
	CXX_EXTENSIONS ON
	LINKER_LANGUAGE CXX
)