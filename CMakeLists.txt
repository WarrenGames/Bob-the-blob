cmake_minimum_required(VERSION 3.13)

project( BobTheBlob LANGUAGES CXX )

if( DEFINED SQUARE_SIZE )
	file( WRITE "libraries/commonFiles/sources/consts/squareSize.h" "constexpr int SQR_SIZE = ${SQUARE_SIZE};" )
	message( WARNING "You defined the SQUARE_SIZE value as: ${SQUARE_SIZE}" )
else()
	file( WRITE "libraries/commonFiles/sources/consts/squareSize.h" "constexpr int SQR_SIZE = 64;" )
	message( WARNING "SQUARE_SIZE value is set to default: 64" )
	set( SQUARE_SIZE 64 )
endif()

set( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmakeModules)

if( UNIX )
	include(GNUInstallDirs)
endif( UNIX )

if(WIN32)
    set( SDL2_DIR "" )
endif(WIN32)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

add_subdirectory(executables/game)
add_subdirectory(libraries/commonFiles)
add_subdirectory(libraries/levelsHints)
add_subdirectory(libraries/gameOptions)
add_subdirectory(libraries/inGame)
add_subdirectory(libraries/genericLib)
add_subdirectory(libraries/sdl2_wrapper)
add_subdirectory(libraries/sdlLogoDisplay)
add_subdirectory(libraries/soundSystem)

if(UNIX)
	include(GNUInstallDirs)
	install( 
		TARGETS 
			game
		RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT Runtime
	)
else()
	install( 
		TARGETS 
			game
		RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX} COMPONENT Runtime
	)
endif(UNIX)