cmake_minimum_required( VERSION 3.13 )

project( gameOptions LANGUAGES CXX )

set( HEADERS
	sources/gameOptions/gameSettings/gameSettingsContext.h
	sources/gameOptions/gameSettings/gameSettingsInterface.h
	sources/gameOptions/mainMenu/optionsMainMenuGraphisms.h
	sources/gameOptions/optionsContext.h
	sources/gameOptions/consts/optionsConsts.h
	sources/gameOptions/inputs/inputsInterface/globalInterface.h
	sources/gameOptions/inputs/inputsInterface/inputsContext.h
	sources/gameOptions/inputs/joystick/joystickOptions.h
	sources/gameOptions/inputs/keyboard/keyboardOptions.h
)

set( SOURCES
	sources/gameOptions/optionsContext.cpp
	sources/gameOptions/gameSettings/gameSettingsInterface.cpp
	sources/gameOptions/gameSettings/gameSettingsContext.cpp
	sources/gameOptions/mainMenu/optionsMainMenuGraphisms.cpp
	sources/gameOptions/inputs/inputsInterface/globalInterface.cpp
	sources/gameOptions/inputs/inputsInterface/inputsContext.cpp
	sources/gameOptions/inputs/joystick/joystickOptions.cpp
	sources/gameOptions/inputs/keyboard/keyboardOptions.cpp

)

add_library(	
	${PROJECT_NAME} 
	STATIC 
	${SOURCES} 
	${HEADERS} 
	${INC_DIRS}
)

source_group( TREE ${CMAKE_CURRENT_SOURCE_DIR}
	FILES ${HEADERS} ${SOURCES}
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
	PRIVATE ../joystickTests/sources
	PRIVATE ../soundSystem/sources
	PRIVATE ../commonFiles/sources
)

target_link_libraries(
	${PROJECT_NAME} 
	PRIVATE genericLib
	PRIVATE sdl2_wrapper
	PRIVATE joystickTests
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

