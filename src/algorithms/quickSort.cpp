#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <string>
#include <tuple>
#include <vector>

std::tuple<std::function<int(const std::vector<std::string>&, int, int)>,
           std::reference_wrapper<std::vector<int>>>
createSplitFunc(int n) {
  static std::vector<int> indexes(n);
  srand(time(NULL));

  std::iota(indexes.begin(), indexes.end(), 0);

  auto split = [&](const std::vector<std::string>& A, int i, int j) -> int {
    int p = i + rand() % (j - i + 1);

    std::swap(indexes[p], indexes[j]);
    int pivot_idx = j;
    int wall = i - 1;

    for (int k = i; k < j; k++) {
      if (A[indexes[k]] <= A[indexes[pivot_idx]]) {
        wall++;
        std::swap(indexes[wall], indexes[k]);
      }
    }
    std::swap(indexes[wall + 1], indexes[pivot_idx]);

    return wall + 1;
  };

  return std::make_tuple(split, std::ref(indexes));
}

void recursiveQuickSort(
    const std::vector<std::string>& A, std::vector<int>& indexes,
    const std::function<int(const std::vector<std::string>&, int, int)>& split,
    int i, int j) {
  if (i < j) {
    int p = split(A, i, j);
    recursiveQuickSort(A, indexes, split, i, p - 1);
    recursiveQuickSort(A, indexes, split, p + 1, j);
  }
}

std::vector<int> quickSort(const std::vector<std::string>& A) {
  int n = A.size();
  auto [split, indexesRef] = createSplitFunc(n);
  std::vector<int>& indexes = indexesRef.get();

  recursiveQuickSort(A, indexes, split, 0, n - 1);

  return indexes;
}
