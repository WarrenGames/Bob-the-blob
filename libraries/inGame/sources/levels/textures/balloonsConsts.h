#ifndef BOB_THE_BLOB_IN_GAME_TEXTURES_BALLOONS_CONSTS_H
#define BOB_THE_BLOB_IN_GAME_TEXTURES_BALLOONS_CONSTS_H

#include <cstdlib>

constexpr std::size_t PerZoneBalloons = 5;

enum : std::size_t {
	BalloonsEast,			// = 0
	BalloonsNorthEast,
	BalloonsNorth,			// = 2
	BalloonsNorthWest,
	BalloonsWest,			// = 4
	BalloonsSouthWest,
	BalloonsSouth,			// = 6
	BalloonsSouthEast,
	BalloonsMax				// = 8
};

enum : unsigned {
	BalContentIsEnemy,
	BalContentIsApple,
	BalContentIsOrb,
	BalContentIsHammer,
	BalContentIsMax
};

constexpr char BalloonsTexturesListFile[] = "data/textures/objects/balloonsTextures.txt";

constexpr char BalloonsEnemyLogoListFile[] = "data/textures/objects/balloonsEnemyLogo.txt";

constexpr char BalloonsOrbsLogoListFile[] = "data/textures/objects/balloonsOrbsLogo.txt";

constexpr char BalloonsHammerLogoFile[] = "textures/sprites/balloons/hammerLogo.png";

constexpr char BalloonsPositionsFile[] = "data/textures/balloons/balloonsPositions.txt";

#endif //BOB_THE_BLOB_IN_GAME_TEXTURES_BALLOONS_CONSTS_H