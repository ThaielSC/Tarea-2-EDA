#include <future>
#include <iostream>
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

  std::cout << "Cargando archivos:" << std::endl;

  auto load_dataset = [](const std::string& path) {
    std::cout << "  -> Cargando " << path << "..." << std::endl;
    DataSet ds(path);
    ds.load();
    return ds;
  };

  std::vector<std::future<DataSet>> futures;
  for (const auto& path : paths) {
    futures.push_back(std::async(std::launch::async, load_dataset, path));
  }

  for (auto& f : futures) {
    datasets.push_back(f.get());
  }

  Benchmark small_bench(datasets[0]);
  Benchmark medium_bench(datasets[1]);
  Benchmark big_bench(datasets[2]);

  std::cout << "Carga completada." << std::endl << std::endl;

  if (!datasets.empty()) {
    small_bench.run(radixSort, "Radix Sort");
    small_bench.run(quickSort, "Quick Sort");
    small_bench.run(mergeSort, "Merge Sort");
    medium_bench.run(radixSort, "Radix Sort");
    medium_bench.run(mergeSort, "Merge Sort");
    medium_bench.run(quickSort, "Quick Sort");
    big_bench.run(radixSort, "Radix Sort");
    big_bench.run(mergeSort, "Merge Sort");
    big_bench.run(quickSort, "Quick Sort");

    small_bench.report();
    medium_bench.report();
    big_bench.report();
  }

  std::cout << std::endl << "Presiona `q` para salir..." << std::endl;
  return 0;
}
