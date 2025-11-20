#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

const int MAX = 100;

namespace Matrix {

    // Вывод матрицы
    void printMatrix(int arr[][MAX], int rows, int cols);

    // Сумма всех элементов
    long long sumOfElements(int arr[][MAX], int rows, int cols);

    // Максимальный элемент
    int findMaxElement(int arr[][MAX], int rows, int cols);

    // Суммы по строкам
    void sumByRows(int arr[][MAX], int rows, int cols, long long result[]);

    // Суммы по столбцам
    void sumByCols(int arr[][MAX], int rows, int cols, long long result[]);

    // Сумма главной диагонали
    long long sumMainDiagonal(int arr[][MAX], int size);

    // Разница сумм диагоналей
    long long diffDiagonalSums(int arr[][MAX], int size);

    // Сортировка каждой строки по возрастанию
    void sortRows(int arr[][MAX], int rows, int cols);

    // Поворот квадратной матрицы на 90 градусов по часовой стрелке
    void rotate90(int arr[][MAX], int size);

    // Меню операций
    void menu(int arr[][MAX], int rows, int cols);

} // namespace Matrix

#endif // MATRIX_H
#pragma once
