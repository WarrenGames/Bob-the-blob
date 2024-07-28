#include "gameOptions/inputs/inputsInterface/globalInterface.h"
#include "pathsFunctions/pathsFunctions.h"
#include "package/essentials.h"
#include "texturing/texturePosition.h"
#include "gameOptions/consts/optionsConsts.h"
#include "consts/filesAndPaths.h"
#include "consts/playerInputsConsts.h"
#include "consts/fontsSizes.h"
#include "consts/screenConsts.h"

options::InputsGlobalInterface::InputsGlobalInterface(Essentials& essentials):
	keyboardMenusTexts{ essentials.logs.error, path::getLanguageFile(essentials.chosenLanguage, options::KeyboardMenuLanguageTexts), options::KeybColumnTxtMax },
	playerFunctionsTexts{ essentials.logs.error, path::getLanguageFile(essentials.chosenLanguage, options::KeyboardFuncLanguageTexts), MoveMax },
	interfaceTexts{ essentials.logs.error, path::getLanguageFile(essentials.chosenLanguage, options::InputsInterfaceTexts), options::InputsMenuMax },
	arialFont{ essentials.logs.error, ArialFontPath, MediumFontSize },
	joystickEntity{ 0 },
	functionsColumn{ essentials.logs, essentials.rndWnd, arialFont, keyboardMenusTexts[options::KeybFuncColumnTxt], options::BtnsInfosCol, 
						TexturePosition{ SQR_SIZE, SQR_SIZE * 3, false, true} },
	keycodesColumn{ essentials.logs, essentials.rndWnd, arialFont, keyboardMenusTexts[options::KeybKeycodesColumnTxt], options::BtnsInfosCol,
						TexturePosition{ SQR_SIZE * 4, SQR_SIZE * 3, true, true } },
	keyboardOptions{ essentials, arialFont, keyboardMenusTexts },
	joystickOptions{ essentials, arialFont, interfaceTexts },
	joystickInfosButton{ essentials.logs, essentials.rndWnd, arialFont, interfaceTexts[options::InputsMenuJoyInfos], options::BtnsHighLightCol, options::BtnsTxtCol, 
		TexturePosition{ GameScreenWidth * 3 / 4, GameScreenHeight - SQR_SIZE * 2, true, true } },
	joystickCalibrate{ essentials.logs, essentials.rndWnd, arialFont, interfaceTexts[options::InputsMenuCalibrateJoy], options::BtnsHighLightCol, options::BtnsTxtCol, 
		TexturePosition{ GameScreenWidth / 4, GameScreenHeight - SQR_SIZE * 2, true, true }
	},
	menuTitle{ essentials.logs, essentials.rndWnd, arialFont, interfaceTexts[options::InputsMenuTitle], options::BtnsInfosCol, 
		TexturePosition{ GameScreenWidth / 2, SQR_SIZE, true, true } },
	background{essentials.logs, essentials.rndWnd, "textures/wallpapers/optionsScreen.png"}
{
	createButtonsInfosGraphisms(essentials);
}

void options::InputsGlobalInterface::updateButtons(const Offset& mousePosition, bool mouseButtonState)
{
	keyboardOptions.updateButtons(mousePosition, mouseButtonState);
	joystickOptions.updateButtons(mousePosition, mouseButtonState);
	joystickInfosButton.updateButton(mousePosition, mouseButtonState);
	joystickCalibrate.updateButton(mousePosition, mouseButtonState);
}

void options::InputsGlobalInterface::updateKeycodeWithUser(Essentials& essentials)
{
	keyboardOptions.updateKeycodeWithUser(essentials, arialFont);
}

void options::InputsGlobalInterface::updateJoystickConfig(Essentials& essentials, const Offset& mousePosition, bool mouseButtonState)
{
	joystickOptions.changeJoystickElementType(essentials, arialFont);
	joystickOptions.catchUserFocus(essentials, mousePosition, mouseButtonState);
	joystickOptions.changeElementValueHighlightButtons(essentials, arialFont);
}

void options::InputsGlobalInterface::createButtonsInfosGraphisms(Essentials& essentials)
{
	if( playerFunctionsTexts )
	{
		for( std::size_t i{0} ; i < playerFunctionsTexts.size() ; ++i )
		{
			int heightCenterPosition{ SQR_SIZE * ( 4 + static_cast<int>(i) ) };
			buttonsInfos.emplace_back( 
				TextureCombo{essentials.logs, essentials.rndWnd, arialFont, playerFunctionsTexts[i], options::BtnsInfosCol, 
								TexturePosition{SQR_SIZE, heightCenterPosition, false, true} } );
		}
	}
}

void options::InputsGlobalInterface::drawInfosTexts(sdl2::RendererWindow& rndWnd) const
{
	for( auto const &txt : buttonsInfos )
	{
		txt.draw(rndWnd);
	}
}

void options::InputsGlobalInterface::drawEverything(sdl2::RendererWindow& rndWnd) const
{
	background.draw(rndWnd);
	drawInfosTexts(rndWnd);
	functionsColumn.draw(rndWnd);
	keycodesColumn.draw(rndWnd);
	keyboardOptions.drawEverything(rndWnd);
	joystickOptions.drawEverything(rndWnd);
	joystickInfosButton.drawButton(rndWnd);
	joystickCalibrate.drawButton(rndWnd);
	menuTitle.draw(rndWnd);
}

void options::InputsGlobalInterface::recordModificationsToFile(Essentials& essentials)
{
	keyboardOptions.recordModificationsToFiles(essentials);
	joystickOptions.recordModificationsToFile(essentials, path::getInputsFilePath(essentials.prefPath, files::JoystickInputsFile) );
	joystickOptions.recordAxesThreshold(essentials, path::getInputsFilePath(essentials.prefPath, files::JoystickAxesThresholdFile) );
}