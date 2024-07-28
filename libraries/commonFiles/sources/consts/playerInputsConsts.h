#ifndef COMMON_FILES_PLAYER_INPUTS_CONSTS_H
#define COMMON_FILES_PLAYER_INPUTS_CONSTS_H

enum : unsigned{ MoveEast, MoveUp, MoveWest, MoveDown, MoveStop, MoveMax };

enum : unsigned{ DemoSdlQuitCommand, DemoEscapeCommand, DemoQuitCommandMax };

enum : unsigned{ JoyAxes, JoyHats, JoyButtons, JoyMoveWithMax };

constexpr unsigned JoyAxesThresholdId = 100;

#endif //COMMON_FILES_PLAYER_INPUTS_CONSTS_H