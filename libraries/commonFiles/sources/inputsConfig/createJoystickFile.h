#ifndef BOB_THE_BLOB_COMMON_FILES_CREATE_JOYSTICK_FILE_H
#define BOB_THE_BLOB_COMMON_FILES_CREATE_JOYSTICK_FILE_H

#include "SDL_joystick.h"
#include <iosfwd>

struct AppLogFiles;

void writeJoystickConfigFileDefault(AppLogFiles& logs, std::ofstream& joystickFile);

void writeJoystickSingleMoveConfig(AppLogFiles& logs, std::ofstream& joystickFile, unsigned funcEnum, unsigned joystickElement, unsigned elementNumber, unsigned elementValue);

void writeAxesThreshold(AppLogFiles& logs, std::ofstream& axesJoystickFile, int thresholdValue);

#endif //BOB_THE_BLOB_COMMON_FILES_CREATE_JOYSTICK_FILE_H