#ifndef BOB_THE_BLOB_IN_GAME_DRAWING_CAN_BE_DONE_H
#define BOB_THE_BLOB_IN_GAME_DRAWING_CAN_BE_DONE_H

#include "customTypes/positionTypes.h"
#include "matrices/matrixStructs.h"

struct ScreenScrolling;
class AxisScrolling;

int getMatrixSquarePosition(int axisCornerPixelPosition, int widthSquare);

Offset getElementPosition(const ScreenScrolling& screenScrolling, const Offset& playerPosition);

int getOnAxisElementPosition(const AxisScrolling& axisScrolling, int axisPosition);

Coord2D getSpecificMatrixElement(const ScreenScrolling& screenScrolling, int width, int height);

int getWidthMatrixElement(const ScreenScrolling& screenScrolling, int width);

int getHeightMatrixElement(const ScreenScrolling& screenScrolling, int height);

#endif //BOB_THE_BLOB_IN_GAME_DRAWING_CAN_BE_DONE_H