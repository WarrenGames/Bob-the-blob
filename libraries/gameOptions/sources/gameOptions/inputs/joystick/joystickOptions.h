#ifndef BOB_THE_BLOB_GAME_OPTIONS_JOYSTICK_DATA_H
#define BOB_THE_BLOB_GAME_OPTIONS_JOYSTICK_DATA_H

#include "inputsConfig/joystickInputsConfigData.h"
#include "widgets/buttons/highlightButtonWidget.h"
#include "widgets/editBoxes/uint_editBox.h"
#include "widgets/editBoxes/sint_editBox.h"
#include "texts/textLoader.h"
#include <vector>
#include <string>

struct Essentials;

class JoystickOptions
{
private:
	JoystickInputsConfig joystickInputsConfig;
	const TextsBlocks joystickElementsTexts;//Axes, hats or buttons
	const TextsBlocks joystickColumnsHeaders;
	const TextsBlocks joystickHatValues;
	std::vector< JoystickFuncElement > data;
	std::vector< TextureCombo > columnsTexts;
	std::vector< HighLightButton > joystickElementsButtons;
	std::vector< UintEditBox > elementNumbersEditBoxes;
	std::vector< HighLightButton > elementNumberValue;//For joystick hats
	TextureCombo axesThresholdText;
	int axesThreshold;
	SintEditBox thresholdEditBox;
	
public:
	explicit JoystickOptions(Essentials& essentials, const sdl2::Font& arialFont, const TextsBlocks& interfaceTexts);
	~JoystickOptions() = default;
	JoystickOptions( const JoystickOptions& ) = delete;
	JoystickOptions& operator= ( const JoystickOptions& ) = delete;
	JoystickOptions( JoystickOptions&& ) = default;
	JoystickOptions& operator= ( JoystickOptions&& ) = default;
	
	void drawEverything(sdl2::RendererWindow& rndWnd) const;
	void updateButtons(const Offset& mousePosition, bool mouseButtonState);
	void changeJoystickElementType(Essentials& essentials, const sdl2::Font& arialFont);
	void catchUserFocus(Essentials& essentials, const Offset& mousePosition, bool mouseButtonState);
	void changeElementValueHighlightButtons(Essentials& essentials, const sdl2::Font& arialFont);
	void recordModificationsToFile(Essentials& essentials, const fs::path& joystickConfigFile) const;
	void recordAxesThreshold(Essentials& essentials, const fs::path& joystickConfigFile) const;
	
private:
	void setElementsEnums();
	void setElementsNumbers();
	void createColumnsTexts(Essentials& essentials, const sdl2::Font& arialFont);
	void createJoyElementsHighlightButtons(Essentials& essentials, const sdl2::Font& arialFont);
	void createEditBoxes(Essentials& essentials);
	void createElementsValueHighlightButtons(Essentials& essentials, const sdl2::Font& arialFont);
	
	void changeElementValueHighlightButtons(Essentials& essentials, const sdl2::Font& arialFont, std::size_t lineIndex);
	
	void updateJoystickElementsButtons(const Offset& mousePosition, bool mouseButtonState);
	void updateJoystickElementValueButtons(const Offset& mousePosition, bool mouseButtonState);
	
	void drawColumnsTexts(sdl2::RendererWindow& rndWnd) const;
	void drawJoyElementsButtons(sdl2::RendererWindow& rndWnd) const;
	void drawUintBoxes(sdl2::RendererWindow& rndWnd) const;
	void drawElementsNumberValue(sdl2::RendererWindow& rndWnd) const;
	
	void actWithJoystickHatSelection(Essentials& essentials);
};

std::string getElementNameFromValue(unsigned elementType, const TextsBlocks& texts);

std::string getHatStringFromValue(const TextsBlocks& texts, unsigned elementValue);

void switchToNextJoystickElement(JoystickFuncElement& data);

void switchToNextHatValue(unsigned& elementValue);

#endif //BOB_THE_BLOB_GAME_OPTIONS_JOYSTICK_DATA_H