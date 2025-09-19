#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "../include/utils/data_loader.hpp"

int main() {
  std::vector<std::string> files = {"data/codes_500K.txt", "data/codes_1M.txt",
                                    "data/codes_10M.txt"};

  std::cout << std::left << std::setw(24) << "File" << "Items" << std::endl;
  std::cout << std::endl;

  for (const auto& file : files) {
    std::vector<std::string> data = load_data(file);
    std::cout << std::left << std::setw(24) << file << data.size() << std::endl;
  }

  return 0;
}
