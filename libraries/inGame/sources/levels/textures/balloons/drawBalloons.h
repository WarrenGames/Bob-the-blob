#ifndef BOB_THE_BLOB_IN_GAME_DRAW_BALLOONS_H
#define BOB_THE_BLOB_IN_GAME_DRAW_BALLOONS_H

#include <cstdlib>

namespace sdl2{ class RendererWindow; }
struct BalloonsSprites;
class BalloonsPositions;
struct BalloonInfos;
class ConstAnimDraw;

void drawBalloonsIfAny(sdl2::RendererWindow& rndWnd, BalloonsSprites& balloonsSprites, const BalloonsPositions& balloonsPositions);

void drawBalloonWhiteSprite(sdl2::RendererWindow& rndWnd, ConstAnimDraw& balloons, const BalloonInfos& balloonInfos, std::size_t balloonOrientation);

void drawBalloonContent(sdl2::RendererWindow& rndWnd, BalloonsSprites& balloonsSprites, const BalloonInfos& balloonInfos);

void drawEnemyLogoIfAny(sdl2::RendererWindow& rndWnd, ConstAnimDraw& enemyLogo, const BalloonInfos& balloonInfos);

void drawOrbLogoIfAny(sdl2::RendererWindow& rndWnd, ConstAnimDraw& orbsLogo, const BalloonInfos& balloonInfos);

#endif //BOB_THE_BLOB_IN_GAME_DRAW_BALLOONS_H