#include "levels/balloons/updateBalloons.h"
#include "levels/global/levelMandatoryData.h"
#include "levels/gameActors/bobThings/bobsPackage.h"
#include "levels/gameActors/magicOrbs/orbsPackage.h"
#include "levels/textures/drawing/screenScrolling.h"
#include "levels/textures/drawing/inferDrawingPosition.h"
#include "customTypes/positionTypes.h"
#include "levels/textures/balloonsConsts.h"
#include "consts/includeOptions.h"
#include "consts/screenConsts.h"

constexpr int InfosBoardHeight = SQR_SIZE;

void updateBalloons(LevelMandatoryData& levelMandatoryData)
{
	levelMandatoryData.balloonsPositions.resetAllBalloons();
	updateBalloonsWithEnemyBobs(levelMandatoryData.balloonsPositions, levelMandatoryData.bobsPackage, levelMandatoryData.screenScrolling);
}

void updateMexicanBalloons(LevelMandatoryData& levelMandatoryData, const OrbsPackage& orbsPackage)
{
	levelMandatoryData.balloonsPositions.resetAllBalloons();
	updateBallonsWithOrbs(levelMandatoryData.balloonsPositions, orbsPackage, levelMandatoryData.screenScrolling);
	updateBalloonsWithEnemyBobs(levelMandatoryData.balloonsPositions, levelMandatoryData.bobsPackage, levelMandatoryData.screenScrolling);
}

void updateBallonsWithOrbs(BalloonsPositions& balloonsPositions, const OrbsPackage& orbsPackage, const ScreenScrolling& screenScrolling)
{
	for( auto const &orb : orbsPackage )
	{
		if( orb.isPresent )
		{
			balloonsPositions.activateNewBalloonIfPossible( getPositionEnumForBalloons( orb.getRealPosition(), screenScrolling ), BalContentIsOrb, 
														static_cast<unsigned>(orb.orbTextureIndex) );
		}
	}
}

void updateBalloonsWithEnemyBobs(BalloonsPositions& balloonsPositions, const BobsPackage& bobsPackage, const ScreenScrolling& screenScrolling)
{
	for( auto const &bob : bobsPackage )
	{
		if( bob )
		{
			if( bob->isActive )
			{
				balloonsPositions.activateNewBalloonIfPossible( getPositionEnumForBalloons(bob->bobTheBlob.getRealPosition(), screenScrolling), BalContentIsEnemy, 
															static_cast<unsigned>(bob->colorIndex ) );
			}
		}
	}
}

std::size_t getPositionEnumForBalloons(const Offset& position, const ScreenScrolling& screenScrolling)
{
	Offset screenRelativePosition{ getElementPosition(screenScrolling, position) };
	
	if( screenRelativePosition.x + SQR_SIZE / 2 < 0 )
	{
		if( screenRelativePosition.y + SQR_SIZE / 2 < 0 )
		{
			return BalloonsNorthWest;
		}
		else if( screenRelativePosition.y - SQR_SIZE / 2 > GameScreenHeight - InfosBoardHeight )
		{
			return BalloonsSouthWest;
		}
		else{
			return BalloonsWest;
		}
	}
	else if( screenRelativePosition.x - SQR_SIZE / 2 > GameScreenWidth )
	{
		if( screenRelativePosition.y + SQR_SIZE / 2 < 0 )
		{
			return BalloonsNorthEast;
		}
		else if( screenRelativePosition.y - SQR_SIZE / 2 > GameScreenHeight - InfosBoardHeight )
		{
			return BalloonsSouthEast;
		}
		else{
			return BalloonsEast;
		}
	}
	else{
		if( screenRelativePosition.y + SQR_SIZE / 2 < 0 )
		{
			return BalloonsNorth;
		}
		else if( screenRelativePosition.y - SQR_SIZE / 2 > GameScreenHeight - InfosBoardHeight )
		{
			return BalloonsSouth;
		}
		else{
			return BalloonsMax;
		}
	}
}