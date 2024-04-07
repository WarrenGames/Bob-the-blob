#ifndef BOB_THE_BLOB_IN_GAME_AXIS_SCROLLING_H
#define BOB_THE_BLOB_IN_GAME_AXIS_SCROLLING_H

#include "matrices/matrixStructs.h"

class AxisScrolling
{
private:
	int offset;
	int screenViewAxisLength;//the size of the view port
	std::size_t matrixMax;
	
public:
	explicit AxisScrolling(std::size_t matrixAxisMax, int axisScreenLength);
	~AxisScrolling() = default;
	AxisScrolling( const AxisScrolling& ) = delete;
	AxisScrolling& operator= ( const AxisScrolling& ) = delete;
	AxisScrolling( AxisScrolling&& ) = default;
	AxisScrolling& operator= ( AxisScrolling&& ) = default;
	
	int getOffset() const;
	void setOffset(int playerAxisPosition);
	void resetCoordsIfNeeded();
	bool isMapSmallerThanViewPort() const;
	void setOffsetForSmallMaps();
	
private:
	void resetCoordsIfNearStart();
	void resetCoordsIfNearEnd();
};

#endif //BOB_THE_BLOB_IN_GAME_AXIS_SCROLLING_H