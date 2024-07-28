#include "gameOptions/inputs/joystick/joystickOptions.h"
#include "package/essentials.h"
#include "pathsFunctions/pathsFunctions.h"
#include "inputsConfig/createJoystickFile.h"
#include "texturing/texturePosition.h"
#include "consts/filesAndPaths.h"
#include "gameOptions/consts/optionsConsts.h"
#include "consts/playerInputsConsts.h"
#include "consts/fontsSizes.h"
#include <cassert>
#include <limits>

constexpr int ThresholdLine = SQR_SIZE * 10;

JoystickOptions::JoystickOptions(Essentials& essentials, const sdl2::Font& arialFont, const TextsBlocks& interfaceTexts):
	joystickInputsConfig{ essentials.logs, essentials.prefPath },
	joystickElementsTexts{ essentials.logs.error, path::getLanguageFile(essentials.chosenLanguage, options::JoystickElementsTextsPath), JoyMoveWithMax },
	joystickColumnsHeaders{ essentials.logs.error, path::getLanguageFile(essentials.chosenLanguage, options::JoystickColumnsTextsPath), options::JoystickElementMaxTxt },
	joystickHatValues{ essentials.logs.error, path::getLanguageFile(essentials.chosenLanguage, options::JoystickHatValues), options::JoystickHatMax },
	data( MoveMax ),
	axesThresholdText{ essentials.logs, essentials.rndWnd, arialFont, interfaceTexts[options::InputsMenuAxesThreshold], options::BtnsInfosCol,
						TexturePosition{ SQR_SIZE, ThresholdLine, false, true } },
	axesThreshold{ joystickInputsConfig.getAxesTheshold() },
	thresholdEditBox{ essentials.logs, essentials.rndWnd, 
			SDL_Rect{ SQR_SIZE * 2 + axesThresholdText.sprite.width(), ThresholdLine - options::EditBoxesHeight / 2, SQR_SIZE * 3, options::EditBoxesHeight }, 
			MediumFontSize, axesThreshold }
{
	setElementsEnums();
	createColumnsTexts(essentials, arialFont);
	createJoyElementsHighlightButtons(essentials, arialFont);
	createEditBoxes(essentials);
	createElementsValueHighlightButtons(essentials, arialFont);
}

void JoystickOptions::drawEverything(sdl2::RendererWindow& rndWnd) const
{
	drawColumnsTexts(rndWnd);
	drawJoyElementsButtons(rndWnd);
	drawUintBoxes(rndWnd);
	drawElementsNumberValue(rndWnd);
	axesThresholdText.draw(rndWnd);
	thresholdEditBox.drawBoxWithoutFocus(rndWnd);
}

void JoystickOptions::updateButtons(const Offset& mousePosition, bool mouseButtonState)
{
	updateJoystickElementsButtons(mousePosition, mouseButtonState);
	updateJoystickElementValueButtons(mousePosition, mouseButtonState);
}

void JoystickOptions::changeJoystickElementType(Essentials& essentials, const sdl2::Font& arialFont)
{
	for( std::size_t i{0} ; i < joystickElementsButtons.size() ; ++i )
	{
		if( joystickElementsButtons[i].buttonClicked() )
		{
			switchToNextJoystickElement( data[i] );
			joystickElementsButtons[i].changeText( essentials.logs, essentials.rndWnd, arialFont, 
					getElementNameFromValue(data[i].joystickElement, joystickElementsTexts), options::BtnsTxtCol );
		}
	}
}

void JoystickOptions::catchUserFocus(Essentials& essentials, const Offset& mousePosition, bool mouseButtonState)
{
	for( auto &box : elementNumbersEditBoxes )
	{
		box.catchUserFocus(essentials.logs, essentials.rndWnd, mousePosition, mouseButtonState);
	}
	thresholdEditBox.catchUserFocus(essentials.logs, essentials.rndWnd, mousePosition, mouseButtonState);
}

void JoystickOptions::changeElementValueHighlightButtons(Essentials& essentials, const sdl2::Font& arialFont)
{
	for( std::size_t i{0} ; i < MoveMax ; ++i )
	{
		if( elementNumberValue[i].buttonClicked() )
		{
			if( data[i].joystickElement == JoyHats )
			{
				switchToNextHatValue(data[i].elementValue);
			}
			changeElementValueHighlightButtons(essentials, arialFont, i);
		}
	}
}

void JoystickOptions::recordModificationsToFile(Essentials& essentials, const fs::path& joystickConfigFile) const
{
	if( std::ofstream configFile{ joystickConfigFile } )
	{
		assert( data.size() == MoveMax );
		
		for( unsigned i{0} ; i < MoveMax ; ++i )
		{
			if( ! ( configFile << i << " " << data[i].joystickElement << " " << data[i].elementNumber << " " << data[i].elementValue << '\n' ) )
			{
				essentials.logs.error << "Error: couldn't write 'joystick configuration data' in '" << joystickConfigFile.string() << "' file.\n";
			}
		}
	}
	else{
		essentials.logs.error.wrFileOpeningError(joystickConfigFile, "save joystick configuration data");
	}
}

void JoystickOptions::recordAxesThreshold(Essentials& essentials, const fs::path& joystickConfigFile) const
{
	if( std::ofstream configFile{ joystickConfigFile } )
	{
		writeAxesThreshold(essentials.logs, configFile, axesThreshold);
	}
	else{
		essentials.logs.error.wrFileOpeningError(joystickConfigFile, "save joystick axes threshold configuration data");
	}
}

void JoystickOptions::setElementsEnums()
{
	assert( joystickInputsConfig.size() == data.size() );
	for( std::size_t i{0} ; i < joystickInputsConfig.size() ; ++i )
	{
		data[i].joystickElement = joystickInputsConfig.getJoyElement(i);
		data[i].elementNumber = joystickInputsConfig.getElementNumber(i);
		data[i].elementValue = joystickInputsConfig.getElementValue(i);
	}
}

void JoystickOptions::createColumnsTexts(Essentials& essentials, const sdl2::Font& arialFont)
{
	for( std::size_t i{0} ; i < joystickColumnsHeaders.size() ; ++i )
	{
		columnsTexts.emplace_back( TextureCombo{ essentials.logs, essentials.rndWnd, arialFont, joystickColumnsHeaders[i], options::BtnsInfosCol, 
				TexturePosition{ SQR_SIZE * 8 + static_cast<int>(i) * SQR_SIZE * 5, SQR_SIZE * 3, true, true } } );
	}
}

void JoystickOptions::createJoyElementsHighlightButtons(Essentials& essentials, const sdl2::Font& arialFont)
{
	for( std::size_t i{0} ; i < MoveMax ; ++i )
	{
		int heightCenterPosition{ SQR_SIZE * ( 4 + static_cast<int>(i) ) };
		joystickElementsButtons.emplace_back( HighLightButton{essentials.logs, essentials.rndWnd, arialFont, 
			getElementNameFromValue( data[i].joystickElement, joystickElementsTexts ), 
			options::BtnsTxtCol, SDL_Rect{ SQR_SIZE * 8 - options::ButtonsWidth / 2, heightCenterPosition - options::ButtonsHeight / 2, 
			options::ButtonsWidth, options::ButtonsHeight }, options::BtnsHighLightCol } );
	}
}

void JoystickOptions::createEditBoxes(Essentials& essentials)
{
	for( std::size_t i{0} ; i < MoveMax ; ++i )
	{
		int heightCenterPos{ SQR_SIZE * ( 4 + static_cast<int>(i) ) };
		elementNumbersEditBoxes.emplace_back( UintEditBox{essentials.logs, essentials.rndWnd, 
				SDL_Rect{ options::BoxesXCoords - options::EditBoxesWidth / 2, heightCenterPos - options::EditBoxesHeight / 2, options::EditBoxesWidth, options::EditBoxesHeight }, 
				MediumFontSize, data[i].elementNumber } );
	}
}

void JoystickOptions::createElementsValueHighlightButtons(Essentials& essentials, const sdl2::Font& arialFont)
{
	for( std::size_t i{0} ; i < MoveMax ; ++i )
	{
		int heightCenterPos{ SQR_SIZE * ( 4 + static_cast<int>(i) ) };
		elementNumberValue.emplace_back( HighLightButton{ essentials.logs, essentials.rndWnd, arialFont, "-", options::BtnsTxtCol,
					SDL_Rect{ SQR_SIZE * 18 - options::ButtonsWidth / 2, heightCenterPos - options::ButtonsHeight / 2, options::ButtonsWidth, options::ButtonsHeight }, 
					options::BtnsHighLightCol } );
		changeElementValueHighlightButtons(essentials, arialFont, i);
	}
}

void JoystickOptions::changeElementValueHighlightButtons(Essentials& essentials, const sdl2::Font& arialFont, std::size_t lineIndex)
{
	assert( lineIndex < elementNumberValue.size() );
	switch( data[lineIndex].joystickElement )
	{
		case JoyAxes:
			elementNumberValue[lineIndex].changeText(essentials.logs, essentials.rndWnd, arialFont, "----", WhiteCol);
			break;
		case JoyHats:
			elementNumberValue[lineIndex].changeText(essentials.logs, essentials.rndWnd, arialFont, getHatStringFromValue(joystickHatValues, data[lineIndex].elementValue), WhiteCol);
			break;
		case JoyButtons:
			elementNumberValue[lineIndex].changeText(essentials.logs, essentials.rndWnd, arialFont, "----", WhiteCol);
			break;
	}
}

void JoystickOptions::updateJoystickElementsButtons(const Offset& mousePosition, bool mouseButtonState)
{
	for( auto &btn : joystickElementsButtons )
	{
		btn.updateButton(mousePosition, mouseButtonState);
	}
}

void JoystickOptions::updateJoystickElementValueButtons(const Offset& mousePosition, bool mouseButtonState)
{
	for( auto &btn : elementNumberValue )
	{
		btn.updateButton(mousePosition, mouseButtonState);
	}
}

void JoystickOptions::drawColumnsTexts(sdl2::RendererWindow& rndWnd) const
{
	for( auto const &text : columnsTexts )
	{
		text.draw(rndWnd);
	}
}

void JoystickOptions::drawJoyElementsButtons(sdl2::RendererWindow& rndWnd) const
{
	for( auto const &btn: joystickElementsButtons )
	{
		btn.drawButton(rndWnd);
	}
}

void JoystickOptions::drawUintBoxes(sdl2::RendererWindow& rndWnd) const
{
	for( auto const &box : elementNumbersEditBoxes )
	{
		box.drawBoxWithoutFocus(rndWnd);
	}
}

void JoystickOptions::drawElementsNumberValue(sdl2::RendererWindow& rndWnd) const
{
	for( auto const &btn : elementNumberValue )
	{
		btn.drawButton(rndWnd);
	}
}

std::string getElementNameFromValue(unsigned elementType, const TextsBlocks& texts)
{
	switch( elementType )
	{
		case JoyAxes:
			return texts[JoyAxes];
			break;
		case JoyHats:
			return texts[JoyHats];
			break;
		case JoyButtons:
			return texts[JoyButtons];
			break;
		default:
			assert( false && "Error: bad element value." );
			return "Error";
			break;
	}
}

std::string getHatStringFromValue(const TextsBlocks& texts, unsigned elementValue)
{
	switch( elementValue )
	{
		case SDL_HAT_RIGHT:
			return texts[options::JoystickHatRight];
			break;
		case SDL_HAT_UP:
			return texts[options::JoystickHatUp];
			break;
		case SDL_HAT_LEFT:
			return texts[options::JoystickHatLeft];
			break;
		case SDL_HAT_DOWN:
			return texts[options::JoystickHatDown];
			break;
		default:
			return "Error";
			break;
	}
}

void switchToNextJoystickElement(JoystickFuncElement& data)
{
	switch( data.joystickElement )
	{
		case JoyAxes:
			data.joystickElement = JoyHats;
			data.elementNumber = 0;
			data.elementValue = options::JoystickHatRight;
			break;
		case JoyHats:
			data.joystickElement = JoyButtons;
			data.elementNumber = 0;
			data.elementValue = 0;
			break;
		case JoyButtons:
			data.joystickElement = JoyAxes;
			data.elementNumber = 0;
			data.elementValue = 4000;
			break;
		default:
			assert( false && "Error: bad element value." );
			break;
	}
}

void switchToNextHatValue(unsigned& elementValue)
{
	switch( elementValue )
	{
		case SDL_HAT_RIGHT:
			elementValue = SDL_HAT_UP;
			break;
		case SDL_HAT_UP:
			elementValue = SDL_HAT_LEFT;
			break;
		case SDL_HAT_LEFT:
			elementValue = SDL_HAT_DOWN;
			break;
		case SDL_HAT_DOWN:
			elementValue = SDL_HAT_RIGHT;
			break;
		default:
			elementValue = SDL_HAT_RIGHT;
			break;
	}
}
