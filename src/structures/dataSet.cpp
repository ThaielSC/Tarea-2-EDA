#include <fstream>
#include <iostream>

#include "structures/dataSet.hpp"

void DataSet::load() {
  std::ifstream file(filePath);
  std::string value;

  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filePath << std::endl;
  }

  while (file >> value) {
    data.push_back(value);
  }
  file.close();
  size = data.size();
}

void DataSet::showOrderBy(const std::vector<int>& sorted_indices) {
  for (size_t index : sorted_indices) {
    if (index >= 0 && index < data.size()) {
      std::cout << data[index] << " ";
    }
  }
  std::cout << std::endl;
}
