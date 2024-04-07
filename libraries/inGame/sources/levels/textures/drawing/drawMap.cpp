#include "levels/textures/drawing/drawMap.h"
#include "texturing/rendererWindow.h"
#include "levels/textures/mappingTextures/mappingSprites.h"
#include "levels/textures/common/commonSprite.h"
#include "levels/maps/gameMap.h"
#include "levels/maps/bonusesMap.h"
#include "levels/textures/drawing/screenScrolling.h"
#include "levels/gameActors/playerThings/playerMoving.h"
#include "levels/textures/drawing/inferDrawingPosition.h"
#include "levels/maps/mapsConsts.h"
#include "levels/maps/bonusesConsts.h"
#include "consts/includeOptions.h"
#include <cassert>

void drawMap(sdl2::RendererWindow& rndWnd, MappingSprites& mappingSprites, const GameMap& gameMap, const ScreenScrolling& screenScrolling)
{
	for( int height{-1} ; height < static_cast<int>( map::ClassicMapHeight ) + 1 ; ++height )
	{
		for( int width{ -1 } ; width < static_cast<int>( map::ClassicMapWidth ) + 1 ; ++width )
		{
			if( gameMap.matrix.isSignedInsideBoundaries( getWidthMatrixElement(screenScrolling, width), getHeightMatrixElement(screenScrolling, height) ) )
			{
				mappingSprites.drawSprite(rndWnd, 
										getMatrixSquarePosition(screenScrolling.xAxisScrolling.getOffset(), width),
										getMatrixSquarePosition(screenScrolling.yAxisScrolling.getOffset(), height),
										gameMap.matrix( getSpecificMatrixElement(screenScrolling, width, height) ).mapIndex, 
										gameMap.matrix( getSpecificMatrixElement(screenScrolling, width, height) ).indexProperty );
			}
		}
	}
}

void drawMapTransparentWallsBackground(sdl2::RendererWindow& rndWnd, MappingSprites& mappingSprites, const GameMap& gameMap, const ScreenScrolling& screenScrolling)
{
	for( int height{-1} ; height < static_cast<int>( map::ClassicMapHeight ) + 1 ; ++height )
	{
		for( int width{ -1 } ; width < static_cast<int>( map::ClassicMapWidth ) + 1 ; ++width )
		{
			if( gameMap.matrix.isSignedInsideBoundaries( getWidthMatrixElement(screenScrolling, width), getHeightMatrixElement(screenScrolling, height) ) )
			{
				if( gameMap.matrix( getSpecificMatrixElement(screenScrolling, width, height) ).mapIndex > 0 )
				{
					mappingSprites.drawSprite(rndWnd, 
										getMatrixSquarePosition(screenScrolling.xAxisScrolling.getOffset(), width),
										getMatrixSquarePosition(screenScrolling.yAxisScrolling.getOffset(), height),
										0, 
										0 );
				}
			}
		}
	}
}

void drawBonuses(sdl2::RendererWindow& rndWnd, CommonTexturesSprites& sprites, const BonusesMap& bonusesMap, const ScreenScrolling& screenScrolling)
{
	for( int height{-1} ; height < static_cast<int>(map::ClassicMapHeight) + 1 ; ++height )
	{
		for( int width{-1} ; width < static_cast<int>(map::ClassicMapWidth) + 1 ; ++width )
		{
			if( bonusesMap.areCoordinatesInsideBoundaries( getWidthMatrixElement(screenScrolling, width), getHeightMatrixElement(screenScrolling, height) ) )
			{
				selectBonusToDraw(rndWnd, sprites, bonusesMap.getElement( getSpecificMatrixElement(screenScrolling, width, height) ), width, height, screenScrolling );
			}
		}
	}
}

void selectBonusToDraw(sdl2::RendererWindow& rndWnd, CommonTexturesSprites& sprites, const BonusElement& bonusElement, int width, int height, const ScreenScrolling& screenScrolling)
{
	if( bonusElement.isPresent )
	{
		switch( bonusElement.bonusIndex )
		{
			case bonuses::BonusGlassMarble:
				sprites.glassMarbleSprite.draw(rndWnd, getMatrixSquarePosition(screenScrolling.xAxisScrolling.getOffset(), width), 
												getMatrixSquarePosition(screenScrolling.yAxisScrolling.getOffset(), height) );
				break;
			case bonuses::BonusApple:
				sprites.applesSprites[bonusElement.bonusProperty].draw(rndWnd, 
												getMatrixSquarePosition(screenScrolling.xAxisScrolling.getOffset(), width), 
												getMatrixSquarePosition(screenScrolling.yAxisScrolling.getOffset(), height) );
				break;
			case bonuses::BonusDiamond:
				sprites.diamondsSprites[bonusElement.bonusProperty].draw(rndWnd, 
												getMatrixSquarePosition(screenScrolling.xAxisScrolling.getOffset(), width), 
												getMatrixSquarePosition(screenScrolling.yAxisScrolling.getOffset(), height) );
				break;
			case bonuses::BonusGoldIngot:
				sprites.goldIngotSprites[bonusElement.bonusProperty].draw(rndWnd,
												getMatrixSquarePosition(screenScrolling.xAxisScrolling.getOffset(), width), 
												getMatrixSquarePosition(screenScrolling.yAxisScrolling.getOffset(), height) );
				break;
			default:
				assert( false && "Error: bad 'bonusIndex' value." );
				break;
		}
	}
}