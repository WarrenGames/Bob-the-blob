#include "inputsConfig/createJoystickFile.h"
#include "logging/logsStruct.h"
#include "consts/playerInputsConsts.h"
#include "consts/filesAndPaths.h"
#include <fstream>

void writeJoystickConfigFileDefault(AppLogFiles& logs, std::ofstream& joystickFile)
{
	if( joystickFile )
	{
		writeJoystickSingleMoveConfig(logs, joystickFile, MoveEast, JoyHats, 0, static_cast<unsigned>(SDL_HAT_RIGHT) );
		writeJoystickSingleMoveConfig(logs, joystickFile, MoveUp, JoyHats, 0, static_cast<unsigned>(SDL_HAT_UP) );
		writeJoystickSingleMoveConfig(logs, joystickFile, MoveWest, JoyHats, 0, static_cast<unsigned>(SDL_HAT_LEFT) );
		writeJoystickSingleMoveConfig(logs, joystickFile, MoveDown, JoyHats, 0, static_cast<unsigned>(SDL_HAT_DOWN) );
		writeJoystickSingleMoveConfig(logs, joystickFile, MoveStop, JoyButtons, 0, 0);
	}
}

void writeJoystickSingleMoveConfig(AppLogFiles& logs, std::ofstream& joystickFile, unsigned funcEnum, unsigned joystickElement, unsigned elementNumber, unsigned elementValue)
{
	if( ! ( joystickFile << funcEnum << " " << joystickElement << " " << elementNumber << " " << elementValue << "\n" ) )
	{
		logs.error << "Error: couldn't write '" << funcEnum << "' in joystick configuration file: '" << files::JoystickInputsFile << " .\n";
	}
}

void writeAxesThreshold(AppLogFiles& logs, std::ofstream& axesJoystickFile, int thresholdValue)
{
	if( ! ( axesJoystickFile << JoyAxesThresholdId << " " << thresholdValue << '\n' ) )
	{
		logs.error << "Error: couldn't write '" << thresholdValue << "' threshold value in '" << files::JoystickAxesThresholdFile << " .\n";
	}
}