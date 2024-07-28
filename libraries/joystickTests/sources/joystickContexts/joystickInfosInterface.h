#ifndef JOYSTICK_INFOS_INTERFACE_H
#define JOYSTICK_INFOS_INTERFACE_H

#include "fileSystem/fileSystem.h"

struct AppLogFiles;
class JoystickValuesTextures;
class JoystickCalibration;
struct TextureCombo;

namespace sdl2{ class Font; class RendererWindow; class JoystickEntity; }

namespace joyElementView{

	void mainContext(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const sdl2::Font& arial, const fs::path& languageTextsPath, const sdl2::JoystickEntity& joyEnt, int squareSize);

	void mainLoop(sdl2::RendererWindow& rndWnd, JoystickValuesTextures& joystickTextures);
}

namespace joyCalibrate{
	void mainContext(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const sdl2::Font& arialFont, const fs::path& languageTextsPath, int squareSize);
	
	void mainLoop(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, JoystickCalibration& joystickCalibration);
}

#endif //JOYSTICK_INFOS_INTERFACE_H