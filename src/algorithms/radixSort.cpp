#include "algorithms/radixSort.hpp"
#include "algorithms/countingSort.hpp"
#include <numeric> // Required for std::iota

// Implements Radix Sort to return sorted indices.
std::vector<int> radixSort(const std::vector<std::string>& data) {
    if (data.empty()) return {};

    std::vector<int> indices(data.size());
    std::iota(indices.begin(), indices.end(), 0); // Initialize indices to 0, 1, 2, ...

    // Sort by the 6th character (second letter), range is 26 for A-Z.
    countingSort(data, indices, 6, 26);

    // Sort by the 5th character (first letter), range is 26 for A-Z.
    countingSort(data, indices, 5, 26);

    // Sort by the 4th down to the 1st character (the digits), range is 10 for 0-9.
    for (int p = 4; p >= 1; --p) {
        countingSort(data, indices, p, 10);
    }

    return indices;
}
