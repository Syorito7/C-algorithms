#include "arrays_tasks.h"
#include <vector>
#include <iostream>
#include <locale>


namespace arrays {


    // =======================
    // 🖨 Функции вывода
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
        double avg = static_cast<double>(sum) / size;

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
        if (size == 0) return;
        k %= size;
        std::vector<int> tmp(arr + size - k, arr + size);

        for (int i = static_cast<int>(size) - 1; i >= static_cast<int>(k); --i)
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


    bool findPairWithSum(const int arr[], size_t size, int target, int& x, int& y) {
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


    // =======================
    // 🖨 МЕНЮ ДЛЯ МАССИВОВ
    // =======================

    /**
     * @brief Интерактивное меню для тестирования всех функций массивов.
     */
    void arraysMenu() {
        while (true) {
            std::cout << "\n=== Меню задач с массивами ===\n";
            std::cout << "0: Вернуться в главное меню\n";
            std::cout << "=== 🔹 Базовый уровень ===\n";
            std::cout << "1: Вывести массив\n";
            std::cout << "2: Сумма элементов массива\n";
            std::cout << "3: Максимальный элемент массива\n";
            std::cout << "4: Преобразовать элементы в абсолютные значения\n";
            std::cout << "5: Развернуть массив\n";
            std::cout << "6: Количество элементов больше среднего\n";
            std::cout << "=== 🔸 Средний уровень ===\n";
            std::cout << "7: Проверить, отсортирован ли массив\n";
            std::cout << "8: Посчитать уникальные элементы\n";
            std::cout << "9: Сдвинуть массив вправо\n";
            std::cout << "=== 🔥 Продвинутый уровень ===\n";
            std::cout << "10: Пузырьковая сортировка\n";
            std::cout << "11: Удалить дубликаты\n";
            std::cout << "12: Объединить массивы\n";
            std::cout << "13: Найти пару элементов с заданной суммой\n";
            std::cout << "14: Посчитать тройки с суммой 0\n";
            std::cout << "Выберите задачу: ";

            int choice;
            std::cin >> choice;
            if (choice == 0) return;

            int n;
            std::cout << "Введите размер массива: ";
            std::cin >> n;
            if (n <= 0) continue;

            std::vector<int> arr(n);
            std::cout << "Введите " << n << " элементов массива: ";
            for (int i = 0; i < n; ++i) std::cin >> arr[i];

            switch (choice) {
                // 🔹 Базовый уровень
            case 1:
                std::cout << "Массив: ";
                printArray(arr.data(), arr.size());
                break;
            case 2:
                std::cout << "Сумма элементов: " << sumArray(arr.data(), arr.size()) << "\n";
                break;
            case 3:
                std::cout << "Максимальный элемент: " << maxElement(arr.data(), arr.size()) << "\n";
                break;
            case 4:
                absAll(arr.data(), arr.size());
                std::cout << "Массив после преобразования в абсолютные значения: ";
                printArray(arr.data(), arr.size());
                break;
            case 5:
                reverseArray(arr.data(), arr.size());
                std::cout << "Массив после разворота: ";
                printArray(arr.data(), arr.size());
                break;
            case 6:
                std::cout << "Количество элементов больше среднего: "
                    << countGreaterThanAverage(arr.data(), arr.size()) << "\n";
                break;

                // 🔸 Средний уровень
            case 7:
                std::cout << "Массив отсортирован: " << (isSorted(arr.data(), arr.size()) ? "Да" : "Нет") << "\n";
                break;
            case 8:
                std::cout << "Количество уникальных элементов: " << countUnique(arr.data(), arr.size()) << "\n";
                break;
            case 9: {
                size_t k;
                std::cout << "Введите количество сдвигов: ";
                std::cin >> k;
                shiftRight(arr.data(), arr.size(), k);
                std::cout << "Массив после сдвига: ";
                printArray(arr.data(), arr.size());
                break;
            }

                  // 🔥 Продвинутый уровень
            case 10:
                bubbleSort(arr.data(), arr.size());
                std::cout << "Массив после пузырьковой сортировки: ";
                printArray(arr.data(), arr.size());
                break;
            case 11: {
                size_t newSize = removeDuplicates(arr.data(), arr.size());
                std::cout << "Новый размер массива после удаления дубликатов: " << newSize << "\n";
                std::cout << "Массив после удаления дубликатов: ";
                printArray(arr.data(), arr.size());
                break;
            }
            case 12: {
                int n2;
                std::cout << "Введите размер второго массива: ";
                std::cin >> n2;
                std::vector<int> arr2(n2);
                std::cout << "Введите " << n2 << " элементов второго массива: ";
                for (int i = 0; i < n2; ++i) std::cin >> arr2[i];
                std::vector<int> merged(n + n2);
                mergeArrays(arr.data(), arr.size(), arr2.data(), arr2.size(), merged.data());
                std::cout << "Объединенный массив: ";
                printArray(merged.data(), merged.size());
                break;
            }
            case 13: {
                int target, x, y;
                std::cout << "Введите целевую сумму: ";
                std::cin >> target;
                if (findPairWithSum(arr.data(), arr.size(), target, x, y))
                    std::cout << "Найдена пара элементов: " << x << ", " << y << "\n";
                else
                    std::cout << "Пара элементов с заданной суммой не найдена\n";
                break;
            }
            case 14:
                std::cout << "Количество троек с суммой 0: " << countTripletsZero(arr.data(), arr.size()) << "\n";
                break;

            default:
                std::cout << "Неверный выбор!\n";
                break;
            }
        }
    }

} // namespace arrays
