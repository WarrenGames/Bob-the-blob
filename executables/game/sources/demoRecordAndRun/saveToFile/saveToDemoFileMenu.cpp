#include "demoRecordAndRun/saveToFile/saveToDemoFileMenu.h"
#include "package/essentials.h"
#include "demos/data/dataPackage.h"
#include "demos/templates/stacksAlgorithms.h"
#include "pathsFunctions/pathsFunctions.h"
#include "texturing/texturePosition.h"
#include "consts/colors.h"
#include "consts/fontsSizes.h"
#include "consts/screenConsts.h"
#include <algorithm>

constexpr char TextsFileSubPath[] = "demosMenu/toFileSaving.txt";

saveDemo::FileMenu::FileMenu(Essentials& essentials, const demos::DataPackage& demoDataPackage):
	fileName{"demo.txt"},
	menuTexts{ essentials.logs.error, path::getLanguageFile(essentials.chosenLanguage, TextsFileSubPath), saveDemo::TxtMax },
	arialFont{ essentials.logs.error, ArialFontPath, MediumFontSize },
	menuTitle{ essentials.logs, essentials.rndWnd, arialFont, menuTexts[saveDemo::TxtTitle], WhiteCol, TexturePosition{ GameScreenWidth / 2, SQR_SIZE, true, true } },
	fileNameTextHint{ essentials.logs, essentials.rndWnd, arialFont, menuTexts[saveDemo::TxtFileNameHint], WhiteCol, TexturePosition{ SQR_SIZE, SQR_SIZE * 3, false, false } },
	recordedPlayerMoves{ essentials.logs, essentials.rndWnd, arialFont, saveDemo::FileMenu::getMaxRecPlayerText(demoDataPackage.spritesPositions), WhiteCol, 
		TexturePosition{ SQR_SIZE, SQR_SIZE * 5, false, true } },
	recordedBobsMoves{ essentials.logs, essentials.rndWnd, arialFont, saveDemo::FileMenu::getMaxRecBobsText(demoDataPackage.spritesPositions), WhiteCol,
		TexturePosition{ SQR_SIZE, SQR_SIZE * 5 + SQR_SIZE / 2, false, true } },
	fileNameBox{ essentials.logs, essentials.rndWnd, SDL_Rect{ SQR_SIZE * 4, SQR_SIZE * 3, SQR_SIZE * 6, SQR_SIZE * 3 / 4}, MediumFontSize, fileName, 64 },
	saveToFileButton{ essentials.logs, essentials.rndWnd, arialFont, menuTexts[saveDemo::TxtSaveBtn], WhiteCol, GrayCol, TexturePosition{ SQR_SIZE * 4, SQR_SIZE * 14, true, true } },
	quitWithoutSaving{ essentials.logs, essentials.rndWnd, arialFont, menuTexts[saveDemo::TxtQuitBtn], WhiteCol, GrayCol, TexturePosition{ SQR_SIZE * 16, SQR_SIZE * 14, true, true } }
{
	
}

void saveDemo::FileMenu::drawEverything(Essentials& essentials) const
{
	menuTitle.draw(essentials.rndWnd);
	fileNameTextHint.draw(essentials.rndWnd);
	recordedPlayerMoves.draw(essentials.rndWnd);
	recordedBobsMoves.draw(essentials.rndWnd);
	fileNameBox.drawBoxWithoutFocus(essentials.rndWnd);
	saveToFileButton.drawButton(essentials.rndWnd);
	quitWithoutSaving.drawButton(essentials.rndWnd);
}

void saveDemo::FileMenu::updateInterface(Essentials& essentials)
{
	fileNameBox.catchUserFocus(essentials.logs, essentials.rndWnd, essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
	saveToFileButton.updateButton(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
	quitWithoutSaving.updateButton(essentials.inputs.getMousePosition(), essentials.inputs.getMouseButtonState(SDL_BUTTON_LEFT) );
}

std::string saveDemo::FileMenu::getMaxRecPlayerText(const demos::SpritesPositions& spritesPositions) const
{
	return menuTexts[saveDemo::TxtMaxPlayerRecordedPoints] + std::to_string( getGreaterStackSize(spritesPositions.playersMoves) );
}

std::string saveDemo::FileMenu::getMaxRecBobsText(const demos::SpritesPositions& spritesPositions) const
{
	return menuTexts[saveDemo::TxtMaxBobsRecordedPoints] + std::to_string( getGreaterStackSize(spritesPositions.enemyBobsMoves) );
}
	