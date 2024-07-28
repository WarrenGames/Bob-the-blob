#include "levels/benchmarks/outputBenchmarkData.h"
#include "levels/benchmarks/benchmarkObject.h"
#include "prefPath/prefPathFinder.h"
#include "logging/logsStruct.h"

void outputBenchmarkDataToFiles(AppLogFiles& logs, const PrefPathFinder& prefPath, const Benchs& benchmarks)
{
	benchmarks.cpuBench.outputSumToFile(logs, prefPath);
	benchmarks.gpuBench.outputSumToFile(logs, prefPath);
}