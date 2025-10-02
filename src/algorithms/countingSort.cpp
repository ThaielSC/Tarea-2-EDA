#include <stdexcept>
#include <string>
#include <vector>

#include "algorithms/countingSort.hpp"
#include "structures/linkedList.hpp"

static int getPos(char c) {
  if (c >= 'A' && c <= 'Z') {
    return (int)c - (int)'A';
  }

  if (c >= '0' && c <= '9') {
    return (int)c - (int)'0';
  }

  throw std::invalid_argument("Invalid character in data: " +
                              std::string(1, c));
}

void countingSort(const std::vector<std::string> &data,
                  std::vector<int> &indices, int p, int M) {
  std::vector<LinkedList> L(M);

  for (int i : indices) {
    const std::string &code = data[i];
    const char &codechar = code[p];
    L[getPos(codechar)].insertLast(i);
  }

  indices.clear();

  for (int i = 0; i < M; i++) {
    Node *ptr = L[i].getHead();
    while (ptr != nullptr) {
      indices.push_back(ptr->getData());
      ptr = ptr->getNext();
    }
  }
}
