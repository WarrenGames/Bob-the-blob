cmake_minimum_required( VERSION 3.13 )

project( gameOptions LANGUAGES CXX )

set( HEADERS
	sources/gameOptions/gameSettings/gameSettingsContext.h
	sources/gameOptions/gameSettings/gameSettingsInterface.h
	sources/gameOptions/joystick/joystickOptions.h
	sources/gameOptions/mainMenu/optionsMainMenuGraphisms.h
	sources/gameOptions/optionsContext.h
	sources/gameOptions/keyboard/keyboardContext.h
	sources/gameOptions/keyboard/keyboardOptions.h
	sources/gameOptions/consts/optionsConsts.h
)

set( SOURCES
	sources/gameOptions/optionsContext.cpp
	sources/gameOptions/gameSettings/gameSettingsInterface.cpp
	sources/gameOptions/gameSettings/gameSettingsContext.cpp
	sources/gameOptions/joystick/joystickOptions.cpp
	sources/gameOptions/mainMenu/optionsMainMenuGraphisms.cpp
	sources/gameOptions/keyboard/keyboardOptions.cpp
	sources/gameOptions/keyboard/keyboardContext.cpp
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
	PRIVATE ${WARREN_LIBS_INCLUDES_PATH}/soundSystem
	PRIVATE ../commonFiles/sources
)

target_link_libraries(
	${PROJECT_NAME} 
	PRIVATE genericLib
	PRIVATE sdl2_wrapper
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

