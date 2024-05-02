#include "levels/balloons/balloonInfo.h"
#include "levels/textures/balloonsConsts.h"
#include "consts/screenConsts.h"

BalloonInfos::BalloonInfos():
	screenSquarePosition{ WidthSquaresNumber, HeightSquaresNumber },
	accuratePosition{ GameScreenWidth, GameScreenHeight },
	contentType{ BalContentIsMax },
	typeSubValue{ 0 },
	isOccupied{ false }
{
	
}

BalloonInfos::BalloonInfos(const Coord2D& readCoordinates):
	screenSquarePosition{ readCoordinates },
	accuratePosition{ static_cast<int>(readCoordinates.width) * SQR_SIZE, static_cast<int>(readCoordinates.height) * SQR_SIZE },
	contentType{ BalContentIsMax },
	typeSubValue{ 0 },
	isOccupied{ false }
{
	
}