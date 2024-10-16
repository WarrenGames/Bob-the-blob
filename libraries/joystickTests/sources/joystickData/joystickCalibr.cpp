#include "joystickData/joystickCalibr.h"
#include "texturing/rendererWindow.h"
#include "logging/logsStruct.h"
#include "SDL_events.h"
#include <limits>

constexpr SDL_Color BlackCol = { 0, 0, 0, 255 };
constexpr SDL_Color RedCol = { 255, 0, 0, 255 };
constexpr SDL_Color WhiteCol = { 255, 255, 255, 255 };

enum{	CalibrateQuit, 
		CalibrateHelpTune,
		CalibrateHorizontalAxisNumber,
		CalibrateVerticalAxisNumber,
		CalibrateAxisThreshold,
		CalibrateMax };

JoystickCalibration::JoystickCalibration(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const sdl2::Font& arialFont, const fs::path& languageTextsPath, int squareSize):
	movesSquareSide{ squareSize * 4 },
	editBoxesHeight{ squareSize / 2 },
	languagesTexts{ logs.error, languageTextsPath, CalibrateMax},
	moveSquare{ logs, rndWnd, WhiteCol, movesSquareSide, movesSquareSide, TexturePosition{ Offset{ rndWnd.width() / 2, rndWnd.height() / 2 - squareSize * 2 }, true, true} },
	reticule{ logs, rndWnd, RedCol, squareSize / 2, squareSize / 2, TexturePosition{ Offset{ rndWnd.width() / 2, rndWnd.height() / 2 - squareSize * 2 }, true, true} },
	reticulePos{ Offset{ rndWnd.width() / 2, rndWnd.height() / 2 - squareSize * 2 }, true, true},
	joyEnt{ 0 },
	horizontalAxisValue{0},
	verticalAxisValue{0},
	hatValue{SDL_HAT_CENTERED},
	mousePosition{ 0, 0 },
	leftMouseButtonState{ false },
	axisThreshold{ std::numeric_limits<Sint16>::max() / 2 },
	horizontalAxisNumber{ 0 },
	verticalAxisNumber{ 1 },
	thresholdHelpText{ logs, rndWnd, arialFont, languagesTexts[CalibrateAxisThreshold], BlackCol, TexturePosition{ squareSize, rndWnd.height() - squareSize * 2, false, true } },
	thresholdBox{ logs, rndWnd, SDL_Rect{ squareSize * 2 + thresholdHelpText.sprite.width(), 
											thresholdHelpText.sprite.y_pos() + thresholdHelpText.sprite.height() / 2 - editBoxesHeight / 2, squareSize * 3, squareSize / 2}, 
											squareSize / 3, axisThreshold },
	horizontalHelpText{ logs, rndWnd, arialFont, languagesTexts[CalibrateHorizontalAxisNumber], BlackCol, TexturePosition{ squareSize, rndWnd.height() - squareSize * 4, false, true} },
	horizontalAxisNumberBox{ logs, rndWnd, SDL_Rect{ squareSize * 2 + horizontalHelpText.sprite.width(),
											horizontalHelpText.sprite.y_pos() + horizontalHelpText.sprite.height() / 2 - editBoxesHeight / 2, squareSize * 2, squareSize / 2 },
											squareSize / 3, horizontalAxisNumber },
	verticalHelpText{ logs, rndWnd, arialFont, languagesTexts[CalibrateVerticalAxisNumber], BlackCol, TexturePosition{ squareSize, rndWnd.height() - squareSize * 3, false, true } },
	verticalAxisNumberBox{ logs, rndWnd, SDL_Rect{ squareSize * 2 + verticalHelpText.sprite.width(),
											verticalHelpText.sprite.y_pos() + verticalHelpText.sprite.height() / 2 - editBoxesHeight / 2, squareSize * 2, squareSize / 2 },
											squareSize / 3, verticalAxisNumber },
	escapeState{false},
	sdlQuit{false},
	calibrationHelp{ logs, rndWnd, arialFont, languagesTexts[CalibrateHelpTune], BlackCol, 
										TexturePosition{ Offset{ rndWnd.width() / 2, rndWnd.height() - squareSize }, true} },
	quitScreenKey{ logs, rndWnd, arialFont, languagesTexts[CalibrateQuit], BlackCol, 
										TexturePosition{ Offset{ rndWnd.width() / 2, squareSize }, true} }
{
	
}

void JoystickCalibration::drawAll(sdl2::RendererWindow& rndWnd) const
{
	moveSquare.draw(rndWnd);
	reticule.draw(rndWnd);
	calibrationHelp.draw(rndWnd);
	quitScreenKey.draw(rndWnd);
	thresholdHelpText.draw(rndWnd);
	thresholdBox.drawBoxWithoutFocus(rndWnd);
	horizontalHelpText.draw(rndWnd);
	horizontalAxisNumberBox.drawBoxWithoutFocus(rndWnd);
	verticalHelpText.draw(rndWnd);
	verticalAxisNumberBox.drawBoxWithoutFocus(rndWnd);
}

void JoystickCalibration::updateEvents()
{
	SDL_Event event;
	while( SDL_PollEvent(&event) )
	{
		switch(event.type)
		{
			case SDL_QUIT:
				sdlQuit = true;
				break;
			case SDL_KEYDOWN:
				if( event.key.keysym.sym == SDLK_ESCAPE)
					escapeState = true;
				break;
			case SDL_KEYUP:
				if( event.key.keysym.sym == SDLK_ESCAPE )
					escapeState = false;
				break;
			case SDL_MOUSEMOTION:
				mousePosition.x = event.motion.x;
				mousePosition.y = event.motion.y;
				break;
			case SDL_MOUSEBUTTONUP:
				updateMouseButton(event.button.button, false);
				break;
			case SDL_MOUSEBUTTONDOWN:
				updateMouseButton(event.button.button, true);
				break;
			case SDL_JOYHATMOTION:
				hatValue = event.jhat.value;
				break;
			case SDL_JOYAXISMOTION:
				if( static_cast<unsigned>(event.jaxis.axis) == horizontalAxisNumber )
					horizontalAxisValue = event.jaxis.value;
				if( static_cast<unsigned>(event.jaxis.axis) == verticalAxisNumber )
					verticalAxisValue = event.jaxis.value;
				break;
		}
	}
}

void JoystickCalibration::updateMouseButton(unsigned buttonNumber, bool clicked)
{
	if( buttonNumber == SDL_BUTTON_LEFT )
	{
		leftMouseButtonState = clicked;
	}
}

void JoystickCalibration::updateEditBoxes(AppLogFiles& logs, sdl2::RendererWindow& rndWnd)
{
	thresholdBox.catchUserFocus(logs, rndWnd, mousePosition, leftMouseButtonState);
	horizontalAxisNumberBox.catchUserFocus(logs, rndWnd, mousePosition, leftMouseButtonState);
	verticalAxisNumberBox.catchUserFocus(logs, rndWnd, mousePosition, leftMouseButtonState);
}

void JoystickCalibration::moveWithHat()
{
	switch( hatValue )
	{
		case SDL_HAT_LEFT:
			moveReticule(-1, 0 );
			break;
		case SDL_HAT_RIGHT:
			moveReticule(1, 0 );
			break;
		case SDL_HAT_UP:
			moveReticule(0, -1 );
			break;
		case SDL_HAT_DOWN:
			moveReticule(0, 1 );
			break;
		case SDL_HAT_LEFTUP:
			moveReticule(-1, -1 );
			break;
		case SDL_HAT_LEFTDOWN:
			moveReticule(-1, 1 );
			break;
		case SDL_HAT_RIGHTUP:
			moveReticule(1, -1 );
			break;
		case SDL_HAT_RIGHTDOWN:
			moveReticule(1, 1 );
			break;
	}
}

void JoystickCalibration::moveWithAxes()
{
	actWithAxesThresholdOnX( static_cast<Sint16>(axisThreshold) );
	actWithAxesThresholdOnY( static_cast<Sint16>(axisThreshold) );
}

void JoystickCalibration::actWithAxesThresholdOnX(Sint16 joystickThreshold)
{
	if( horizontalAxisValue >= joystickThreshold )
		moveReticule(1, 0);
	if( horizontalAxisValue <= -joystickThreshold )
		moveReticule(-1, 0);
}

void JoystickCalibration::actWithAxesThresholdOnY(Sint16 joystickThreshold)
{
	if( verticalAxisValue >= joystickThreshold )
		moveReticule(0, 1);
	if( verticalAxisValue <= -joystickThreshold )
		moveReticule(0, -1);
}

void JoystickCalibration::moveReticule(int xincr, int yincr)
{	
	if( moveTime.hasTimeElapsed( std::chrono::milliseconds{movesSquareSide / 2 / 2000} ) )
	{
		moveTime.joinTimePoints();
		if( reticulePos.position.x + xincr >= moveSquare.sprite.x_pos()  
			&& reticulePos.position.x + xincr < moveSquare.sprite.x_pos() + moveSquare.sprite.width() )
		{
			reticulePos.position.x += xincr;
		}
		
		if( reticulePos.position.y + yincr >= moveSquare.sprite.y_pos() 
			&& reticulePos.position.y + yincr < moveSquare.sprite.y_pos() + moveSquare.sprite.height() )
		{
			reticulePos.position.y += yincr;
		}
		reticule.sprite.setTexturePosition(reticulePos);
	}
}

bool JoystickCalibration::quitContext() const
{
	if( escapeState || sdlQuit )
		return true;
	else
		return false;
}

void JoystickCalibration::setToQuit()
{
	sdlQuit = true;
}

void JoystickCalibration::setMouseButtonToFalse()
{
	leftMouseButtonState = false;
}