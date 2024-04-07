#include "levels/global/actWithBonuses.h"
#include "levels/gameActors/playerThings/singlePlayerData.h"
#include "levels/gameActors/bobThings/bobsPackage.h"
#include "levels/gameActors/magicOrbs/orbsPackage.h"
#include "demos/data/dataPackage.h"
#include "levels/playerAttributes/playerAttributes.h"
#include "levels/gameActors/playerThings/playerMapRelativeAbilities.h"
#include "levels/textures/common/commonSprite.h"
#include "levels/maps/bonusesMap.h"
#include "levels/textures/texturesConsts.h"
#include "levels/maps/mapsConsts.h"
#include "levels/gameActors/playerActorsConsts.h"
#include "levels/maps/bonusesConsts.h"
#include <cassert>

void eatBonusWithPlayer(SinglePlayerData& player, BonusesMap& bonusesMap, BobsPackage& bobsPackage, PlayerAttributes& playerAttributes)
{
	//if( player.move.hasReachCenterOfSquare() )
	//{
		if( bonusesMap.areCoordinatesInsideBoundaries(player.move.getMatrixPosition() ) )
		{
			if( bonusesMap.getElement(player.move.getMatrixPosition() ).isPresent )
			{
				switch( bonusesMap.getElement(player.move.getMatrixPosition() ).bonusIndex )
				{
					case bonuses::BonusGlassMarble:
						playerAttributes.addToScore(map::GlassMarbleWorth);
						bonusesMap.getElement(player.move.getMatrixPosition() ).isPresent = false;
						bonusesMap.decrementElementNumberCount(bonuses::BonusGlassMarble);
						break;
					case bonuses::BonusApple:
						player.abilities[abilities::CanEatBob].startAbility();
						player.abilities.setDemoFlag(abilities::CanEatBob, true);
						bobsPackage.makeBobsNotSeekingPlayer();
						playerAttributes.addToScore(map::AppleWorth);
						bonusesMap.getElement(player.move.getMatrixPosition() ).isPresent = false;
						bonusesMap.decrementElementNumberCount(bonuses::BonusApple);
						break;
					case bonuses::BonusDiamond:
						playerAttributes.addToScore(map::DiamondWorth);
						bonusesMap.getElement(player.move.getMatrixPosition() ).isPresent = false;
						bonusesMap.decrementElementNumberCount(bonuses::BonusDiamond);
						break;
					case bonuses::BonusGoldIngot:
						playerAttributes.addToScore(map::GoldIngotWorth);
						bonusesMap.getElement(player.move.getMatrixPosition() ).isPresent = false;
 						bonusesMap.decrementElementNumberCount(bonuses::BonusGoldIngot);
						break;
				}
			}
		}
	//}
}

void updateBonusesAnimation(BonusesMap& bonusesMap, CommonTexturesSprites& sprites)
{
	for( auto &bonus : bonusesMap )
	{
		if( bonus.isPresent )
		{
			switch( bonus.bonusIndex )
			{
				case bonuses::BonusDiamond:
					animSingleBonus(bonus, sprites.diamondsSprites.size(), std::chrono::milliseconds{ textures::DiamondFrameDuration } );
					break;
				case bonuses::BonusGoldIngot:
					animSingleBonus(bonus, sprites.goldIngotSprites.size(), std::chrono::milliseconds{ textures::GoldIngotFrameDuration } );
					break;
			}
		}
	}
}

void animSingleBonus(BonusElement& bonusElement, std::size_t bonusFramesNumber, const std::chrono::milliseconds& delay)
{
	if( bonusElement.animDelay.hasTimeElapsed(delay) )
	{
		bonusElement.animDelay.joinTimePoints();
		if( bonusElement.bonusProperty + 1 < bonusFramesNumber )
		{
			bonusElement.bonusProperty++;
		}
		else{
			bonusElement.bonusProperty = 0;
		}
	}
}