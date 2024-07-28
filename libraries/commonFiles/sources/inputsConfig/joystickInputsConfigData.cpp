#include "inputsConfig/joystickInputsConfigData.h"
#include "pathsFunctions/pathsFunctions.h"
#include "prefPath/prefPathFinder.h"
#include "logging/logsStruct.h"
#include "consts/playerInputsConsts.h"
#include "consts/filesAndPaths.h"
#include "SDL_joystick.h"
#include <fstream>
#include <string>
#include <cassert>
#include <limits>

JoystickFuncElement::JoystickFuncElement():
	joystickElement{ JoyMoveWithMax },
	elementNumber{ 0 },
	elementValue{ 0 }
{
	
}

JoystickFuncElement::JoystickFuncElement(unsigned joyElement, unsigned elementNum, unsigned elementVal):
	joystickElement{ joyElement },
	elementNumber{ elementNum },
	elementValue{ elementVal }
{
	
}

JoystickInputsConfig::JoystickInputsConfig(AppLogFiles& logs, const PrefPathFinder& prefPath):
	configData( MoveMax ),
	axesThreshold{ std::numeric_limits<Sint16>::max() / 2 },
	isLoadingPerfect{ true }
{
	loadData(logs, path::getInputsFilePath(prefPath, files::JoystickInputsFile) );
	loadAxesThreshold(logs, path::getInputsFilePath(prefPath, files::JoystickAxesThresholdFile) );
}

unsigned JoystickInputsConfig::getJoyElement(std::size_t i) const
{
	assert( i < configData.size() );
	return configData[i].joystickElement;
}

unsigned JoystickInputsConfig::getElementNumber(std::size_t i) const
{
	assert( i < configData.size() );
	return configData[i].elementNumber;
}

unsigned JoystickInputsConfig::getElementValue(std::size_t i) const
{
	assert( i < configData.size() );
	return configData[i].elementValue;
}

std::size_t JoystickInputsConfig::size() const
{
	return configData.size();
}

bool JoystickInputsConfig::wasLoadingPerfect() const
{
	return isLoadingPerfect;
}

int JoystickInputsConfig::getAxesTheshold() const
{
	return axesThreshold;
}

void JoystickInputsConfig::loadData(AppLogFiles& logs, const fs::path& joystickInputsConfig)
{
	if( std::ifstream joyFile{ joystickInputsConfig } )
	{
		std::string fileLine;
		std::size_t fileLineNumber{1};
		while( std::getline( joyFile, fileLine ) )
		{
			std::istringstream lineStream{ fileLine };
			readLineStream(logs, joystickInputsConfig, lineStream, fileLineNumber);
			fileLineNumber++;
		}
	}
	else{
		logs.error.wrFileOpeningError(joystickInputsConfig, "load joystick configuration data");
		isLoadingPerfect = false;
	}
}

void JoystickInputsConfig::readLineStream(AppLogFiles& logs, const fs::path& joystickInputsConfig, std::istringstream& lineStream, std::size_t fileLineNumber)
{
	unsigned funcEnum{ MoveMax };
	if( lineStream >> funcEnum )
	{
		if( funcEnum < MoveMax )
		{
			assert( configData.size() == MoveMax );
			if( ! ( lineStream >> configData[funcEnum].joystickElement >> configData[funcEnum].elementNumber >> configData[funcEnum].elementValue ) )
			{
				logs.error << "Error: couldn't set data of joystick configuration with '" << joystickInputsConfig.string() << "' file at line number " << fileLineNumber << " .\n";
				isLoadingPerfect = false;
			}
		}
		else{
			logs.error << "Error: bad func enum value: " << funcEnum << " at line number " << fileLineNumber << " in '" << joystickInputsConfig.string() << "' joystick file.\n";
			isLoadingPerfect = false;
		}
	}
	else{
		logs.error.wrReadErrorMessage(joystickInputsConfig, "joystick data", fileLineNumber);
		isLoadingPerfect = false;
	}
}

void JoystickInputsConfig::loadAxesThreshold(AppLogFiles& logs, const fs::path& joystickAxesThresholdInputsConfig)
{
	if( std::ifstream joyFile{ joystickAxesThresholdInputsConfig } )
	{
		std::string fileLine;
		if( std::getline( joyFile, fileLine ) )
		{
			unsigned thresholdLineId{0};
			std::istringstream lineStream{ fileLine };
			if( !( lineStream >> thresholdLineId >> axesThreshold && thresholdLineId == JoyAxesThresholdId ) )
			{
				logs.error.wrReadErrorMessage(joystickAxesThresholdInputsConfig, "joystick threshold data (line stream step)", 1);
				isLoadingPerfect = false;
			}
		}
		else{
			logs.error.wrReadErrorMessage(joystickAxesThresholdInputsConfig, "joystick threshold data (std::getline() step)", 1);
			isLoadingPerfect = false;
		}
	}
	else{
		logs.error.wrFileOpeningError(joystickAxesThresholdInputsConfig, "load joystick axes threshold configuration data");
		isLoadingPerfect = false;
	}
}