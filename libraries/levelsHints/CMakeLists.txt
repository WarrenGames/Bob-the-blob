cmake_minimum_required(VERSION 3.13)

project( levelsHints LANGUAGES CXX)

if(UNIX)
	include(GNUInstallDirs)
endif(UNIX)

set(HEADERS
	sources/hintsScreen/mexican/mexicanHintsData.h
	sources/hintsScreen/mexican/mexicanHintScreen.h
	sources/hintsScreen/blueCastle/blueCastleHintsData.h
	sources/hintsScreen/blueCastle/blueCastleHintContext.h
)

set(SOURCES
	sources/hintsScreen/mexican/mexicanHintScreen.cpp
	sources/hintsScreen/mexican/mexicanHintsData.cpp
	sources/hintsScreen/blueCastle/blueCastleHintsData.cpp
	sources/hintsScreen/blueCastle/blueCastleHintContext.cpp
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
