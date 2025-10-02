#include "algorithms/mergeSort.hpp"

static void merge(const std::vector<std::string>& data,
                  std::vector<int>& indices, int i, int k, int j) {
    
    int size = j - i + 1;
    std::vector<int> temp(size); //vector temporal (indices ordenados)
    
    int p1 = i;
    int p2 = k + 1;
    int q = 0;

    while (p1 <= k && p2 <= j) {
        if (data[indices[p1]] <= data[indices[p2]]) {
            temp[q] = indices[p1];
            p1++;
        } else {
            temp[q] = indices[p2];
            p2++;
        }
        q++;
    }
    while (p1 <= k) {
        temp[q] = indices[p1];
        p1++;
        q++;
    }
    while (p2 <= j) {
        temp[q] = indices[p2];
        p2++;
        q++;
    }
    for (int l = 0; l < size; l++) {
        indices[i + l] = temp[l];
    }
}

static void mergeSortRecursive(const std::vector<std::string>& data, 
                               std::vector<int>& indices, int i, int j) {
    if (i < j) {
        int k = i + (j - i) / 2;
        
        mergeSortRecursive(data, indices, i, k);
        
        mergeSortRecursive(data, indices, k + 1, j);
        
        merge(data, indices, i, k, j);
    }
}

std::vector<int> mergeSort(const std::vector<std::string>& data) {
    int n = data.size();
    if (n == 0) {
        return {};
    }

    std::vector<int> indices(n);
    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }

    mergeSortRecursive(data, indices, 0, n - 1);
    
    return indices;
}