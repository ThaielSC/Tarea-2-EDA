#ifndef DATASET_HPP
#define DATASET_HPP

#include <string>
#include <vector>

class DataSet {
private:
  const std::string filePath;
  size_t size;
  std::vector<std::string> data;

public:
  DataSet(const std::string &filePath) : filePath(filePath), size(0) {}

  void load();

  size_t getSize() const { return size; }

  const std::string &getFilePath() const { return filePath; }

  std::vector<std::string> &getData() { return data; }

  void showOrderBy(const std::vector<int> &sorted_indices, int limit = 0);
};

#endif
