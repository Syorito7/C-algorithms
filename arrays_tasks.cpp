#include "arrays_tasks.h"
#include <vector>

namespace arrays {

// =======================
// 🖨 ФУНКЦИИ ВЫВОДА
// =======================

void printArray(const int arr[], size_t size) {
    for (size_t i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}
// Complexity: O(n)


// =======================
// 🔹 БАЗОВЫЙ УРОВЕНЬ
// =======================

long long sumArray(const int arr[], size_t size) {
    long long sum = 0;
    for (size_t i = 0; i < size; ++i)
        sum += arr[i];
    return sum;
}
// Complexity: O(n)


int maxElement(const int arr[], size_t size) {
    int mx = arr[0];
    for (size_t i = 1; i < size; ++i)
        if (arr[i] > mx) mx = arr[i];
    return mx;
}
// Complexity: O(n)


void absAll(int arr[], size_t size) {
    for (size_t i = 0; i < size; ++i)
        if (arr[i] < 0) arr[i] = -arr[i];
}
// Complexity: O(n)


void reverseArray(int arr[], size_t size) {
    for (size_t i = 0; i < size / 2; ++i)
        std::swap(arr[i], arr[size - 1 - i]);
}
// Complexity: O(n)


size_t countGreaterThanAverage(const int arr[], size_t size) {
    long long sum = 0;
    for (size_t i = 0; i < size; ++i) sum += arr[i];
    double avg = (double)sum / size;

    size_t count = 0;
    for (size_t i = 0; i < size; ++i)
        if (arr[i] > avg) count++;

    return count;
}
// Complexity: O(n)


// =======================
// 🔸 СРЕДНИЙ УРОВЕНЬ
// =======================

bool isSorted(const int arr[], size_t size) {
    for (size_t i = 1; i < size; ++i)
        if (arr[i] < arr[i - 1]) return false;
    return true;
}
// Complexity: O(n)


size_t countUnique(const int arr[], size_t size) {
    size_t count = 0;
    for (size_t i = 0; i < size; ++i) {
        bool unique = true;
        for (size_t j = 0; j < i; ++j)
            if (arr[i] == arr[j]) { unique = false; break; }
        if (unique) count++;
    }
    return count;
}
// Complexity: O(n²)


void shiftRight(int arr[], size_t size, size_t k) {
    k %= size;
    std::vector<int> tmp(arr + size - k, arr + size);

    for (size_t i = size - 1; i >= k; --i)
        arr[i] = arr[i - k];

    for (size_t i = 0; i < k; ++i)
        arr[i] = tmp[i];
}
// Complexity: O(n)


// =======================
// 🔥 ПРОДВИНУТЫЙ УРОВЕНЬ
// =======================

void bubbleSort(int arr[], size_t size) {
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
}
// Complexity: O(n²)


size_t removeDuplicates(int arr[], size_t size) {
    size_t newSize = 0;
    for (size_t i = 0; i < size; ++i) {
        bool dup = false;
        for (size_t j = 0; j < newSize; ++j)
            if (arr[j] == arr[i]) { dup = true; break; }
        if (!dup) arr[newSize++] = arr[i];
    }
    return newSize;
}
// Complexity: O(n²)


void mergeArrays(const int arr1[], size_t n1, const int arr2[], size_t n2, int result[]) {
    size_t i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
        result[k++] = (arr1[i] < arr2[j]) ? arr1[i++] : arr2[j++];

    while (i < n1) result[k++] = arr1[i++];
    while (j < n2) result[k++] = arr2[j++];
}
// Complexity: O(n1 + n2)


bool findPairWithSum(const int arr[], size_t size, int target, int &x, int &y) {
    for (size_t i = 0; i < size; ++i)
        for (size_t j = i + 1; j < size; ++j)
            if (arr[i] + arr[j] == target) {
                x = arr[i]; y = arr[j];
                return true;
            }
    return false;
}
// Complexity: O(n²)


size_t countTripletsZero(const int arr[], size_t size) {
    size_t count = 0;
    for (size_t i = 0; i < size; ++i)
        for (size_t j = i + 1; j < size; ++j)
            for (size_t k = j + 1; k < size; ++k)
                if (arr[i] + arr[j] + arr[k] == 0)
                    count++;
    return count;
}
// Complexity: O(n³)

} // namespace arrays
