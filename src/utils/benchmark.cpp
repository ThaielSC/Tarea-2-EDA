#include <algorithm>
#include <numeric>

#include "utils/benchmark.hpp"

Benchmark::Benchmark() = default;

void Benchmark::report(std::ostream& os) const {
  if (results.empty()) {
    os << "No se han registrado resultados.\n";
    return;
  }

  const size_t n = results.size();
  double total = std::accumulate(results.begin(), results.end(), 0.0);
  double promedio = total / n;
  double minimo = *std::min_element(results.begin(), results.end());
  double maximo = *std::max_element(results.begin(), results.end());

  // Calcular la desviación estándar
  double suma_cuadrados = 0.0;
  for (double x : results) {
    suma_cuadrados += (x - promedio) * (x - promedio);
  }
  double desviacion = std::sqrt(suma_cuadrados / n);

  os << "Benchmark Report:\n";
  os << "  Repeticiones:        " << n << "\n";
  os << "  Promedio:            " << promedio << " ms\n";
  os << "  Mínimo:              " << minimo << " ms\n";
  os << "  Máximo:              " << maximo << " ms\n";
  os << "  Desviación estándar: " << desviacion << " ms\n";
}

const std::vector<double>& Benchmark::getResults() const { return results; }
