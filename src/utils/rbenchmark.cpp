#include <algorithm>
#include <cmath>
#include <numeric>

#include "utils/rbenchmark.hpp"

void RBenchmark::add(double duration) { result.push_back(duration); }

void RBenchmark::show(std::ostream &os) const {
  if (result.empty()) {
    os << "No se han registrado resultados.\n";
    return;
  }

  const size_t n = result.size();
  double total = std::accumulate(result.begin(), result.end(), 0.0);
  double promedio = total / n;
  double minimo = *std::min_element(result.begin(), result.end());
  double maximo = *std::max_element(result.begin(), result.end());

  // Calcular la desviación estándar
  double suma_cuadrados = 0.0;
  for (double x : result) {
    suma_cuadrados += (x - promedio) * (x - promedio);
  }
  double desviacion = std::sqrt(suma_cuadrados / n);

  os << "Benchmark Report:\n";
  os << "  Algoritmo:           " << name << "\n";
  os << "  Repeticiones:        " << n << "\n";
  os << "  Promedio:            " << promedio << " ms\n";
  os << "  Mínimo:              " << minimo << " ms\n";
  os << "  Máximo:              " << maximo << " ms\n";
  os << "  Desviación estándar: " << desviacion << " ms\n";
}
