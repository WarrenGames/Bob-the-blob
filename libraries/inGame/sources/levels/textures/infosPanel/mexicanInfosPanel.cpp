#include "levels/textures/infosPanel/mexicanInfosPanel.h"
#include "levels/maps/bonusesMap.h"
#include "levels/gameActors/cactus/cactiPackage.h"
#include "package/essentials.h"
#include "levels/playerAttributes/playerAttributes.h"
#include "levels/loadings/gameConfigurationData.h"
#include "texturing/texturePosition.h"
#include "levels/textures/gradients.h"
#include "consts/filesAndPaths.h"
#include "levels/textures/itemsCountConsts.h"
#include "levels/maps/bonusesConsts.h"

MexicanInfosPanel::MexicanInfosPanel(Essentials& essentials, PlayerAttributes& playerAttributes, const BonusesMap& bonusesMap, const CactiPackage& cacti, 
										const GameConfigData& gameConfigData):
	infosBoard{ essentials, InfosBoardGreenGranit },
	scoreDisplay{ essentials, playerAttributes },
	canBeEatenBobsGradient{ essentials, LeftGradient, 0, static_cast<unsigned>( gameConfigData.bobVulnerability.count() ), DarkGreen, BrightGreen },
	canBeEatenCactiGradient{ essentials, RightGradient, 0, static_cast<unsigned>( gameConfigData.playerCanEatCactiDelay.count() ), DarkYellow, BrightYellow },
	goldIngotsCountDisplay{ essentials, GoldIngotsCountRect, bonusesMap.getElementNumber(bonuses::BonusGoldIngot), GoldIngotIcon },
	cactiCountDisplay{ essentials, CactusCountRect, cacti.getEffectiveCactiNumber(), CactusIcon }
{

}

void MexicanInfosPanel::drawEverything(sdl2::RendererWindow& rndWnd) const
{
	infosBoard.drawBoard(rndWnd);
	scoreDisplay.drawEverything(rndWnd);
	goldIngotsCountDisplay.drawEverything(rndWnd);
	cactiCountDisplay.drawEverything(rndWnd);
}