#include <vector>

#include "algorithms/countingSort.hpp"
#include "structures/linkedList.hpp"

// Helper function to get the integer value of a character
int getCharValue(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  } else if (c >= 'A' && c <= 'Z') {
    return c - 'A';
  }
  return -1;  // Should not happen with valid codes
}

void countingSort(std::vector<std::string>& data, int p, int M) {
  size_t n = data.size();
  if (n == 0) return;

  // 1. Create an array of Linked Lists (buckets)
  std::vector<LinkedList> buckets(M);

  // 2. Add the index of each code to the corresponding bucket
  for (size_t i = 0; i < n; ++i) {
    // The postal codes are 6 characters long, p is 1-based in the PDF.
    // Adjust p to be 0-based for array indexing.
    int char_pos = p - 1;
    if (char_pos < 0 || char_pos >= data[i].length()) continue;  // Safety check

    int value = getCharValue(data[i][char_pos]);
    if (value != -1) {
      buckets[value].insert(i);
    }
  }

  // 3. Store a copy of the original data
  std::vector<std::string> original_data = data;

  // 4. Reconstruct the data vector in sorted order
  int k = 0;
  for (int i = 0; i < M; ++i) {
    Node* current = buckets[i].head;
    while (current != nullptr) {
      data[k] = original_data[current->data];
      k++;
      current = current->next;
    }
  }
}

// Implementation for sorting indices
void countingSort(const std::vector<std::string>& data, std::vector<int>& indices, int p, int M) {
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
