#include "levels/textures/balloons/drawBalloons.h"
#include "levels/textures/balloons/balloonsSprites.h"
#include "levels/balloons/balloonsPositionsData.h"
#include "texturing/rendererWindow.h"
#include "consts/includeOptions.h"
#include "levels/textures/balloonsConsts.h"
#include <cassert>

void drawBalloonsIfAny(sdl2::RendererWindow& rndWnd, BalloonsSprites& balloonsSprites, const BalloonsPositions& balloonsPositions)
{
	for( std::size_t orientationEnum{0} ; orientationEnum < balloonsPositions.getScreenEnumMax() ; ++orientationEnum )
	{
		for( std::size_t i{0} ; i < balloonsPositions.getPerZoneNumber() ; ++i )
		{
			if( balloonsPositions.getElement(orientationEnum, i).isOccupied )
			{
				drawBalloonWhiteSprite(rndWnd, balloonsSprites.balloonsSprites, balloonsPositions.getElement(orientationEnum, i), orientationEnum );
				drawBalloonContent(rndWnd, balloonsSprites, balloonsPositions.getElement(orientationEnum, i) );
			}
		}
	}
}

void drawBalloonWhiteSprite(sdl2::RendererWindow& rndWnd, ConstAnimDraw& balloons, const BalloonInfos& balloonInfos, std::size_t balloonOrientation)
{
	balloons[balloonOrientation].draw(rndWnd, balloonInfos.accuratePosition);
}

void drawBalloonContent(sdl2::RendererWindow& rndWnd, BalloonsSprites& balloonsSprites, const BalloonInfos& balloonInfos)
{
	switch( balloonInfos.contentType )
	{
		case BalContentIsEnemy:
			drawEnemyLogoIfAny(rndWnd, balloonsSprites.enemyLogos, balloonInfos);
			break;
		case BalContentIsApple:
		
			break;
		case BalContentIsOrb:
			drawOrbLogoIfAny(rndWnd, balloonsSprites.orbsLogos, balloonInfos);
			break;
	}
}

void drawEnemyLogoIfAny(sdl2::RendererWindow& rndWnd, ConstAnimDraw& enemyLogo, const BalloonInfos& balloonInfos)
{
	assert( balloonInfos.typeSubValue < enemyLogo.size() );
	enemyLogo[balloonInfos.typeSubValue].drawToCenter(rndWnd, balloonInfos.accuratePosition.x + SQR_SIZE / 2, balloonInfos.accuratePosition.y + SQR_SIZE / 2);
}

void drawOrbLogoIfAny(sdl2::RendererWindow& rndWnd, ConstAnimDraw& orbsLogo, const BalloonInfos& balloonInfos)
{
	assert( balloonInfos.typeSubValue < orbsLogo.size() );
	orbsLogo[balloonInfos.typeSubValue].drawToCenter(rndWnd, balloonInfos.accuratePosition.x + SQR_SIZE / 2, balloonInfos.accuratePosition.y + SQR_SIZE / 2);
}