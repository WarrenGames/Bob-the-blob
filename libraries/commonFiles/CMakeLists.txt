cmake_minimum_required( VERSION 3.13 )

project( commonFiles LANGUAGES CXX )

set( HEADERS
	sources/exceptions/writeErrorExcept.h
	sources/exceptions/readErrorExcept.h
	sources/pathsFunctions/pathsFunctions.h
	sources/pathsFunctions/getLanguageFromFile.h
	sources/inputsConfig/keyboardInputsConfig.h
	sources/consts/playerInputsConsts.h
	sources/consts/levelsTypesConsts.h
	sources/consts/filesAndPaths.h
	sources/consts/fontsSizes.h
	sources/consts/squareSize.h
	sources/consts/colors.h
	sources/consts/includeOptions.h
	sources/consts/soundsConsts.h
	sources/consts/screenConsts.h
	sources/sounds/gameSoundSystem.h
	sources/sounds/soundConfigFilesPaths.h
	sources/package/essentials.h
	sources/package/inputs.h
)

set( SOURCES
	sources/exceptions/readErrorExcept.cpp
	sources/exceptions/writeErrorExcept.cpp
	sources/pathsFunctions/pathsFunctions.cpp
	sources/pathsFunctions/getLanguageFromFile.cpp
	sources/inputsConfig/keyboardInputsConfig.cpp
	sources/sounds/gameSoundSystem.cpp
	sources/sounds/soundConfigFilesPaths.cpp
	sources/package/inputs.cpp
	sources/package/essentials.cpp
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
)

target_link_libraries(
	${PROJECT_NAME} 
	PRIVATE genericLib
	PRIVATE sdl2_wrapper
	PRIVATE soundSystem
)

set_target_properties(	
	${PROJECT_NAME} 
	PROPERTIES 
	CXX_STANDARD 20 
	CXX_STANDARD_REQUIRED YES 
	CXX_EXTENSIONS ON
	LINKER_LANGUAGE CXX
)

