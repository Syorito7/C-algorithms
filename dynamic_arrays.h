#pragma once
#include <cstddef>
#include <iostream>

namespace dynamic
{
    // ======================= ОДНОМЕРНЫЕ МАССИВЫ =======================

    // Удаление элемента
    void removeElement(int arr[], size_t& size, int index);

    // Добавление элемента (увеличение массива)
    void pushBack(int*& arr, size_t& size, int value);

    // Вывод одномерного массива
    void printArray(int arr[], size_t size);


    // ======================= ДВУМЕРНЫЕ МАССИВЫ =======================

    // Создание 2D массива
    int** create2DArray(size_t rows, size_t cols);

    // Освобождение памяти 2D массива
    void delete2DArray(int** arr, size_t rows);

    // Транспонирование матрицы
    int** transposeMatrix(int** arr, size_t rows, size_t cols);

    // Вывод двумерного массива
    void print2DArray(int** arr, size_t rows, size_t cols);


    // ======================= МЕНЮ =======================

    void menu();
}
