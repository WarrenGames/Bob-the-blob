#include "joystickData/joystickGraphicsValues.h"
#include "texturing/texturePosition.h"
#include "texturing/rendererWindow.h"
#include "logging/logsStruct.h"
#include "SDL_events.h"
#include <string>
#include <cassert>
#include <limits>

constexpr int ButtonsWidthNumber = 16; //The number of buttons states in one row
constexpr int ButtonsHeightNumber = 2;  //The number of buttons row : so it's 32 buttons max that are drawn.
constexpr double Sint16_MaxValue = std::numeric_limits<Sint16>::max();

constexpr SDL_Color BlackCol = { 0, 0, 0, 255 };
constexpr SDL_Color WhiteCol = { 255, 255, 255, 255 };
constexpr SDL_Color RedCol = { 255, 0, 0, 255 };

enum{
	JoyAxis,
	JoyHat,
	JoyButton,
	JoyMax
};

JoyEventsInfos::JoyEventsInfos(const sdl2::JoystickEntity& joyEnt):
	joyButtons( joyEnt.getButtonsNumber(), false ),
	joyHats( joyEnt.getHatsNumber(), SDL_HAT_CENTERED ),
	joyAxes( joyEnt.getAxesNumber(), 0 ),
	joystickNumber{ joyEnt.getJoystickNumber() },
	escapeState{false},
	sdl_Quit{ false }
{

}



JoystickValuesTextures::JoystickValuesTextures(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const sdl2::Font& arial, const fs::path& languageTextsPath, 
												const sdl2::JoystickEntity& joyEnt, int squareSize_):
	squareSize{ squareSize_ },
	joyLangTexts{ logs.error, languageTextsPath, JoyMax },
	hatsSquare{ logs, rndWnd, WhiteCol, squareSize * 3, squareSize * 3 },
	buttonOff{ logs, rndWnd, WhiteCol, squareSize / 2, squareSize / 2 },
	buttonPushed{ logs, rndWnd, RedCol, squareSize / 2, squareSize / 2 },
	axisGradientOff{ logs, rndWnd, WhiteCol, squareSize / 2, squareSize * 2 },
	axisGradientRed{ logs, rndWnd, RedCol, squareSize / 2, squareSize, TexturePosition{ -squareSize * 4, -squareSize * 4 } },
	buttonsText{ logs, rndWnd, arial, joyLangTexts[JoyButton], BlackCol, TexturePosition{ Offset{squareSize, squareSize * 2 - squareSize / 4}, false, true } },
	hatsText{ logs, rndWnd, arial, joyLangTexts[JoyHat], BlackCol, TexturePosition{Offset{squareSize, squareSize * 5 + squareSize/2}, false, true } },
	axisText{ logs, rndWnd, arial, joyLangTexts[JoyAxis], BlackCol, TexturePosition{Offset{squareSize, squareSize * 9}, false, false } },
	joyEventsInfos{ joyEnt },
	numbersTextures( std::max(joyEnt.getButtonsNumber(), std::max(joyEnt.getHatsNumber(), joyEnt.getAxesNumber()) ) )
{
	createNumbersTextures(logs, rndWnd, arial);
}

void JoystickValuesTextures::updateEvents()
{
	SDL_Event ev;
	while( SDL_PollEvent(&ev) )
	{
		switch( ev.type )
		{
			case SDL_QUIT:
				joyEventsInfos.sdl_Quit = true;
				break;
			case SDL_KEYDOWN:
				appendEscapeKeyStatus(ev.key.keysym.sym, true);
				break;
			case SDL_KEYUP:
				appendEscapeKeyStatus(ev.key.keysym.sym, false);
				break;
			case SDL_JOYBUTTONDOWN:
				if( ev.jbutton.which == joyEventsInfos.joystickNumber )
					joyEventsInfos.joyButtons[ev.jbutton.button] = true;
				break;
			case SDL_JOYBUTTONUP:
				if( ev.jbutton.which == joyEventsInfos.joystickNumber )
					joyEventsInfos.joyButtons[ev.jbutton.button] = false;
				break;
			case SDL_JOYHATMOTION:
				if( ev.jbutton.which == joyEventsInfos.joystickNumber )
					joyEventsInfos.joyHats[ev.jhat.hat] = ev.jhat.value;
				break;
			case SDL_JOYAXISMOTION:
				if( ev.jbutton.which == joyEventsInfos.joystickNumber )
					joyEventsInfos.joyAxes[ev.jaxis.axis] = ev.jaxis.value;
				break;
		}
	}
}

bool JoystickValuesTextures::isQuitTriggered() const
{
	return joyEventsInfos.escapeState || joyEventsInfos.sdl_Quit;
}

void JoystickValuesTextures::drawAll(sdl2::RendererWindow& rndWnd)
{
	buttonsText.draw(rndWnd);
	drawButtonsStates(rndWnd);
	hatsText.draw(rndWnd);
	drawHatsSurfaces(rndWnd);
	axisText.draw(rndWnd);
	drawAxesValues(rndWnd);
}

void JoystickValuesTextures::drawButtonsStates(sdl2::RendererWindow& rndWnd)
{
	std::size_t buttonIndex{0};
	
	for( int i{0} ; i < ButtonsHeightNumber ; ++i )
	{
		for( int j{0} ; j < ButtonsWidthNumber ; ++j )
		{
			if( buttonIndex < joyEventsInfos.joyButtons.size() )
			{
				drawSingleButtonSurface(rndWnd, squareSize * 3 + squareSize * j, squareSize * 2 + squareSize * i, joyEventsInfos.joyButtons[buttonIndex] );
				drawButtonsNumbers(rndWnd, buttonIndex, squareSize * 3 + squareSize * j + squareSize / 4, squareSize * 2 - squareSize / 4 + squareSize * i);
			}
			buttonIndex++;
		}
	}
}

void JoystickValuesTextures::drawButtonsNumbers(sdl2::RendererWindow& rndWnd, std::size_t figureNum, int x_center_pos, int y_center_pos)
{
	assert( figureNum < numbersTextures.size() );
	numbersTextures[figureNum].resetSpritePosition(TexturePosition{ Offset{x_center_pos, y_center_pos}, true, true} );
	numbersTextures[figureNum].draw(rndWnd);
}

void JoystickValuesTextures::drawHatsSurfaces(sdl2::RendererWindow& rndWnd)
{
	if( false == joyEventsInfos.joyHats.empty() )
	{
		for( std::size_t i{0} ; i < joyEventsInfos.joyHats.size() ; ++i )
		{
			hatsSquare.draw(rndWnd, squareSize * 4 + static_cast<int>(i) * squareSize * 4, squareSize * 5);
			drawHatReticule(rndWnd, joyEventsInfos.joyHats[i], squareSize * 4+ static_cast<int>(i) * squareSize * 4 + hatsSquare.sprite.width() / 2, 
								squareSize * 5 + hatsSquare.sprite.height() / 2 );
			drawButtonsNumbers(rndWnd, i, squareSize * 4 + static_cast<int>(i) * squareSize * 4 + hatsSquare.sprite.width() / 2, squareSize * 5 - squareSize / 4 );
		}
	}
}

void JoystickValuesTextures::drawAxesValues(sdl2::RendererWindow& rndWnd)
{
	if( false == joyEventsInfos.joyAxes.empty() )
	{
		for( std::size_t i{0} ; i < joyEventsInfos.joyAxes.size() ; ++i )
		{
			drawSingleAxisSurface(rndWnd, squareSize * 4 + squareSize * static_cast<int>(i), squareSize * 9, joyEventsInfos.joyAxes[i]);
			drawButtonsNumbers(rndWnd, i, squareSize * 4 + squareSize * static_cast<int>(i) + squareSize / 4, squareSize * 9 - squareSize / 4);
		}
	}
}

void JoystickValuesTextures::appendEscapeKeyStatus(SDL_Keycode keycode, bool valueToSet)
{
	if( keycode == SDLK_ESCAPE )
		joyEventsInfos.escapeState = valueToSet;
}

void JoystickValuesTextures::createNumbersTextures(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const sdl2::Font& arial)
{
	for( std::size_t i{0} ; i < numbersTextures.size() ; ++i )
	{
		numbersTextures[i].texture.loadBlendedText(logs, rndWnd, arial, std::to_string(i), BlackCol);
		numbersTextures[i].sprite.resetDimensions();
	}
}

void JoystickValuesTextures::drawSingleButtonSurface(sdl2::RendererWindow& rndWnd, int x_pos, int y_pos, bool buttonState)
{
	if( buttonState )
	{
		buttonPushed.draw(rndWnd, x_pos, y_pos);
	}
	else
		buttonOff.draw(rndWnd, x_pos, y_pos);
}

void JoystickValuesTextures::drawHatReticule(sdl2::RendererWindow& rndWnd, Uint8 hatValue, int x_pos, int y_pos)
{
	switch( hatValue )
	{
		case SDL_HAT_CENTERED:
			buttonPushed.drawToCenter(rndWnd, x_pos, y_pos);
			break;
		case SDL_HAT_LEFT:
			buttonPushed.drawToCenter(rndWnd, x_pos - hatsSquare.sprite.width() / 2 + buttonPushed.sprite.width() / 2, y_pos );
			break;
		case SDL_HAT_RIGHT:
			buttonPushed.drawToCenter(rndWnd, x_pos + hatsSquare.sprite.width() / 2 - buttonPushed.sprite.width() / 2, y_pos );
			break;
		case SDL_HAT_UP:
			buttonPushed.drawToCenter(rndWnd, x_pos, y_pos - hatsSquare.sprite.height() / 2 + buttonPushed.sprite.height() / 2 );
			break;
		case SDL_HAT_DOWN:
			buttonPushed.drawToCenter(rndWnd, x_pos, y_pos + hatsSquare.sprite.height() / 2 - buttonPushed.sprite.height() / 2 );
			break;
		case SDL_HAT_LEFTUP:
			buttonPushed.drawToCenter(rndWnd, x_pos - hatsSquare.sprite.width() / 2 + buttonPushed.sprite.width() / 2, y_pos - hatsSquare.sprite.height() / 2 + buttonPushed.sprite.height() / 2 );
			break;
		case SDL_HAT_LEFTDOWN:
			buttonPushed.drawToCenter(rndWnd, x_pos - hatsSquare.sprite.width() / 2 + buttonPushed.sprite.width() / 2, y_pos + hatsSquare.sprite.height() / 2 - buttonPushed.sprite.height() / 2 );
			break;
		case SDL_HAT_RIGHTUP:
			buttonPushed.drawToCenter(rndWnd, x_pos + hatsSquare.sprite.width() / 2 - buttonPushed.sprite.width() / 2, y_pos - hatsSquare.sprite.height() / 2 + buttonPushed.sprite.height() / 2 );
			break;
		case SDL_HAT_RIGHTDOWN:
			buttonPushed.drawToCenter(rndWnd, x_pos + hatsSquare.sprite.width() / 2 - buttonPushed.sprite.width() / 2, y_pos + hatsSquare.sprite.height() / 2 - buttonPushed.sprite.height() / 2 );
			break;
	}
}

void JoystickValuesTextures::drawSingleAxisSurface(sdl2::RendererWindow& rndWnd, int x_pos, int y_pos, Sint16 axisValue)
{
	axisGradientOff.draw(rndWnd, x_pos, y_pos);
	drawAxisValue(rndWnd, x_pos, y_pos, axisValue);
}

void JoystickValuesTextures::drawAxisValue(sdl2::RendererWindow& rndWnd, int x_pos, int y_pos, Sint16 axisValue)
{
	double multiplyHeight{ static_cast<double>(axisValue) / Sint16_MaxValue };
	
	if( axisValue > 0)
	{
		axisGradientRed.sprite.multiplyHeight( multiplyHeight );
		axisGradientRed.sprite.setDefaultCoord(x_pos, y_pos + squareSize - axisGradientRed.sprite.height());
		axisGradientRed.draw(rndWnd);
	}
	else if( axisValue < 0 )
	{
		axisGradientRed.sprite.multiplyHeight( -multiplyHeight );
		axisGradientRed.sprite.setDefaultCoord(x_pos, y_pos + squareSize);
		axisGradientRed.draw(rndWnd);
	}
	else{
		axisGradientRed.draw(rndWnd);
	}
}