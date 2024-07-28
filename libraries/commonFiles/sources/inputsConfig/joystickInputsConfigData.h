#ifndef BOB_THE_BLOB_COMMON_FILES_JOYSTICK_INPUTS_CONFIG_H
#define BOB_THE_BLOB_COMMON_FILES_JOYSTICK_INPUTS_CONFIG_H

#include "fileSystem/fileSystem.h"
#include <vector>
#include <sstream>

struct AppLogFiles;
class PrefPathFinder;

struct JoystickFuncElement
{
	unsigned joystickElement; //Hat, Axis or Button
	unsigned elementNumber; //Hat direction, Axis number or of course button number
	unsigned elementValue;//Axis value, hat value or ignored if a button is selected
	
	explicit JoystickFuncElement();
	explicit JoystickFuncElement(unsigned joyElement, unsigned elementNum, unsigned elementVal);
	~JoystickFuncElement() = default;
	JoystickFuncElement( const JoystickFuncElement& ) = default;
	JoystickFuncElement& operator= ( const JoystickFuncElement& ) = default;
};

class JoystickInputsConfig
{
private:
	std::vector< JoystickFuncElement > configData;
	int axesThreshold;
	bool isLoadingPerfect;
	
public:
	explicit JoystickInputsConfig(AppLogFiles& logs, const PrefPathFinder& prefPath);
	~JoystickInputsConfig() = default;
	JoystickInputsConfig( const JoystickInputsConfig& ) = delete;
	JoystickInputsConfig& operator= ( const JoystickInputsConfig& ) = delete;
	JoystickInputsConfig( JoystickInputsConfig&& ) = default;
	JoystickInputsConfig& operator= ( JoystickInputsConfig&& ) = default;
	
	unsigned getJoyElement(std::size_t i) const;
	unsigned getElementNumber(std::size_t i) const;
	unsigned getElementValue(std::size_t i) const;
	std::size_t size() const;
	bool wasLoadingPerfect() const;
	int getAxesTheshold() const;
	
private:
	void loadData(AppLogFiles& logs, const fs::path& joystickInputsConfig);
	void readLineStream(AppLogFiles& logs, const fs::path& joystickInputsConfig, std::istringstream& lineStream, std::size_t fileLineNumber);
	
	void loadAxesThreshold(AppLogFiles& logs, const fs::path& joystickAxesThresholdInputsConfig);
};

#endif //BOB_THE_BLOB_COMMON_FILES_JOYSTICK_INPUTS_CONFIG_H