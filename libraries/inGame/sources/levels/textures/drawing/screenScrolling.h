#ifndef BOB_THE_BLOB_IN_GAME_SCREEN_SCROLLING_H
#define BOB_THE_BLOB_IN_GAME_SCREEN_SCROLLING_H

#include "levels/textures/drawing/axisScrolling.h"

struct Offset;

struct ScreenScrolling
{
	AxisScrolling xAxisScrolling;
	AxisScrolling yAxisScrolling;
	
	explicit ScreenScrolling(const Coord2D& matrixSize, int xScreenView, int yScreenView);
	~ScreenScrolling() = default;
	ScreenScrolling( const ScreenScrolling& ) = delete;
	ScreenScrolling& operator= ( const ScreenScrolling& ) = delete;
	ScreenScrolling( ScreenScrolling&& ) = default;
	ScreenScrolling& operator= ( ScreenScrolling&& ) = default;
	
	void setScrollingOffset(const Offset& screenCenterPosition);//Center position is player position
	void setAxisScrollingOffset(AxisScrolling& axisScrolling, int playerAxisPos);
};

#endif //BOB_THE_BLOB_IN_GAME_SCREEN_SCROLLING_H