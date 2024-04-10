#include "levels/textures/drawing/drawElements.h"
#include "levels/textures/drawing/inferDrawingPosition.h"
#include "levels/textures/drawing/axisScrolling.h"
#include "levels/maps/bonusesMap.h"
#include "levels/gameActors/playerThings/singlePlayerData.h"
#include "levels/gameActors/bobThings/bobsPackage.h"
#include "levels/gameActors/cactus/cactiPackage.h"
#include "levels/gameActors/magicOrbs/orbsPackage.h"
#include "levels/textures/infosPanel/infoGradient.h"
#include "levels/textures/drawing/screenScrolling.h"
#include "levels/textures/texturesConsts.h"
#include "levels/maps/bonusesConsts.h"
#include "advancedDrawing/texturesDrawing/2dimTexturesDrawing.h"
#include "advancedDrawing/texturesDrawing/constAnimationDrawing.h"
#include "consts/includeOptions.h"
#include <cassert>

void drawPlayerMoving(sdl2::RendererWindow& rndWnd, ConstAnimDraw& playerSprites, const SinglePlayerData& player, const ScreenScrolling& screenScrolling)
{
	playerSprites.drawToCenter(rndWnd, getElementPosition(screenScrolling, player.move.getRealPosition() ), player.anim.getCurrentFrame());
}

void drawBobs(sdl2::RendererWindow& rndWnd, Matrix2DTexturesDrawing& blobSprites, const BobsPackage& bobsPackage, const Ability& ability, const ScreenScrolling& screenScrolling)
{
	for( auto const &bob : bobsPackage )
	{
		if( bob )
		{
			if( bob->isActive )
			{
				if( ability.isAbilityActive() )//Ability here is whether bob is eatable by player
				{
					blobSprites.drawToCenter(rndWnd, Coord2D{bob->frameNumber, textures::BlobColorGreen}, getElementPosition(screenScrolling, bob->bobTheBlob.getRealPosition() ) );
				}
				else{
					blobSprites.drawToCenter(rndWnd, Coord2D{bob->frameNumber, bob->colorIndex }, getElementPosition(screenScrolling, bob->bobTheBlob.getRealPosition() ) );
				}
			}
		}
	}
}

void drawMexicanBobs(sdl2::RendererWindow& rndWnd, Matrix2DTexturesDrawing& blobSprites, sdl2::Sprite& bobHat, const BobsPackage& bobsPackage, const Ability& ability, 
						const ScreenScrolling& screenScrolling)
{
	for( auto const &bob : bobsPackage )
	{
		if( bob )
		{
			if( bob->isActive )
			{
				if( ability.isAbilityActive() )
				{
					blobSprites.drawToCenter(rndWnd, Coord2D{bob->frameNumber, textures::BlobColorGreen}, getElementPosition(screenScrolling, bob->bobTheBlob.getRealPosition() ) );
				}
				else{
					blobSprites.drawToCenter(rndWnd, Coord2D{bob->frameNumber, bob->colorIndex}, getElementPosition(screenScrolling, bob->bobTheBlob.getRealPosition() ) );
				}
				bobHat.drawToCenter(rndWnd, getOnAxisElementPosition(screenScrolling.xAxisScrolling, bob->bobTheBlob.getRealPosition().x - SQR_SIZE / 8),
										getOnAxisElementPosition(screenScrolling.yAxisScrolling, bob->bobTheBlob.getRealPosition().y - SQR_SIZE / 2) );
			}
		}
	}
}

void drawBobsLightBulbs(sdl2::RendererWindow& rndWnd, ConstAnimDraw& lightBulbSprite, const BobsPackage& bobsPackage, const ScreenScrolling& screenScrolling)
{
	for( auto const &bob : bobsPackage )
	{
		if( bob )
		{
			if( bob->isActive && bob->canSeekPlayer )
			{
				lightBulbSprite.drawToCenter(rndWnd, getOnAxisElementPosition( screenScrolling.xAxisScrolling, bob->bobTheBlob.getRealPosition().x ),
													getOnAxisElementPosition( screenScrolling.yAxisScrolling, bob->bobTheBlob.getRealPosition().y - SQR_SIZE * 3 / 4 ),
													bob->lightBulbFrameNumber );
			}
		}
	}
}

void drawCacti(sdl2::RendererWindow& rndWnd, ConstAnimDraw& cactusSprites, const CactiPackage& cactiPackage, const ScreenScrolling& screenScrolling)
{
	for( auto const &cactus : cactiPackage )
	{
		assert( cactus.cactusTexture < cactusSprites.size() );
		
		if( cactus.isEffective )
		{
			cactusSprites.draw(rndWnd, getElementPosition(screenScrolling, cactus.getRealPosition() ), cactus.cactusTexture);
		}
	}
}

void drawOrbs(sdl2::RendererWindow& rndWnd, ConstAnimDraw& magicOrbSprites, const OrbsPackage& orbsPackage, const ScreenScrolling& screenScrolling)
{
	for( auto const &orb : orbsPackage )
	{
		assert( orb.orbTextureIndex < bonuses::OrbMax );
		if( orb.isPresent )
		{
			magicOrbSprites.draw(rndWnd, getElementPosition(screenScrolling, orb.getRealPosition() ), orb.orbTextureIndex );
		}
	}
}

void drawRosterGradient(sdl2::RendererWindow& rndWnd, const sdl2::Sprite& spriteIcon, const InfoGradient& gradient, const Ability& ability)
{
	if( ability.isAbilityActive() )
	{
		gradient.draw(rndWnd, ability);
		spriteIcon.draw(rndWnd);
	}
}

void drawBlueSmokeExplosion(sdl2::RendererWindow& rndWnd, ConstAnimDraw& blueSmokeExplosion, const BobsPackage& bobsPackage, const ScreenScrolling& screenScrolling)
{
	for( auto const &bob : bobsPackage )
	{
		if( bob->blueSpawnExplosion.isExplosionActive() )
		{
			blueSmokeExplosion.drawToCenter(rndWnd, 
				getOnAxisElementPosition(screenScrolling.xAxisScrolling, static_cast<int>(bob->bobTheBlob.getStartingPosition().width) * SQR_SIZE + SQR_SIZE / 2),
				getOnAxisElementPosition(screenScrolling.yAxisScrolling, static_cast<int>(bob->bobTheBlob.getStartingPosition().height) * SQR_SIZE + SQR_SIZE / 2), 
				bob->blueSpawnExplosion.getCurrentFrame() );
		}
	}
}