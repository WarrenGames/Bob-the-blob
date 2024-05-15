#include "levels/global/actWithBonuses.h"
#include "levels/gameActors/playerThings/singlePlayerData.h"
#include "levels/gameActors/bobThings/bobsPackage.h"
#include "levels/gameActors/magicOrbs/orbsPackage.h"
#include "levels/demosRecordingAndPlaying/data/dataPackage.h"
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
}

void createBonusesAnimationData(BonusesMap& bonusesMap, const CommonTexturesSprites& sprites)
{
	bonusesMap.createAnimData(sprites);
}
