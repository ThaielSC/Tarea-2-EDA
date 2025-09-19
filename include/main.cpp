#include <iostream>
#include <vector>

#include "algorithms/mergeSort.hpp"
#include "algorithms/quickSort.hpp"
#include "algorithms/radixSort.hpp"

int main() {
  std::vector<int> arr = {5, 2, 8, 1, 9, 4};

  mergeSort(arr);
  quickSort(arr);
  // radixSort(arr);

  for (int i : arr) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}
