#include "setupFiles/createFoldersInPrefPath.h"
#include "fileSystem/createNewElementFs.h"
#include "pathsFunctions/pathsFunctions.h"
#include "prefPath/prefPathFinder.h"
#include "logging/logsStruct.h"
#include "levels/gameActors/playerActorsConsts.h"
#include "consts/filesAndPaths.h"
#include "demos/consts/demosConsts.h"
#include "demos/consts/demoConfigFilesConsts.h"
#include "consts/soundsConsts.h"
#include "SDL_keyboard.h"
#include "SDL_mixer.h"
#include <fstream>
#include <sstream>

void filesSetup::setupFiles(const PrefPathFinder& prefPath, AppLogFiles& logs)
{
	if( createFs::FsNewError != createFs::mkDirectoryIfMissing(prefPath.getFsPath(), files::OptionsDir) 
		&& createFs::FsNewError != createFs::mkDirectoryIfMissing(prefPath.getFsPath(), files::InputsDir ) 
		&& createFs::FsNewError != createFs::mkDirectoryIfMissing(prefPath.getFsPath(), files::DemosDir )
		&& createFs::FsNewError != createFs::mkDirectoryIfMissing(prefPath.getFsPath(), files::DemosConfigDir )
		)
	{
		filesSetup::createFileInPath(logs, path::getOptionFilePath(prefPath, files::BobsMoveDelayFile), std::to_string( actors::DefaultMoveMicroSecDelay ) );
		filesSetup::createFileInPath(logs, path::getOptionFilePath(prefPath, files::PlayerMoveDelayFile), std::to_string( actors::DefaultMoveMicroSecDelay ) );
		filesSetup::createFileInPath(logs, path::getOptionFilePath(prefPath, files::PlayerCanEatCacti), "7000");
		filesSetup::createFileInPath(logs, path::getOptionFilePath(prefPath, files::BobsAnimDelayFile), "100");
		filesSetup::createFileInPath(logs, path::getOptionFilePath(prefPath, files::BobsEatableDelayFile), "20000");
		filesSetup::createFileInPath(logs, path::getOptionFilePath(prefPath, files::GreenOrbDurationFile), "14000");
		filesSetup::createFileInPath(logs, path::getOptionFilePath(prefPath, files::GreenOrbCreationDelay), "20000");
		filesSetup::createFileInPath(logs, path::getOptionFilePath(prefPath, sounds::SoundVolumeConfigFileName), "1 " + std::to_string(MIX_MAX_VOLUME / 2) );
		filesSetup::createFileInPath(logs, path::getPrefPathFilePath(prefPath, files::ChosenLanguageFile), files::DefaultLanguage );
		filesSetup::createFileInPath(logs, path::getPrefPathFilePath(prefPath, files::SdlLogoDisplayStatusFile), "1" );
		filesSetup::createFileInPath(logs, path::getInputsFilePath(prefPath, files::KeyboardInputsFile), filesSetup::getDefaultKeybInpFileStr() );
		filesSetup::createFileInPath(logs, path::getDemoConfigRelatedFile(prefPath, demos::files::NextPositionAndAction), std::to_string(demos::DefaultReservedDataForRecording) );
		filesSetup::createFileInPath(logs, path::getDemoConfigRelatedFile(prefPath, demos::files::ActionData), std::to_string(demos::DefaultReservedDataForRecording) );
		filesSetup::createFileInPath(logs, path::getDemoConfigRelatedFile(prefPath, demos::files::SoundsPlaying), std::to_string(demos::DefaultSmallDataReservedForRecording) );
		filesSetup::createFileInPath(logs, path::getDemoConfigRelatedFile(prefPath, demos::files::GameEvents), std::to_string(demos::DefaultSmallDataReservedForRecording) );
	}
	else{
		logs.error << "Error: couldn't create directories in '" << prefPath.getFsPath().string() << "' pref path.\n";
	}
}

void filesSetup::createFileInPath(AppLogFiles& logs, const fs::path& filePath, const std::string& dataToWrite)
{
	if( false == fs::exists( filePath ) )
	{
		if( std::ofstream file{ filePath } )
		{
			filesSetup::writeInOptionFile(logs, filePath, file, dataToWrite);
		}
		else{
			logs.error << "Error: couldn't open '" << filePath.string() << "' file in order to write data.\n";
		}
	}
	else{
		logs.warning << "The file '" << filePath.string() << "' already exists, it won't be overwritten.\n"; 
	}
}

void filesSetup::writeInOptionFile(AppLogFiles& logs, const fs::path& filePath, std::ofstream& file, const std::string& dataToWrite)
{
	if( ! ( file << dataToWrite ) )
	{
		logs.error << "Error: couldn't write data in '" << filePath.string() << "' file.\n";
	}
}

std::string filesSetup::getDefaultKeybInpFileStr()
{
	std::ostringstream keybStream;
	keybStream << SDLK_RIGHT << " " << SDLK_UP << " " << SDLK_LEFT << " " << SDLK_DOWN << " " << SDLK_SPACE;
	return keybStream.str();
}