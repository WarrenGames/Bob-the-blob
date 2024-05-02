#ifndef BOB_THE_BLOB_COMMON_FILES_FILES_AND_PATHS_H
#define BOB_THE_BLOB_COMMON_FILES_FILES_AND_PATHS_H

namespace files{
	
	constexpr char Mexican1[] = "mexican1";
	constexpr char BlueBricks1[] = "blueBricks1";
	constexpr char BlueBricks2[] = "blueBricks2";
	
	constexpr char DefaultMapsFilesDir[] = "data/levelsMaps";
	constexpr char DefaultMapsExtension[] = ".grid";
	constexpr char DefaultBonusesFileSuffix[] = "_bonuses.txt";
	constexpr char DefaultEnemyBobsFileSuffix[] = "_bobsData.txt";
	constexpr char DefaultPlayerStartingPositionSuffix[] = "_playerStartPosition.txt";
	constexpr char DefaultMapSubDivisionSuffix[] = "_subDivisions.txt";
	
	constexpr char DemosDir[] = "demos";
	constexpr char DemosConfigDir[] = "demosConfig";
	
	constexpr char OptionsDir[] = "options";
	constexpr char PlayerMoveDelayFile[] = "playerMoveDelay.txt";
	constexpr char BobsMoveDelayFile[] = "bobsMoveDelay.txt";
	constexpr char BobsAnimDelayFile[] = "bobsAnimDelay.txt";
	constexpr char BobsEatableDelayFile[] = "bobsVulnerabilityDelay.txt";
	constexpr char GreenOrbDurationFile[] = "greenOrbDuration.txt";
	constexpr char GreenOrbCreationDelay[] = "greenOrbCreation.txt";
	constexpr char BobsSpawnDelay[] = "bobsSpawnDelay.txt";
	
	constexpr char InputsDir[] = "inputs";
	constexpr char KeyboardInputsFile[] = "keyboardInputs.txt";
	
	constexpr char PlayerCanEatCacti[] = "playerCanEatCactiDelay.txt";
	
	constexpr char SdlLogoDisplayStatusFile[] = "sdlLogoDisplayStatus.txt";
	constexpr char ChosenLanguageFile[] = "chosenLanguage.txt";
	
	constexpr char DefaultLanguage[] = "english";
	
	constexpr char LanguagesFilesDirectory[] = "data/languages";
	constexpr char SdlLogoDisplayLanguageFile[] = "versioning/sdlVersion.txt";
}

#endif //BOB_THE_BLOB_COMMON_FILES_FILES_AND_PATHS_H