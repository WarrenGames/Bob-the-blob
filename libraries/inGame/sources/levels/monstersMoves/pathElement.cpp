#include "levels/monstersMoves/pathElement.h"
#include "levels/monstersMoves/monstersMovesConsts.h"
#include <cassert>

PathElement::PathElement():
	startDirection{ RoadMax },
	canBeAnalysed{ true }
{

}

IdealPathChunk::IdealPathChunk():
	coords{ 0, 0 },
	effectiveDirection{ RoadMax },
	isRelevant{false}
{
	
}

void IdealPathChunk::setFlagOff()
{
	effectiveDirection = RoadMax;
	isRelevant = false;
}

void IdealPathChunk::setEffectiveDirection(unsigned roadDirectionEnumValue)
{
	assert( roadDirectionEnumValue < RoadMax );
	effectiveDirection = roadDirectionEnumValue;
}