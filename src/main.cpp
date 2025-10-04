#include <future>
#include <iostream>
#include <mutex>
#include <vector>

#include "algorithms/mergeSort.hpp"
#include "algorithms/quickSort.hpp"
#include "algorithms/radixSort.hpp"
#include "structures/dataSet.hpp"
#include "utils/benchmark.hpp"

int main() {
  std::vector<std::string> paths = {"data/codes_500K.txt", "data/codes_1M.txt",
                                    "data/codes_10M.txt"};
  std::vector<DataSet> datasets;
  std::mutex cout_mutex;

  std::cout << "Cargando archivos:" << std::endl;

  auto load_dataset = [&](const std::string &path) {
    DataSet ds(path);
    ds.load();
    {
      std::lock_guard<std::mutex> lock(cout_mutex);
      std::cout << "  -> Cargado: " << path << "..." << std::endl;
    }
    return ds;
  };

  std::vector<std::future<DataSet>> futures;
  for (const auto &path : paths) {
    futures.push_back(std::async(std::launch::async, load_dataset, path));
  }

  for (auto &f : futures) {
    datasets.push_back(f.get());
  }

  Benchmark small_bench(datasets[0]);
  Benchmark medium_bench(datasets[1]);
  Benchmark large_bench(datasets[2]);

  std::cout << "Carga completada." << std::endl << std::endl;

  if (!datasets.empty()) {
    auto radix_S = small_bench.run(radixSort, "Radix Sort");
    auto quick_S = small_bench.run(quickSort, "Quick Sort");
    auto merge_S = small_bench.run(mergeSort, "Merge Sort");
    // auto radix_M = medium_bench.run(radixSort, "Radix Sort");
    // auto quick_M = medium_bench.run(mergeSort, "Merge Sort");
    // auto merge_M = medium_bench.run(quickSort, "Quick Sort");
    // auto radix_L = large_bench.run(radixSort, "Radix Sort");
    // auto quick_L = large_bench.run(mergeSort, "Merge Sort");
    // auto merge_L = large_bench.run(quickSort, "Quick Sort");

    // DEBUG: MOSTRAR DATA ORDENADA POR UN CADA ALGORITMO
    // Limita los n primeros códigos para mostrar en consola, 0 para deslimitar
    int limit = 5;
    std::cout << "500k" << std::endl;
    std::cout << "Radix Sort: ";
    datasets[0].showOrderBy(radix_S, limit);
    std::cout << "Quick Sort: ";
    datasets[0].showOrderBy(quick_S, limit);
    std::cout << "Merge Sort: ";
    datasets[0].showOrderBy(merge_S, limit);
    std::cout << std::endl;

    // std::cout << "1MM" << std::endl;
    // std::cout << "Radix Sort: ";
    // datasets[1].showOrderBy(radix_M, limit);
    // std::cout << "Quick Sort: ";
    // datasets[1].showOrderBy(quick_M, limit);
    // std::cout << "Merge Sort: ";
    // datasets[1].showOrderBy(merge_M, limit);
    // std::cout << std::endl;

    // std::cout << "10MM" << std::endl;
    // std::cout << "Radix Sort: ";
    // datasets[2].showOrderBy(radix_L, limit);
    // std::cout << "Quick Sort: ";
    // datasets[2].showOrderBy(quick_L, limit);
    // std::cout << "Merge Sort: ";
    // datasets[2].showOrderBy(merge_L, limit);
    // std::cout << std::endl;

    small_bench.report();
    // medium_bench.report();
    // large_bench.report();
  }
  return 0;
}
