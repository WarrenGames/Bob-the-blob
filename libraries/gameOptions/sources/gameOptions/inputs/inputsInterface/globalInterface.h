#ifndef BOB_THE_BLOB_GAME_OPTIONS_LIB_INPUTS_GLOBAL_INTERFACE_H
#define BOB_THE_BLOB_GAME_OPTIONS_LIB_INPUTS_GLOBAL_INTERFACE_H

#include "gameOptions/inputs/keyboard/keyboardOptions.h"
#include "gameOptions/inputs/joystick/joystickOptions.h"
#include "widgets/buttons/textButtonWidget.h"
#include "joystick/joystickEntity.h"
#include "text/sdl2ttf_font.h"
#include "texts/textLoader.h"

struct Essentials;

namespace options{

struct InputsGlobalInterface
{
	const TextsBlocks keyboardMenusTexts;
	const TextsBlocks playerFunctionsTexts;
	const TextsBlocks interfaceTexts;
	const sdl2::Font arialFont;
	sdl2::JoystickEntity joystickEntity;
	TextureCombo functionsColumn;
	TextureCombo keycodesColumn;
	std::vector< TextureCombo > buttonsInfos;
	KeyboardOptions keyboardOptions;
	JoystickOptions joystickOptions;
	TextButton joystickInfosButton;
	TextButton joystickCalibrate;
	TextureCombo menuTitle;
	const TextureCombo background;
	
	explicit InputsGlobalInterface(Essentials& essentials);
	~InputsGlobalInterface() = default;
	InputsGlobalInterface( const InputsGlobalInterface& ) = delete;
	InputsGlobalInterface& operator= ( const InputsGlobalInterface& ) = delete;
	InputsGlobalInterface( InputsGlobalInterface&& ) = default;
	InputsGlobalInterface& operator= ( InputsGlobalInterface&& ) = default;
	
	void updateButtons(const Offset& mousePosition, bool mouseButtonState);
	void updateKeycodeWithUser(Essentials& essentials);
	void updateJoystickConfig(Essentials& essentials, const Offset& mousePosition, bool mouseButtonState);
	
	void createButtonsInfosGraphisms(Essentials& essentials);
	void drawInfosTexts(sdl2::RendererWindow& rndWnd) const;
	void drawEverything(sdl2::RendererWindow& rndWnd) const;
	
	void recordModificationsToFile(Essentials& essentials);
};

}

#endif //BOB_THE_BLOB_GAME_OPTIONS_LIB_INPUTS_GLOBAL_INTERFACE_H