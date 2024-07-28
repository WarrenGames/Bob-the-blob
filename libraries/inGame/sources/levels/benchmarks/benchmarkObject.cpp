#include "levels/benchmarks/benchmarkObject.h"
#include "pathsFunctions/pathsFunctions.h"
#include "prefPath/prefPathFinder.h"
#include "logging/logsStruct.h"
#include "consts/filesAndPaths.h"
#include "fileSystem/fileSystem.h"
#include <algorithm>
#include <cassert>
#include <iomanip>

Benchmark::Benchmark(AppLogFiles& logs, const PrefPathFinder& prefPath, const fs::path& levelName, unsigned benchType):
	benchmarkType{benchType},
	isBenchmarkActive{false},
	benchmarkLevelName{levelName }
{
	if( std::ifstream benchmarkConfigFile{ path::getBenchmarksFilePath(prefPath, files::BenchmarksStatusFile) } )
	{
		if( benchmarkConfigFile >> isBenchmarkActive )
		{
			logs.warning.wrSimpleMessage("The benchmark option is '" + std::to_string(isBenchmarkActive) + "' \n");
		}
		else{
			logs.error.wrSimpleMessage("Error: couldn't read benchmark status option in succesfully open file '" + 
				path::getBenchmarksFilePath(prefPath, files::BenchmarksStatusFile).string() + "' .\n");
		}
	}
	else{
		logs.warning.wrSimpleMessage("Warning: couldn't open '" + path::getBenchmarksFilePath(prefPath, files::BenchmarksStatusFile).string() 
			+ "' file. The benchmark mode is off for the following level: " + levelName.string() + " .\n");
		
	}
}

Benchmark::Benchmark():
	isBenchmarkActive{false},
	data{}
{
	
}

void Benchmark::setStartingPoint()
{
	if( isBenchmarkActive )
	{
		timePoint.joinTimePoints();
	}
}

void Benchmark::setFinalPoint()
{
	if( isBenchmarkActive )
	{
		data.hasMesuredSomething = true;
		std::chrono::duration<double, std::milli> delay{ timePoint.getCurrentElapsedMillisecondsTime() };
		data.totalTime += delay.count();
		changeBestMinValue(delay);
		changeBestMaxValue(delay);
		data.incrementMeasuresNumber();
	}
}

void Benchmark::changeBestMinValue(const std::chrono::duration<double, std::milli>& delay)
{
	if( delay < data.shortestOfAll )
	{
		data.shortestOfAll = delay;
	}
}

void Benchmark::changeBestMaxValue(const std::chrono::duration<double, std::milli>& delay)
{
	if( delay > data.longestOfAll )
	{
		data.longestOfAll = delay;
	}
}

void Benchmark::outputSumToFile(AppLogFiles& logs, const PrefPathFinder& prefPath) const
{
	if( data.hasMesuredSomething && prefPath.isAValidPathFound() )
	{
		fs::path outputPath{ path::getBenchmarksFilePath(prefPath, fs::path{benchmarkLevelName.filename().string() + getBenchAccordingToType() + ".txt"} ) };
		
		if( std::ofstream outputSumFile{outputPath} )
		{
			outputSumFile << std::fixed << std::setprecision(6);
			outputGlobalDataToFile(outputSumFile);
		}
		else{
			logs.error.wrPrefixAndSimpleMessage("couldn't write benchmark output file: " + outputPath.string() + " .\n");
		}
	}
}

void Benchmark::outputGlobalDataToFile(std::ofstream& sumFile) const
{
	sumFile << "This is a " << getBenchAccordingToType() << " sum file.\n"
			<< "  minimum delay measured in milliseconds is " << data.shortestOfAll.count() << "\n"
			<< "  maximum delay measured in milliseconds is " << data.longestOfAll.count() << "\n"
			<< "  average value in milliseconds is " << static_cast<double>(data.getStandardMilliSecondsAverage() ) << "\n"
			<< "  End of sum file.\n";
}

std::string Benchmark::getBenchAccordingToType() const
{
	switch( benchmarkType )
	{
		case BenchGpuDrawing:
			return "_GPU_bench_";
			break;
		case BenchCpu:
			return "_CPU_bench_";
			break;
		default:
			assert( false && "error: bad 'benchmarkType' value !" );
			return "_BenchError_";
			break;
	}
}

Benchs::Benchs(AppLogFiles& logs, const PrefPathFinder& prefPath, const fs::path& levelName):
	gpuBench{logs, prefPath, levelName, BenchGpuDrawing},
	cpuBench{logs, prefPath, levelName, BenchCpu}
{
	
}
