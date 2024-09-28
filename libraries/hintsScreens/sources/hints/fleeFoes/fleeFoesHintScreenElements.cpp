#include "hints/fleeFoes/fleeFoesHintScreenElements.h"
#include "package/essentials.h"
#include "paragraph/makeTextTextures.h"
#include "paragraph/paragraphData.h"
#include "pathsFunctions/pathsFunctions.h"
#include "levels/textures/texturesConsts.h"
#include "levels/demosRecordingAndPlaying/consts/demosConsts.h"
#include "consts/includeOptions.h"
#include "consts/fontsSizes.h"

constexpr char MiniMapPath[] = "data/helpScreens/fleeFoesMiniMap.txt";
constexpr int ExplanationsTextWidth = 10 * SQR_SIZE;
constexpr SDL_Color TextColor = { 255, 127, 0, 255 };
constexpr char HelpTextSubPath[] = "helpScreens/fleeEnemies.txt";
constexpr char LeftRightArrowTexturePath[] = "textures/gameGUI/helpScreens/fleeFoes_0.png";
constexpr char UpDownArrowTexturePath[] = "textures/gameGUI/helpScreens/fleeFoes_1.png";

hintsScreens::FleeFoes::FleeFoes(Essentials& essentials):
	isLoadingPerfect{ true },
	mapLeftCorner{ 13, 1 },
	miniMapData{ essentials.logs, MiniMapPath, isLoadingPerfect, demos::GameHasPlayerInputs },
	miniMapTextures{ essentials.logs, essentials.rndWnd, textures::WallsTexturesFilePath },
	miniMapSprites{ miniMapTextures },
	leftRightFleeArrows{ essentials.logs, essentials.rndWnd, LeftRightArrowTexturePath },
	upDownFleeArrows{ essentials.logs, essentials.rndWnd, UpDownArrowTexturePath },
	topArrows{ upDownFleeArrows, 16 * SQR_SIZE, SQR_SIZE },
	bottomArrows{ upDownFleeArrows, 16 * SQR_SIZE, 13 * SQR_SIZE },
	leftArrows{ leftRightFleeArrows, 13 * SQR_SIZE, 8 * SQR_SIZE },
	rightArrows{ leftRightFleeArrows, 18 * SQR_SIZE, 8 * SQR_SIZE }
{
	ParagraphData paragraphData{ essentials.logs, path::getLanguageFile(essentials.chosenLanguage, HelpTextSubPath), ArialFontPath, MediumFontSize, TextColor, ExplanationsTextWidth };
	makeText::openFileForReading( essentials.logs, essentials.rndWnd, paragraphData, infosText );
	setTextPosition();
}

void hintsScreens::FleeFoes::drawEverything(Essentials& essentials)
{
	drawMap(essentials);
	drawArrows(essentials);
	drawInfosText(essentials);
}

void hintsScreens::FleeFoes::drawMap(Essentials& essentials)
{
	for( std::size_t x{0} ; x < miniMapData.matrix.width() ; ++x )
	{
		for( std::size_t y{0} ; y < miniMapData.matrix.height() ; ++y )
		{
			mapCoords.x = (mapLeftCorner.x + static_cast<int>(x) ) * SQR_SIZE;
			mapCoords.y = (mapLeftCorner.y + static_cast<int>(y) ) * SQR_SIZE;
			miniMapSprites.drawSprite(essentials.rndWnd, mapCoords.x, mapCoords.y, miniMapData.matrix(x,y).mapIndex, miniMapData.matrix(x,y).indexProperty); 
		}
	}
}

void hintsScreens::FleeFoes::setTextPosition()
{
	for( std::size_t i{0} ; i < infosText.size() ; ++i )
	{
		infosText[i].sprite.setXPos( SQR_SIZE );
		infosText[i].sprite.setYPos( static_cast<int>( i ) * SQR_SIZE / 2 + SQR_SIZE * 2, true );
	}
}

void hintsScreens::FleeFoes::drawInfosText(Essentials& essentials) const
{
	for( auto const &textLine : infosText )
	{
		textLine.draw(essentials.rndWnd);
	}
}

void hintsScreens::FleeFoes::drawArrows(Essentials& essentials) const
{
	topArrows.draw(essentials.rndWnd);
	bottomArrows.draw(essentials.rndWnd);
	leftArrows.draw(essentials.rndWnd);
	rightArrows.draw(essentials.rndWnd);
}