#include <vector>

#include "algorithms/countingSort.hpp"
#include "structures/linkedList.hpp"

static int getCharValue(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  } else if (c >= 'A' && c <= 'Z') {
    return c - 'A';
  }
  return -1;
}

void countingSort(const std::vector<std::string>& data,
                  std::vector<int>& indices, int p, int M) {
  size_t n = indices.size();
  if (n == 0) return;

  std::vector<LinkedList> buckets(M);

  for (size_t i = 0; i < n; ++i) {
    int index = indices[i];
    int char_pos = p - 1;
    if (char_pos < 0 || char_pos >= data[index].length()) continue;

    int value = getCharValue(data[index][char_pos]);
    if (value != -1) {
      buckets[value].insert(index);
    }
  }

  int k = 0;
  for (int i = 0; i < M; ++i) {
    Node* current = buckets[i].head;
    while (current != nullptr) {
      indices[k] = current->data;
      k++;
      current = current->next;
    }
  }
}
