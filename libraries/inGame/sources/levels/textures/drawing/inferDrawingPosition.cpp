#include "levels/textures/drawing/inferDrawingPosition.h"
#include "levels/maps/gameMap.h"
#include "levels/textures/drawing/screenScrolling.h"
#include "levels/maps/mapsConsts.h"
#include "consts/includeOptions.h"

int getMatrixSquarePosition(int axisCornerPixelPosition, int widthSquare)
{
	return -axisCornerPixelPosition % SQR_SIZE + widthSquare * SQR_SIZE;
}

Offset getElementPosition(const ScreenScrolling& screenScrolling, const Offset& playerPosition)
{
	return Offset{ playerPosition.x - screenScrolling.xAxisScrolling.getOffset(), playerPosition.y - screenScrolling.yAxisScrolling.getOffset() };
}

int getOnAxisElementPosition(const AxisScrolling& axisScrolling, int axisPosition)
{
	return axisPosition - axisScrolling.getOffset();
}

Coord2D getSpecificMatrixElement(const ScreenScrolling& screenScrolling, int width, int height)
{
	return Coord2D{
		static_cast<std::size_t>( screenScrolling.xAxisScrolling.getOffset() / SQR_SIZE + width ), 
		static_cast<std::size_t>( screenScrolling.yAxisScrolling.getOffset() / SQR_SIZE + height )
	};
}

int getWidthMatrixElement(const ScreenScrolling& screenScrolling, int width)
{
	return screenScrolling.xAxisScrolling.getOffset() / SQR_SIZE + width;
}

int getHeightMatrixElement(const ScreenScrolling& screenScrolling, int height)
{
	return screenScrolling.yAxisScrolling.getOffset() / SQR_SIZE + height;
}
