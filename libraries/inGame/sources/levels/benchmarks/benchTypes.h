#ifndef BENCHS_TYPES_H
#define BENCHS_TYPES_H

#include <chrono>
#include <vector>

struct TimeData
{
	long double totalTime;
	long long unsigned measuresNumber;
	std::chrono::duration<double, std::milli> shortestOfAll;
	std::chrono::duration<double, std::milli> longestOfAll;
	bool hasMesuredSomething;
	
	explicit TimeData();
	~TimeData() = default;
	TimeData( const TimeData& ) = delete;
	TimeData& operator= ( const TimeData& ) = delete;
	TimeData( TimeData&& ) = default;
	TimeData& operator= ( TimeData&& ) = default;
	long double getStandardMilliSecondsAverage() const;
	void incrementMeasuresNumber();
};

#endif //BENCHS_TYPES_H