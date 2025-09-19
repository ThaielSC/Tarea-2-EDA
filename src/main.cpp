#include <iomanip>
#include <iostream>
#include <vector>

#include "algorithms/radixSort.hpp"
#include "structures/dataSet.hpp"
#include "utils/benchmark.hpp"

// Helper function to print a vector of strings
void printVector(const std::string& label,
                 const std::vector<std::string>& vec) {
  std::cout << label << ": ";
  for (const auto& s : vec) {
    std::cout << s << " ";
  }
  std::cout << std::endl;
}

int main() {
  Benchmark b;
  std::vector<DataSet> datasets;

  std::vector<std::string> paths = {"data/codes_500K.txt", "data/codes_1M.txt",
                                    "data/codes_10M.txt"};

  for (const auto& path : paths) {
    DataSet ds(path);
    ds.load();
    datasets.push_back(std::move(ds));
  }

  std::cout << std::left << std::setw(24) << "Files" << "Items" << std::endl;
  std::cout << std::endl;

  for (auto& ds : datasets) {
    std::cout << std::left << std::setw(24) << ds.getFilePath() << ds.getSize()
              << std::endl;
  }

  // Benchmark the 500K dataset
  if (!datasets.empty()) {
    std::cout << std::endl
              << "--- Running Benchmark on 500K dataset ---" << std::endl;
    b.run(radixSort, 5, datasets[0].getData());
    b.report();
    std::cout << "--- Benchmark Finished ---" << std::endl;
  }

  std::cout << std::endl << "Presiona `q` para salir..." << std::endl;
  return 0;
}
