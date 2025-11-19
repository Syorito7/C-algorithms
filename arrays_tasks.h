#ifndef ARRAYS_TASKS_H
#define ARRAYS_TASKS_H

#include <cstddef>  // Для size_t

namespace arrays {

    // =======================
    // 🖨 МЕНЮ ДЛЯ МАССИВОВ
    // =======================

    /**
     * @brief Интерактивное меню для тестирования всех функций массивов.
     */
    void arraysMenu();

    // =======================
    // 🖨 Функции вывода
    // =======================

    /**
     * @brief Выводит элементы массива в консоль.
     * @param arr Массив целых чисел.
     * @param size Размер массива.
     */
    void printArray(const int arr[], size_t size);

    // =======================
    // 🔹 БАЗОВЫЙ УРОВЕНЬ
    // =======================

    long long sumArray(const int arr[], size_t size);
    int maxElement(const int arr[], size_t size);
    void absAll(int arr[], size_t size);
    void reverseArray(int arr[], size_t size);
    size_t countGreaterThanAverage(const int arr[], size_t size);

    // =======================
    // 🔸 СРЕДНИЙ УРОВЕНЬ
    // =======================

    bool isSorted(const int arr[], size_t size);
    size_t countUnique(const int arr[], size_t size);
    void shiftRight(int arr[], size_t size, size_t k);

    // =======================
    // 🔥 ПРОДВИНУТЫЙ УРОВЕНЬ
    // =======================

    void bubbleSort(int arr[], size_t size);
    size_t removeDuplicates(int arr[], size_t size);
    void mergeArrays(const int arr1[], size_t n1, const int arr2[], size_t n2, int result[]);
    bool findPairWithSum(const int arr[], size_t size, int target, int& x, int& y);
    size_t countTripletsZero(const int arr[], size_t size);

}

#endif // ARRAYS_TASKS_H
