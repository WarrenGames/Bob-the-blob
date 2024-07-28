#include "levels/benchmarks/benchTypes.h"
#include <limits>
#include <numeric>

TimeData::TimeData():
	totalTime{0},
	measuresNumber{0},
	shortestOfAll{std::numeric_limits<double>::max()},
	longestOfAll{0},
	hasMesuredSomething{false}
{

}

long double TimeData::getStandardMilliSecondsAverage() const
{
	if( measuresNumber == 0 )
	{
		return 0;
	}
	else
	{
		return totalTime / measuresNumber;
	}
}

void TimeData::incrementMeasuresNumber()
{
	measuresNumber++;
}