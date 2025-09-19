#ifndef BENCHMARK_HPP
#define BENCHMARK_HPP

#include <iostream>
#include <vector>

#include "structures/dataSet.hpp"

class Benchmark {
 private:
  std::vector<double> results;
  std::vector<int> orderIndex;

 public:
  Benchmark();

  std::vector<int> run(
      std::function<std::vector<int>(const std::vector<std::string>&)>
          sorterAlgorithm,
      DataSet& data, size_t times = 5);

  // Reporta resultados al ostream (por defecto std::cout)
  void report(std::ostream& os = std::cout) const;

  // Acceso directo a los resultados
  const std::vector<double>& getResults() const;

  // Ejecuta la función 'repeat' veces y almacena los tiempos
  // template <typename Func, typename... Args>
  // void run(Func func, int repeat, Args&&... args);
};

// #include "benchmark.tpp"  // Incluir implementación de métodos template

#endif  // BENCHMARK_HPP
