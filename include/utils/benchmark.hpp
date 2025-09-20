#ifndef BENCHMARK_HPP
#define BENCHMARK_HPP

#include <functional>
#include <iostream>
#include <vector>

#include "structures/dataSet.hpp"
#include "utils/rbenchmark.hpp"

class Benchmark {
private:
  std::vector<RBenchmark> results;
  DataSet &data;

public:
  Benchmark(DataSet &);

  std::vector<int>
  run(std::function<std::vector<int>(const std::vector<std::string> &)>
          sorterAlgorithm,
      std::string name, size_t times = 5);

  // Reporta resultados al ostream (por defecto std::cout)
  void report(std::ostream &os = std::cout) const;

  // Acceso directo a los resultados
  const std::vector<RBenchmark> &getResults() const;
};

#endif // BENCHMARK_HPP
