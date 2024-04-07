#ifndef BOB_THE_BLOB_IN_GAME_MEXICAN_TEXTURES_CONSTS_H
#define BOB_THE_BLOB_IN_GAME_MEXICAN_TEXTURES_CONSTS_H

#include <cstdlib>

namespace textures{
	namespace mexican{
		enum : std::size_t{ 
			EmptySquare,
			ClayWall 
		};
		
		constexpr char BobMexicanTexturesListFile[] = "data/textures/protagonists/bobTheMexicanTextures.txt";
		
		enum : std::size_t {
			CactusYellow,
			CactusTall,
			CactusGray,
			CactusMax
		};

		constexpr char MexicanMapTexturesListFile[] = "data/textures/mapping/mexicanBackgrounds.txt";

		constexpr char CactiTexturesFilePath[] = "data/textures/objects/cactusTextures.txt";
		
		constexpr char SandDunesTexturePath[] = "textures/sprites/mexican/sandDunes.png";

		constexpr char BobHatTexturePath[] = "textures/sprites/bob/bobHat.png";
	}
}

#endif //BOB_THE_BLOB_IN_GAME_MEXICAN_TEXTURES_CONSTS_H