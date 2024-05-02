#ifndef BOB_THE_BLOB_IN_GAME_INTERFACE_GRADIENTS_THINGS_H
#define BOB_THE_BLOB_IN_GAME_INTERFACE_GRADIENTS_THINGS_H

#include "consts/screenConsts.h"
#include "SDL_rect.h"
#include "SDL_pixels.h"

constexpr int GradientBorder = SQR_SIZE / 16;

constexpr SDL_Rect LeftGradient = { SQR_SIZE + SQR_SIZE / 4, GameScreenHeight - SQR_SIZE * 3 / 4, SQR_SIZE * 2 - SQR_SIZE / 2, SQR_SIZE / 2 };

constexpr SDL_Rect LeftGradientBackground = { LeftGradient.x - GradientBorder, LeftGradient.y - GradientBorder, LeftGradient.w + GradientBorder * 2, LeftGradient.h + GradientBorder * 2 };

constexpr SDL_Rect RightGradient = { LeftGradient.x + LeftGradient.w + SQR_SIZE, LeftGradient.y, LeftGradient.w, LeftGradient.h };

constexpr SDL_Rect RightGradientBackground = { RightGradient.x - GradientBorder, RightGradient.y - GradientBorder, RightGradient.w + GradientBorder * 2, RightGradient.h + GradientBorder * 2 };

constexpr SDL_Color DarkGreen = { 0, 64, 0, 255 };

constexpr SDL_Color BrightGreen = { 0, 255, 0, 255 };

constexpr SDL_Color DarkYellow = { 64, 64, 0, 255 };

constexpr SDL_Color BrightYellow = { 255, 255, 0, 255 };

constexpr SDL_Color Black = { 0, 0, 0, 255 };

#endif //BOB_THE_BLOB_IN_GAME_INTERFACE_GRADIENTS_THINGS_H