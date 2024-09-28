cmake_minimum_required(VERSION 3.13)

project( graphicalTextParagraph LANGUAGES CXX)

if(UNIX)
	include(GNUInstallDirs)
endif(UNIX)

set(HEADERS
	sources/paragraph/makeTextTextures.h
	sources/paragraph/paragraphData.h
)

set(SOURCES
	sources/paragraph/makeTextTextures.cpp
	sources/paragraph/paragraphData.cpp
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
	PRIVATE sources
	PRIVATE ../genericLib/sources
	PRIVATE ../sdl2_wrapper/sources
)

target_link_libraries(	
	${PROJECT_NAME} 
	PRIVATE ${SDL2_LIBRARIES} 
	PRIVATE ${SDL2_IMAGE_LIBRARIES} 
	PRIVATE ${SDL2_TTF_LIBRARIES} 
	PRIVATE genericLib
	PRIVATE sdl2_wrapper
)

set_target_properties(	
	${PROJECT_NAME} 
	PROPERTIES 
	CXX_STANDARD 20 
	CXX_STANDARD_REQUIRED YES 
	CXX_EXTENSIONS ON
	LINKER_LANGUAGE CXX
)

install( DIRECTORY sources/ DESTINATION includes/graphicalTextParagraph FILES_MATCHING PATTERN "*.h" )

install(
	TARGETS ${PROJECT_NAME}
	LIBRARY DESTINATION ${BuiltSharedLibsDir}
	ARCHIVE DESTINATION ${BuiltStaticLibsDir}
)