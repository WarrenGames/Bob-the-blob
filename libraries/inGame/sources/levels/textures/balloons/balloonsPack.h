#ifndef BOB_THE_BLOB_IN_GAME_BALLOONS_PACK_H
#define BOB_THE_BLOB_IN_GAME_BALLOONS_PACK_H

#include "levels/textures/balloons/balloonsTexturesLoader.h"
#include "levels/textures/balloons/balloonsSprites.h"

struct AppLogFiles;
namespace sdl2{ class RendererWindow; }

struct BalloonsPack
{
	const BalloonsTexturesLoader loadedTextures;
	BalloonsSprites sprites;
	
	explicit BalloonsPack(AppLogFiles& logs, sdl2::RendererWindow& rndWnd);
	~BalloonsPack() = default;
	BalloonsPack( const BalloonsPack& ) = delete;
	BalloonsPack& operator= ( const BalloonsPack& ) = delete;
	BalloonsPack( BalloonsPack&& ) = default;
	BalloonsPack& operator= ( BalloonsPack&& ) = default;
};

#endif //BOB_THE_BLOB_IN_GAME_BALLOONS_PACK_H