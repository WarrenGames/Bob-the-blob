cmake_minimum_required( VERSION 3.13 )

project( hintsScreens LANGUAGES CXX )

set(HEADERS
	sources/hints/mainMenu/hintsMainMenuContext.h
	sources/hints/mainMenu/hintsMainMenuElements.h
	sources/hints/fleeFoes/fleeFoesHintScreenContext.h
	sources/hints/fleeFoes/fleeFoesHintScreenElements.h
)

set(SOURCES
	sources/hints/mainMenu/hintsMainMenuElements.cpp
	sources/hints/mainMenu/hintsMainMenuContext.cpp
	sources/hints/fleeFoes/fleeFoesHintScreenContext.cpp
	sources/hints/fleeFoes/fleeFoesHintScreenElements.cpp
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
	PRIVATE sources
	PRIVATE ../genericLib/sources
	PRIVATE ../sdl2_wrapper/sources
	PRIVATE ../graphicalTextParagraph/sources
	PRIVATE ../commonFiles/sources
	PRIVATE ../inGame/sources
)

target_link_libraries(	
	${PROJECT_NAME} 
	PRIVATE genericLib
	PRIVATE sdl2_wrapper
	PRIVATE commonFiles
	PRIVATE inGame
	PRIVATE graphicalTextParagraph
)

set_target_properties(	
	${PROJECT_NAME} 
	PROPERTIES 
	CXX_STANDARD 20 
	CXX_STANDARD_REQUIRED YES 
	CXX_EXTENSIONS ON
	LINKER_LANGUAGE CXX
)