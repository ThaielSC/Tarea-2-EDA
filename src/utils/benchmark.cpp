#include <numeric>

#include "utils/benchmark.hpp"

Benchmark::Benchmark() = default;

std::vector<int> Benchmark::run(
    std::function<std::vector<int>(const std::vector<std::string>&)>
        sorterAlgorithm,
    DataSet& data, size_t times) {
  std::vector<int> sorted;

  for (size_t i = 0; i < times; i++) {
    auto start_time = std::chrono::high_resolution_clock::now();
    sorted = sorterAlgorithm(data.getData());

    auto end_time = std::chrono::high_resolution_clock::now();

    auto duracion = std::chrono::duration_cast<std::chrono::milliseconds>(
        end_time - start_time);

    results.push_back(duracion.count());
  }
  return sorted;
}

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
