#ifndef COUNTINGSORT_HPP
#define COUNTINGSORT_HPP

#include <vector>
#include <string>

// Adjusted to sort a vector of strings based on the character at a specific position 'p'
void countingSort(std::vector<std::string>& data, int p, int M);

// Overload for sorting indices based on data
void countingSort(const std::vector<std::string>& data, std::vector<int>& indices, int p, int M);

#endif // COUNTINGSORT_HPP