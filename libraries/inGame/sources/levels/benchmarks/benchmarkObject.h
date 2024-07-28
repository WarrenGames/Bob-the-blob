#ifndef IN_GAME_BENCHMARK_DATA_H
#define IN_GAME_BENCHMARK_DATA_H

#include "levels/benchmarks/benchTypes.h"
#include "time/accurateTime.h"
#include "fileSystem/fileSystem.h"
#include <string>

struct AppLogFiles;
class PrefPathFinder;

enum{	BenchGpuDrawing, 
		BenchCpu, 
		BenchMax
};

class Benchmark
{
private:
	unsigned benchmarkType;
	bool isBenchmarkActive;
	AccurateTimeDelay timePoint;
	TimeData data;
	fs::path benchmarkLevelName;

public:
	explicit Benchmark(AppLogFiles& logs, const PrefPathFinder& prefPath, const fs::path& levelName, unsigned benchType);
	explicit Benchmark();
	~Benchmark() = default;
	Benchmark( const Benchmark& ) = delete;
	Benchmark& operator= ( const Benchmark& ) = delete;
	Benchmark( Benchmark&& ) = default;
	Benchmark& operator= ( Benchmark&& ) = default;
		
	void setStartingPoint();
	void setFinalPoint();
	void changeBestMinValue(const std::chrono::duration<double, std::milli>& delay);
	void changeBestMaxValue(const std::chrono::duration<double, std::milli>& delay);

	void outputSumToFile(AppLogFiles& logs, const PrefPathFinder& prefPath) const;
	void outputGlobalDataToFile(std::ofstream& sumFile) const;

	std::string getBenchAccordingToType() const;
	void trunkBenchmarkLevelName(const std::string& levelName);
};

struct Benchs
{
	Benchmark gpuBench;
	Benchmark cpuBench;
	
	explicit Benchs(AppLogFiles& logs, const PrefPathFinder& prefPath, const fs::path& levelName);
	explicit Benchs() = default;
	Benchs( const Benchs& ) = delete;
	Benchs& operator= ( const Benchs& ) = delete;
	Benchs( Benchs&& ) = default;
	Benchs& operator= ( Benchs&& ) = default;
};

#endif //IN_GAME_BENCHMARK_DATA_H