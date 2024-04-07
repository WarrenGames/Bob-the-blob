#ifndef BOB_THE_BLOB_IN_GAME_DRAW_MAP_ELEMENTS_H
#define BOB_THE_BLOB_IN_GAME_DRAW_MAP_ELEMENTS_H

namespace sdl2{ class RendererWindow; class Sprite; }
class ConstAnimDraw;
class Matrix2DTexturesDrawing;
struct SinglePlayerData;
class BobsPackage;
class CactiPackage;
class OrbsPackage;
class Ability;
class InfoGradient;
struct ScreenScrolling;

void drawPlayerMoving(sdl2::RendererWindow& rndWnd, ConstAnimDraw& playerSprites, const SinglePlayerData& player, const ScreenScrolling& screenScrolling);

void drawBobs(sdl2::RendererWindow& rndWnd, Matrix2DTexturesDrawing& blobSprites, const BobsPackage& bobsPackage, const Ability& ability, const ScreenScrolling& screenScrolling);

void drawMexicanBobs(sdl2::RendererWindow& rndWnd, Matrix2DTexturesDrawing& blobSprites, sdl2::Sprite& bobHat, const BobsPackage& bobsPackage, const Ability& ability, 
						const ScreenScrolling& screenScrolling);

void drawBobsLightBulbs(sdl2::RendererWindow& rndWnd, ConstAnimDraw& lightBulbSprite, const BobsPackage& bobsPackage, const ScreenScrolling& screenScrolling); 

void drawCacti(sdl2::RendererWindow& rndWnd, ConstAnimDraw& cactusSprites, const CactiPackage& cactiPackage, const ScreenScrolling& screenScrolling);

void drawOrbs(sdl2::RendererWindow& rndWnd, ConstAnimDraw& magicOrbSprites, const OrbsPackage& orbsPackage, const ScreenScrolling& screenScrolling);

void drawRosterGradient(sdl2::RendererWindow& rndWnd, const sdl2::Sprite& spriteIcon, const InfoGradient& gradient, const Ability& ability);

#endif //BOB_THE_BLOB_IN_GAME_DRAW_MAP_ELEMENTS_H