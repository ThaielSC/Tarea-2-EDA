#include <future>
#include <iostream>
#include <vector>

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

  Benchmark b(datasets[0]);

  std::cout << "Carga completada." << std::endl << std::endl;

  if (!datasets.empty()) {
    b.run(radixSort, "Radix Sort");
    // b.run(mergeSort, "Merge Sort");
    // b.run(quickSort, "Quick Sort");
    b.report();
  }

  std::cout << std::endl << "Presiona `q` para salir..." << std::endl;
  return 0;
}
