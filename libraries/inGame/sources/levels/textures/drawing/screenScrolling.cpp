#include "levels/textures/drawing/screenScrolling.h"
#include "customTypes/positionTypes.h"

ScreenScrolling::ScreenScrolling(const Coord2D& matrixSize, int xScreenView, int yScreenView):
	xAxisScrolling{ matrixSize.width, xScreenView },
	yAxisScrolling{ matrixSize.height, yScreenView }
{
	xAxisScrolling.resetCoordsIfNeeded();
	yAxisScrolling.resetCoordsIfNeeded();
}

void ScreenScrolling::setScrollingOffset(const Offset& screenCenterPosition)//screenCenterPosition is player position
{
	setAxisScrollingOffset(xAxisScrolling, screenCenterPosition.x);
	setAxisScrollingOffset(yAxisScrolling, screenCenterPosition.y);
}

void ScreenScrolling::setAxisScrollingOffset(AxisScrolling& axisScrolling, int playerAxisPos)
{
	if( axisScrolling.isMapSmallerThanViewPort() == false )
	{
		axisScrolling.setOffset(playerAxisPos);
		axisScrolling.resetCoordsIfNeeded();
	}
	else{
		axisScrolling.setOffsetForSmallMaps();
	}
}