#ifndef BOB_THE_BLOB_IN_GAME_DRAW_MAP_H
#define BOB_THE_BLOB_IN_GAME_DRAW_MAP_H

namespace sdl2{ class RendererWindow; class Sprite; }
class MappingSprites;
struct GameMap;
struct ScreenScrolling;
struct CommonTexturesSprites;
class BonusesMap;
struct BonusElement;

void drawMap(sdl2::RendererWindow& rndWnd, MappingSprites& mappingSprites, const GameMap& gameMap, const ScreenScrolling& screenScrolling);

void drawMapTransparentWallsBackground(sdl2::RendererWindow& rndWnd, MappingSprites& mappingSprites, const GameMap& gameMap, const ScreenScrolling& screenScrolling);

void drawBonuses(sdl2::RendererWindow& rndWnd, CommonTexturesSprites& sprites, const BonusesMap& bonusesMap, const ScreenScrolling& screenScrolling);

void selectBonusToDraw(sdl2::RendererWindow& rndWnd, CommonTexturesSprites& sprites, const BonusElement& bonusElement, int width, int height, const ScreenScrolling& screenScrolling);

#endif //BOB_THE_BLOB_IN_GAME_DRAW_MAP_H