#include <chrono>
#include <string>
#include <vector>

#include "structures/dataSet.hpp"
#include "utils/benchmark.hpp"

#include <filesystem>

Benchmark::Benchmark(DataSet &data) : data(data) {
  std::filesystem::create_directories("results");
  resultsFile.open("results/results.csv", std::ios_base::app);
  if(resultsFile.tellp() == 0) {
    resultsFile << "Algorithm,Size,Time_ms\n";
  }
};

Benchmark::~Benchmark() {
  if (resultsFile.is_open()) {
    resultsFile.close();
  }
}

std::vector<int>
Benchmark::run(std::function<std::vector<int>(const std::vector<std::string> &)>
                   sorterAlgorithm,
               std::string name, size_t times) {
  std::vector<int> sorted;
  RBenchmark result = RBenchmark(name);

  for (size_t i = 0; i < times; i++) {
    auto start_time = std::chrono::high_resolution_clock::now();
    sorted = sorterAlgorithm(data.getData());

    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
        end_time - start_time);

    result.add(duration.count());
    if (resultsFile.is_open()) {
      resultsFile << name << "," << data.getSize() << "," << duration.count() << "\n";
    }
  }
  results.push_back(result);
  return sorted;
}

void Benchmark::report(std::ostream &os) const {
  os << std::endl << "Dataset: " << data.getSize() << std::endl << std::endl;
  for (RBenchmark result : results) {
    result.show();
  }
}

const std::vector<RBenchmark> &Benchmark::getResults() const { return results; }
