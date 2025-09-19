#ifndef BENCHMARK_HPP
#define BENCHMARK_HPP

#include <iostream>
#include <vector>

class Benchmark {
 private:
  std::vector<double> results;

 public:
  Benchmark();

  // Ejecuta la función 'repeat' veces y almacena los tiempos
  template <typename Func, typename... Args>
  void run(Func func, int repeat, Args&&... args);

  // Reporta resultados al ostream (por defecto std::cout)
  void report(std::ostream& os = std::cout) const;

  // Acceso directo a los resultados
  const std::vector<double>& getResults() const;
};

#include "benchmark.tpp"  // Incluir implementación de métodos template

#endif  // BENCHMARK_HPP
