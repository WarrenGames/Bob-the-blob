#ifndef BOB_THE_BLOB_GAME_OPTIONS_CONSTS_H
#define BOB_THE_BLOB_GAME_OPTIONS_CONSTS_H

#include "consts/colors.h"
#include "consts/includeOptions.h"

namespace options{
	constexpr SDL_Color BtnsInfosCol = BlackCol;
	constexpr SDL_Color BtnsTxtCol = WhiteCol;
	constexpr SDL_Color BtnsHighLightCol = GreenCol;
	
	constexpr int ButtonsWidth = SQR_SIZE * 3;
	constexpr int ButtonsHeight = SQR_SIZE;
	
	constexpr int BoxesXCoords = SQR_SIZE * 13;
	constexpr int EditBoxesWidth = SQR_SIZE;
	constexpr int EditBoxesHeight = SQR_SIZE / 2;
	
	constexpr char KeyboardFuncLanguageTexts[] = "optionsMenu/playerFunctions.txt";
	constexpr char KeyboardMenuLanguageTexts[] = "optionsMenu/keyboardMenu.txt";
	
	constexpr char JoystickElementsTextsPath[] = "optionsMenu/joystickElementsEnum.txt";
	constexpr char JoystickColumnsTextsPath[] = "optionsMenu/joystickColumns.txt";
	constexpr char JoystickHatValues[] = "optionsMenu/joystickHatValues.txt";
	constexpr char InputsInterfaceTexts[] = "optionsMenu/inputsInterfaceTexts.txt";
	constexpr char JoyCalibrationTextsPath[] = "optionsMenu/joyCalibration.txt";
	
	constexpr char BackgroundTexturePath[] = "textures/wallpapers/optionsScreen.png";
	
	enum : unsigned{
		PanelKeyboard,
		PanelJoystick,
		PanelMax
	};
	
	enum : unsigned{
		KeybFuncColumnTxt,
		KeybKeycodesColumnTxt,
		KeybChooseNewKey,
		KeybColumnTxtMax
	};
	
	enum : unsigned{
		JoystickElementsTxt,
		JoystickElementNumberTxt,
		JoystickElementNumberValueTxt,
		JoystickElementMaxTxt,
	};
	
	enum : unsigned{
		JoystickHatRight,
		JoystickHatUp,
		JoystickHatLeft,
		JoystickHatDown,
		JoystickHatMax,
	};
	
	enum : unsigned{
		InputsMenuTitle,
		InputsMenuJoyInfos,
		InputsMenuCalibrateJoy,
		InputsMenuAxesThreshold,
		InputsMenuMax
	};
}

#endif //BOB_THE_BLOB_GAME_OPTIONS_CONSTS_H