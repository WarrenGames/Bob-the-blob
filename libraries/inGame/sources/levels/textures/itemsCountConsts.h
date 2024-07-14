#ifndef BOB_THE_BLOB_IN_GAME_ITEMS_COUNT_CONSTS_H
#define BOB_THE_BLOB_IN_GAME_ITEMS_COUNT_CONSTS_H

#include "consts/screenConsts.h"
#include "SDL_rect.h"

constexpr SDL_Rect GoldIngotsCountRect = { GameScreenWidth / 2 + SQR_SIZE * 2, GameScreenHeight - SQR_SIZE * 3 / 4, SQR_SIZE * 2 - SQR_SIZE / 2, SQR_SIZE / 2 };

constexpr char GoldIngotIcon[] = "textures/interface/goldIngotIcon.png";

constexpr SDL_Rect CactusCountRect = { GameScreenWidth / 2 + SQR_SIZE * 5, GameScreenHeight - SQR_SIZE * 3 / 4, SQR_SIZE * 2 - SQR_SIZE / 2, SQR_SIZE / 2 };

constexpr char CactusIcon[] = "textures/interface/cactusIcon.png";

#endif //BOB_THE_BLOB_IN_GAME_ITEMS_COUNT_CONSTS_H