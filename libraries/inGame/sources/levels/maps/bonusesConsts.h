#ifndef BOB_THE_BLOB_IN_GAME_MAPS_BONUSES_CONSTS_H
#define BOB_THE_BLOB_IN_GAME_MAPS_BONUSES_CONSTS_H

namespace bonuses{
	enum : std::size_t {
		BonusGlassMarble,		// = 0
		BonusApple,				// = 1
		BonusDiamond,			// = 2
		BonusGoldIngot,			// = 3
		//BonusCactusToAvoid,
		//BonusOrb,
		BonusMax
	};
	
	enum : std::size_t {
		AppleRed,
		AppleGreen,
		AppleYellow,
		AppleBlue,
		AppleMax
	};
	
	enum : std::size_t {
		OrbGreen,
		OrbRed,
		OrbBlue,
		OrbMax
	};
}

#endif //BOB_THE_BLOB_IN_GAME_MAPS_BONUSES_CONSTS_H