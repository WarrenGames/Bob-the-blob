#ifndef BOB_THE_BLOB_IN_GAME_TEXTURES_CONSTS_H
#define BOB_THE_BLOB_IN_GAME_TEXTURES_CONSTS_H

#include <cstdlib>

namespace textures{
	constexpr std::size_t BlobFramesNumber = 4;
	constexpr unsigned BobFrameDuration = 100;
	constexpr unsigned LightBulbFrameDuration = 250;
	
	constexpr unsigned DiamondFrameDuration = 120;
	constexpr unsigned GoldIngotFrameDuration = 1000 / 16;
	
	enum : std::size_t {
		BlobColorGreen,
		BlobColorYellow,
		BlobColorBlue,
		BlobColorViolet,
		BlobColorMax
	};
	
	constexpr char BlobTexturesFilePath[] = "data/textures/protagonists/bobTheBlobTextures.txt";
	
	constexpr std::size_t PlayerFramesNumber = 10;
	constexpr unsigned PlayerFrameDuration = 80;
	
	enum : std::size_t {
		PlayerDirectionEast,
		PlayerDirectionNorth,
		PlayerDirectionWest,
		PlayerDirectionSouth,
		PlayerDirectionMax
	};
	
	enum : std::size_t {
		SquareEmpty,
		SquareBrick,
		SquareMax
	};
	
	enum : std::size_t {
		WallBlue,
		WallMax
	};
	
	enum : std::size_t {
		LightBulbPutOut,
		LightBulbHit,
		LightBulbMax
	};
	
	constexpr char PlayerTexturesFilePath[] = "data/textures/protagonists/bobPlayer.txt";
	
	constexpr char WallsTexturesFilePath[] = "data/textures/mapping/stdBackgrounds.txt";
	
	constexpr char ApplesTexturesFilePath[] = "data/textures/objects/applesTextures.txt";
	
	constexpr char GlassMarbleTexturePath[] = "textures/sprites/items/glassMarble.png";
	
	constexpr char LightBulbTexturesFilePath[] = "data/textures/objects/lightBulbAnim.txt";
	
	constexpr char StdLevelFloorTexture[] = "textures/sprites/map/floorTexture.png";
	
	constexpr char MagicOrbTexturesFilePath[] = "data/textures/objects/magicOrbsTextures.txt";
	
	constexpr char DiamondsTexturesFilePath[] = "data/textures/objects/diamondsTextures.txt";
	
	constexpr char GoldIngotTexturesFilePath[] = "data/textures/objects/goldIngot.txt";
}



#endif //BOB_THE_BLOB_IN_GAME_TEXTURES_CONSTS_H