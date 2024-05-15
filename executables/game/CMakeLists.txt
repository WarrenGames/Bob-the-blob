cmake_minimum_required( VERSION 3.13 )

project( game LANGUAGES CXX )

set( HEADERS
	sources/demoRecordAndRun/record/recordDemoMenu.h
	sources/demoRecordAndRun/record/recordDemoContext.h
	sources/demoRecordAndRun/play/playDemoContext.h
	sources/demoRecordAndRun/play/playDemoMenu.h
	sources/demoRecordAndRun/saveToFile/saveToDemoFileMenu.h
	sources/demoRecordAndRun/saveToFile/saveToFileContext.h
	sources/miniScreenStart/miniScreenStartContext.h
	sources/miniScreenStart/miniScreenStartMenu.h
	sources/mainMenu/mainMenuContext.h
	sources/mainMenu/mainMenuThings.h
	sources/setupFiles/createFoldersInPrefPath.h
	sources/gameStarting/openLogsFiles.h
	sources/gameStarting/initializeSDL_Modules.h
	sources/gameStarting/openPrefPath.h
	sources/gameStarting/createRenderer.h
	sources/gameStarting/packageEssentials.h
	sources/levelChoiceMenu/levelChoiceThings.h
	sources/levelChoiceMenu/levelChoiceMenuContext.h
	sources/levelChoiceMenu/levelChoiceMenuConsts.h
	sources/levelChoiceMenu/levelsListing.h
	sources/levelChoiceMenu/skillLevelTextsInterface.h
	sources/levelChoiceMenu/skillLevelCursorInterface.h
	sources/consts/gameConsts.h
)

set( SOURCES
	sources/demoRecordAndRun/record/recordDemoMenu.cpp
	sources/demoRecordAndRun/record/recordDemoContext.cpp
	sources/demoRecordAndRun/play/playDemoMenu.cpp
	sources/demoRecordAndRun/play/playDemoContext.cpp
	sources/demoRecordAndRun/saveToFile/saveToFileContext.cpp
	sources/demoRecordAndRun/saveToFile/saveToDemoFileMenu.cpp
	sources/miniScreenStart/miniScreenStartContext.cpp
	sources/miniScreenStart/miniScreenStartMenu.cpp
	sources/mainMenu/mainMenuThings.cpp
	sources/mainMenu/mainMenuContext.cpp
	sources/setupFiles/createFoldersInPrefPath.cpp
	sources/gameStarting/main.cpp
	sources/gameStarting/initializeSDL_Modules.cpp
	sources/gameStarting/createRenderer.cpp
	sources/gameStarting/openPrefPath.cpp
	sources/gameStarting/packageEssentials.cpp
	sources/gameStarting/openLogsFiles.cpp
	sources/levelChoiceMenu/skillLevelCursorInterface.cpp
	sources/levelChoiceMenu/skillLevelTextsInterface.cpp
	sources/levelChoiceMenu/levelChoiceThings.cpp
	sources/levelChoiceMenu/levelsListing.cpp
	sources/levelChoiceMenu/levelChoiceMenuContext.cpp
)

add_executable(	
	${PROJECT_NAME} 
	WIN32
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
	PRIVATE ../../libraries/genericLib/sources
	PRIVATE ../../libraries/sdl2_wrapper/sources
	PRIVATE ../../libraries/soundSystem/sources
	PRIVATE ../../libraries/sdlLogoDisplay/sources
	PRIVATE ../../libraries/commonFiles/sources
	PRIVATE ../../libraries/levelsHints/sources
	PRIVATE ../../libraries/inGame/sources
	PRIVATE ../../libraries/gameOptions/sources
)

target_link_libraries(	
	${PROJECT_NAME}
	PRIVATE inGame
	PRIVATE gameOptions
	PRIVATE levelsHints
	PRIVATE commonFiles
	PRIVATE sdlLogoDisplay
	PRIVATE soundSystem
	PRIVATE sdl2_wrapper
	PRIVATE genericLib
	PRIVATE ${SDL2_LIBRARIES} 
	PRIVATE ${SDL2_IMAGE_LIBRARIES} 
	PRIVATE ${SDL2_TTF_LIBRARIES} 
	PRIVATE ${SDL2_MIXER_LIBRARIES}
)


set_target_properties(
	${PROJECT_NAME} 
	PROPERTIES 
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED YES 
	CXX_EXTENSIONS NO 
	LINKER_LANGUAGE CXX
)
