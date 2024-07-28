#ifndef JOYSTICK_CALIBR_H
#define JOYSTICK_CALIBR_H

#include "joystick/joystickEntity.h"
#include "texturing/texturesCombo.h"
#include "texturing/texturePosition.h"
#include "widgets/editBoxes/uint_editBox.h"
#include "widgets/editBoxes/sint_editBox.h"
#include "customTypes/positionTypes.h"
#include "time/accurateTime.h"
#include "texts/textLoader.h"

namespace sdl2{ class RendererWindow; }

class JoystickCalibration
{
private:
	int movesSquareSide;
	int editBoxesHeight;
	const TextsBlocks languagesTexts;
	TextureCombo moveSquare;
	TextureCombo reticule;
	TexturePosition reticulePos;
	
	sdl2::JoystickEntity joyEnt;
		
	Sint16 horizontalAxisValue;
	Sint16 verticalAxisValue;
	Uint8 hatValue;
	Offset mousePosition;
	bool leftMouseButtonState;
	int axisThreshold;
	unsigned horizontalAxisNumber;
	unsigned verticalAxisNumber;
	TextureCombo thresholdHelpText;
	SintEditBox thresholdBox;
	const TextureCombo horizontalHelpText; 
	UintEditBox horizontalAxisNumberBox;
	const TextureCombo verticalHelpText;
	UintEditBox verticalAxisNumberBox;
	
	bool escapeState;
	bool sdlQuit;
	AccurateTimeDelay moveTime;
	const TextureCombo calibrationHelp;
	const TextureCombo quitScreenKey;
	
public:
	explicit JoystickCalibration(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const sdl2::Font& arialFont, const fs::path& languageTextsPath, int SquareSize);
	~JoystickCalibration() = default;
	JoystickCalibration (const JoystickCalibration& ) = delete;
	JoystickCalibration& operator= (const JoystickCalibration& ) = delete;
	JoystickCalibration( JoystickCalibration&& ) = default;
	JoystickCalibration& operator= ( JoystickCalibration&& ) = default;
	
	void drawAll(sdl2::RendererWindow& rndWnd) const;
	void updateEvents();
	void updateMouseButton(unsigned buttonNumber, bool clicked);
	void updateEditBoxes(AppLogFiles& logs, sdl2::RendererWindow& rndWnd);
	void moveWithHat();
	void moveWithAxes();
	void actWithAxesThresholdOnX(Sint16 joystickThreshold);
	void actWithAxesThresholdOnY(Sint16 joystickThreshold);
	
	void moveReticule(int xincr, int yincr);
	bool quitContext() const;
	void setToQuit();
	void setMouseButtonToFalse();
};

#endif//JOYSTICK_CALIBR_H