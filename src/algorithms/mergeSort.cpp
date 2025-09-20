#include "algorithms/mergeSort.hpp"
#include <iostream>
#include <numeric>

void merge(const std::vector<std::string>& data, std::vector<int>& indices,
           int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  std::vector<int> L(n1), R(n2);

  for (int i = 0; i < n1; i++)
    L[i] = indices[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = indices[mid + 1 + j];

  int i = 0;
  int j = 0;
  int k = left;

  while (i < n1 && j < n2) {
    if (data[L[i]] <= data[R[j]]) {
      indices[k] = L[i];
      i++;
    } else {
      indices[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    indices[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    indices[k] = R[j];
    j++;
    k++;
  }
}

void mergeSortRecursive(const std::vector<std::string>& data,
                        std::vector<int>& indices, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSortRecursive(data, indices, left, mid);
    mergeSortRecursive(data, indices, mid + 1, right);
    merge(data, indices, left, mid, right);
  }
}

std::vector<int> mergeSort(const std::vector<std::string>& data) {
  if (data.empty()) {
    return {};
  }
  std::vector<int> indices(data.size());
  std::iota(indices.begin(), indices.end(), 0);

  mergeSortRecursive(data, indices, 0, data.size() - 1);

  return indices;
}