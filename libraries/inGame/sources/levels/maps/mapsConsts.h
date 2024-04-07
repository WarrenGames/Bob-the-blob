#ifndef BOB_THE_BLOB_IN_GAME_MAPS_CONSTS_H
#define BOB_THE_BLOB_IN_GAME_MAPS_CONSTS_H

#include <cstdlib>

namespace map{
	constexpr std::size_t ClassicMapWidth = 20;
	
	constexpr std::size_t ClassicMapHeight = 15;
	
	constexpr int MatrixSizeIndex = -1;
	
	constexpr int GlassMarbleWorth = 10;
	constexpr int AppleWorth = 40;
	constexpr int GreenOrbWorth = 80;
	constexpr int DiamondWorth = 100;
	constexpr int GoldIngotWorth = 40;
	constexpr int BobEatingWorth = 400;
	constexpr int CactusEatingWorth = 800;
	
	enum{
		BlueBrickLevel,
		MexicanLevel,
		MaxLevel
	};
}

#endif //BOB_THE_BLOB_IN_GAME_MAPS_CONSTS_H