#ifndef BOB_THE_BLOB_GAME_OPTIONS_CONSTS_H
#define BOB_THE_BLOB_GAME_OPTIONS_CONSTS_H

#include "consts/colors.h"
#include "consts/includeOptions.h"

namespace options{
	constexpr SDL_Color BtnsInfosCol = BlackCol;
	constexpr SDL_Color BtnsTxtCol = WhiteCol;
	constexpr SDL_Color BtnsHighLightCol = GreenCol;
	
	constexpr int ButtonsWidth = SQR_SIZE * 4;
	constexpr int ButtonsHeight = SQR_SIZE;
	
	constexpr char KeyboardFuncLanguageTexts[] = "optionsMenu/keyboardInfos.txt";
	constexpr char KeyboardMenuLanguageTexts[] = "optionsMenu/keyboardMenu.txt";
	
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
}

#endif //BOB_THE_BLOB_GAME_OPTIONS_CONSTS_H