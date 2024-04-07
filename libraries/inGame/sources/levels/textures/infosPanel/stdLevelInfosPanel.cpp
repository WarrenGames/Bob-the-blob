#include "levels/textures/infosPanel/stdLevelInfosPanel.h"
#include "levels/maps/bonusesMap.h"
#include "package/essentials.h"
#include "levels/playerAttributes/playerAttributes.h"
#include "levels/loadings/getConfigFileNumber.h"
#include "levels/textures/gradients.h"
#include "consts/filesAndPaths.h"
#include "levels/textures/itemsCountConsts.h"
#include "levels/maps/bonusesConsts.h"

StdLevelInfosPanel::StdLevelInfosPanel(Essentials& essentials, PlayerAttributes& playerAttributes, const BonusesMap& bonusesMap):
	infosBoard{ essentials, InfosBoardRedGranit },
	scoreDisplay{ essentials, playerAttributes },
	canBeEatenBobsGradient{ essentials, LeftGradient, 0, getUnsignedIntFromFile(essentials.prefPath.getFsPath() / files::OptionsDir / files::BobsEatableDelayFile, 
							"eatable bobs delay for info gradient" ), DarkGreen, BrightGreen },
	goldIngotsCountDisplay{ essentials, GoldIngotsCountRect, bonusesMap.getElementNumber(bonuses::BonusGoldIngot), GoldIngotIcon }
{

}

void StdLevelInfosPanel::drawEverything(sdl2::RendererWindow& rndWnd) const
{
	infosBoard.drawBoard(rndWnd);
	scoreDisplay.drawEverything(rndWnd);
	goldIngotsCountDisplay.drawEverything(rndWnd);
}