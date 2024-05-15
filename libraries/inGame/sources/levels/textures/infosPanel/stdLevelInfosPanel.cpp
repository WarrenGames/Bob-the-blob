#include "levels/textures/infosPanel/stdLevelInfosPanel.h"
#include "levels/maps/bonusesMap.h"
#include "package/essentials.h"
#include "levels/loadings/gameConfigurationData.h"
#include "levels/playerAttributes/playerAttributes.h"
#include "levels/textures/gradients.h"
#include "consts/filesAndPaths.h"
#include "levels/textures/itemsCountConsts.h"
#include "levels/maps/bonusesConsts.h"

StdLevelInfosPanel::StdLevelInfosPanel(Essentials& essentials, PlayerAttributes& playerAttributes, const BonusesMap& bonusesMap, const GameConfigData& gameConfigData):
	infosBoard{ essentials, InfosBoardRedGranit },
	scoreDisplay{ essentials, playerAttributes },
	canBeEatenBobsGradient{ essentials, LeftGradient, 0, static_cast<unsigned>( gameConfigData.bobVulnerability.count() ), DarkGreen, BrightGreen },
	goldIngotsCountDisplay{ essentials, GoldIngotsCountRect, bonusesMap.getElementNumber(bonuses::BonusGoldIngot), GoldIngotIcon }
{

}

void StdLevelInfosPanel::drawEverything(sdl2::RendererWindow& rndWnd) const
{
	infosBoard.drawBoard(rndWnd);
	scoreDisplay.drawEverything(rndWnd);
	goldIngotsCountDisplay.drawEverything(rndWnd);
}