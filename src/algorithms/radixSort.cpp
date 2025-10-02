#include "algorithms/countingSort.hpp"
#include "algorithms/radixSort.hpp"
#include <numeric>
#include <vector>

std::vector<int> radixSort(const std::vector<std::string> &data) {
  std::vector<int> indices(data.size());
  std::iota(indices.begin(), indices.end(), 0);

  countingSort(data, indices, 5, 26);
  countingSort(data, indices, 4, 26);

  for (int i = 3; i >= 0; i--) {
    countingSort(data, indices, i, 10);
  }

  return indices;
}
