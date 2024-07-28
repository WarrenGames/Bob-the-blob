#ifndef IN_GAME_OUTPUT_BENCHMARK_DATA_H
#define IN_GAME_OUTPUT_BENCHMARK_DATA_H

struct AppLogFiles;
class PrefPathFinder;
struct Benchs;

void outputBenchmarkDataToFiles(AppLogFiles& logs, const PrefPathFinder& prefPath, const Benchs& benchmarks);

#endif //IN_GAME_OUTPUT_BENCHMARK_DATA_H