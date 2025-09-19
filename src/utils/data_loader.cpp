#include "../../include/utils/data_loader.hpp"

#include <fstream>
#include <iostream>

std::vector<std::string> load_data(const std::string& filename) {
  std::vector<std::string> data;
  std::ifstream file(filename);
  std::string value;

  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    return data;
  }

  while (file >> value) {
    data.push_back(value);
  }

  file.close();
  return data;
}
