#include "Matrix.h"

namespace Matrix {

    void printMatrix(int arr[][MAX], int rows, int cols) {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j)
                std::cout << arr[i][j] << " ";
            std::cout << std::endl;
        }
    }

    long long sumOfElements(int arr[][MAX], int rows, int cols) {
        long long sum = 0;
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                sum += arr[i][j];
        return sum;
    }

    int findMaxElement(int arr[][MAX], int rows, int cols) {
        int maxElement = arr[0][0];
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                if (arr[i][j] > maxElement)
                    maxElement = arr[i][j];
        return maxElement;
    }

    void sumByRows(int arr[][MAX], int rows, int cols, long long result[]) {
        for (size_t i = 0; i < rows; ++i) {
            result[i] = 0;
            for (size_t j = 0; j < cols; ++j)
                result[i] += arr[i][j];
        }
    }

    void sumByCols(int arr[][MAX], int rows, int cols, long long result[]) {
        for (size_t j = 0; j < cols; ++j) {
            result[j] = 0;
            for (size_t i = 0; i < rows; ++i)
                result[j] += arr[i][j];
        }
    }

    long long sumMainDiagonal(int arr[][MAX], int size) {
        long long sum = 0;
        for (size_t i = 0; i < size; ++i)
            sum += arr[i][i];
        return sum;
    }

    long long diffDiagonalSums(int arr[][MAX], int size) {
        long long mainDiagSum = 0, secondaryDiagSum = 0;
        for (size_t i = 0; i < size; ++i) {
            mainDiagSum += arr[i][i];
            secondaryDiagSum += arr[i][size - i - 1];
        }
        return mainDiagSum - secondaryDiagSum;
    }

    void sortRows(int arr[][MAX], int rows, int cols) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols - 1; ++j) {
                for (int k = 0; k < cols - j - 1; ++k) {
                    if (arr[i][k] > arr[i][k + 1])
                        std::swap(arr[i][k], arr[i][k + 1]);
                }
            }
        }
    }

    void rotate90(int arr[][MAX], int size) {
        for (int i = 0; i < size / 2; ++i) {
            for (int j = i; j < size - i - 1; ++j) {
                int temp = arr[i][j];
                arr[i][j] = arr[size - j - 1][i];
                arr[size - j - 1][i] = arr[size - i - 1][size - j - 1];
                arr[size - i - 1][size - j - 1] = arr[j][size - i - 1];
                arr[j][size - i - 1] = temp;
            }
        }
    }

    void menu(int arr[][MAX], int rows, int cols) {
        int choice;
        do {
            std::cout << "\n=== Меню операций с матрицей ===\n";
            std::cout << "1. Показать матрицу\n";
            std::cout << "2. Сумма всех элементов\n";
            std::cout << "3. Максимальный элемент\n";
            std::cout << "4. Суммы по строкам\n";
            std::cout << "5. Суммы по столбцам\n";
            std::cout << "6. Сумма главной диагонали (только для квадратной матрицы)\n";
            std::cout << "7. Разница сумм диагоналей (только для квадратной матрицы)\n";
            std::cout << "8. Сортировка строк по возрастанию\n";
            std::cout << "9. Поворот квадратной матрицы на 90 градусов\n";
            std::cout << "0. Выход\n";
            std::cout << "Выберите действие: ";
            std::cin >> choice;

            switch (choice) {
            case 1: printMatrix(arr, rows, cols); break;
            case 2: std::cout << "Сумма всех элементов: " << sumOfElements(arr, rows, cols) << std::endl; break;
            case 3: std::cout << "Максимальный элемент: " << findMaxElement(arr, rows, cols) << std::endl; break;
            case 4: {
                long long rowSum[MAX];
                sumByRows(arr, rows, cols, rowSum);
                for (int i = 0; i < rows; ++i)
                    std::cout << "Сумма строки " << i << ": " << rowSum[i] << std::endl;
                break;
            }
            case 5: {
                long long colSum[MAX];
                sumByCols(arr, rows, cols, colSum);
                for (int j = 0; j < cols; ++j)
                    std::cout << "Сумма столбца " << j << ": " << colSum[j] << std::endl;
                break;
            }
            case 6:
                if (rows != cols) std::cout << "Ошибка: только квадратная матрица!\n";
                else std::cout << "Сумма главной диагонали: " << sumMainDiagonal(arr, rows) << std::endl;
                break;
            case 7:
                if (rows != cols) std::cout << "Ошибка: только квадратная матрица!\n";
                else std::cout << "Разница сумм диагоналей: " << diffDiagonalSums(arr, rows) << std::endl;
                break;
            case 8: sortRows(arr, rows, cols); std::cout << "Строки отсортированы.\n"; break;
            case 9:
                if (rows != cols) std::cout << "Ошибка: только квадратная матрица!\n";
                else { rotate90(arr, rows); std::cout << "Матрица повернута на 90 градусов.\n"; }
                break;
            case 0: std::cout << "Выход...\n"; break;
            default: std::cout << "Неверный выбор, попробуйте снова.\n";
            }
        } while (choice != 0);
    }

} // namespace Matrix
