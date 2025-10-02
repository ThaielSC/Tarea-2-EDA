#include <vector>
#include <string>

static void quickSortRecursive(const std::vector<std::string>& data, std::vector<int>& indices, int i, int j);


static void swap(std::vector<int>& indices, int idx1, int idx2) {
    int temp = indices[idx1];
    indices[idx1] = indices[idx2];
    indices[idx2] = temp;
}


static int split(const std::vector<std::string>& data, std::vector<int>& indices, int i, int j) {
    std::string pivot= data[indices[j]];
    
    int p = i - 1; // Indice del ultimo elemento más pequeño

    for (int q = i; q <= j - 1; q++) {
        if (data[indices[q]] <= pivot) {
            p++;
            swap(indices, p, q);
        }
    }
    swap(indices, p + 1, j);
    return p + 1;
}


static void quickSortRecursive(const std::vector<std::string>& data,
                               std::vector<int>& indices, int i, int j) {
    if (i < j) {
        int k = split(data, indices, i, j);
        
        quickSortRecursive(data, indices, i, k - 1);
        
        quickSortRecursive(data, indices, k + 1, j);
    }
}


std::vector<int> quickSort(const std::vector<std::string>& A) {
    int n = A.size();
    if (n == 0) {
        return {};
    }

    std::vector<int> indices(n);
    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }

    quickSortRecursive(A, indices, 0, n - 1);
    
    return indices;
}