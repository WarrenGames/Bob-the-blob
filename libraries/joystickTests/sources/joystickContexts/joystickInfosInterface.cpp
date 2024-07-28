#include "joystickContexts/joystickInfosInterface.h"
#include "joystickData/joystickGraphicsValues.h"
#include "joystickData/joystickCalibr.h"
#include "text/sdl2ttf_font.h"
#include "texturing/texturesCombo.h"
#include "texturing/texturePosition.h"
#include "texturing/rendererWindow.h"
#include "logging/logsStruct.h"

constexpr SDL_Color BlackCol = { 0, 0, 0, 255 };

void joyElementView::mainContext(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const sdl2::Font& arial, const fs::path& languageTextsPath, const sdl2::JoystickEntity& joyEnt,
								int squareSize)
{
	JoystickValuesTextures joyTextures{logs, rndWnd, arial, languageTextsPath, joyEnt, squareSize};
	
	joyElementView::mainLoop(rndWnd, joyTextures);
}

void joyElementView::mainLoop(sdl2::RendererWindow& rndWnd, JoystickValuesTextures& joystickTextures)
{
	while( false == joystickTextures.isQuitTriggered() )
	{
		joystickTextures.updateEvents();
		rndWnd.clearScreen(SDL_Color{192, 192, 192, 255});
		joystickTextures.drawAll(rndWnd);
		rndWnd.displayRenderer();
		SDL_Delay(16);
	}
}

void joyCalibrate::mainContext(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const sdl2::Font& arialFont, const fs::path& languageTextsPath, int squareSize)
{
	JoystickCalibration joystickCalibration{logs, rndWnd, arialFont, languageTextsPath, squareSize};

	joyCalibrate::mainLoop(logs, rndWnd, joystickCalibration);
}

void joyCalibrate::mainLoop(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, JoystickCalibration& joystickCalibration)
{
	while( false == joystickCalibration.quitContext() )
	{
		joystickCalibration.updateEvents();
		joystickCalibration.moveWithAxes( );
		joystickCalibration.moveWithHat( );
		joystickCalibration.updateEditBoxes(logs, rndWnd);
		joystickCalibration.setMouseButtonToFalse();
		rndWnd.clearScreen(SDL_Color{192, 192, 192, 255});
		joystickCalibration.drawAll(rndWnd);
		rndWnd.displayRenderer();
		SDL_Delay(16);
	}
}
