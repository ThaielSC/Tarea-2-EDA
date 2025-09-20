#include <numeric>

#include "algorithms/countingSort.hpp"
#include "algorithms/radixSort.hpp"

std::vector<int> radixSort(const std::vector<std::string>& data) {
  if (data.empty()) return {};

  std::vector<int> indices(data.size());
  std::iota(indices.begin(), indices.end(), 0);
  countingSort(data, indices, 6, 26);

  countingSort(data, indices, 5, 26);

  for (int p = 4; p >= 1; --p) {
    countingSort(data, indices, p, 10);
  }

  return indices;
}
