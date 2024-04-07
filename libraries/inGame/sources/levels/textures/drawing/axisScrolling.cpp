#include "levels/textures/drawing/axisScrolling.h"
#include "consts/screenConsts.h"
#include "consts/includeOptions.h"

AxisScrolling::AxisScrolling(std::size_t matrixAxisMax, int axisScreenLength):
	offset{0},
	screenViewAxisLength{ axisScreenLength },
	matrixMax{ matrixAxisMax }
{
	
}

int AxisScrolling::getOffset() const
{
	return offset;
}

void AxisScrolling::setOffset(int playerAxisPosition)
{
	offset = playerAxisPosition - screenViewAxisLength / 2;
}

void AxisScrolling::resetCoordsIfNeeded()
{
	if( isMapSmallerThanViewPort() == false )
	{
		resetCoordsIfNearStart();
		resetCoordsIfNearEnd();
	}
}

bool AxisScrolling::isMapSmallerThanViewPort() const
{
	return static_cast<int>(matrixMax) * static_cast<int>(SQR_SIZE) < screenViewAxisLength;
}

void AxisScrolling::resetCoordsIfNearStart()
{
	if( offset < 0 )
	{
		offset = 0;
	}
}

void AxisScrolling::resetCoordsIfNearEnd()
{
	if( offset > static_cast<int>(matrixMax) * SQR_SIZE - screenViewAxisLength )
	{
		offset = static_cast<int>(matrixMax) * SQR_SIZE - screenViewAxisLength;
	}
}

void AxisScrolling::setOffsetForSmallMaps()
{
	if( isMapSmallerThanViewPort() )
	{
		offset = -( screenViewAxisLength / 2 - (static_cast<int>(matrixMax) * SQR_SIZE / 2 ) );
	}
}