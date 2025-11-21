#include <iostream>

namespace dynamic {

	// 🔹 Задача 1: Удаление элемента
	void removeElement(int arr[], size_t& size, int index)
	{
		if (index < 0 || index >= size) return;
		for (size_t i = index; i < size - 1; ++i)
			arr[i] = arr[i + 1];
		--size;
	}

	// 🔹 Задача 2: push_back
	void pushBack(int*& arr, size_t& size, int value)
	{
		int* newArr = new int[size + 1];
		if (!newArr) return;

		for (size_t i = 0; i < size; ++i)
			newArr[i] = arr[i];

		newArr[size] = value;
		++size;

		delete[] arr;
		arr = newArr;
	}

	// 🔹 Создание 2D массива
	int** create2DArray(size_t rows, size_t cols)
	{
		int** arr = new int* [rows];
		if (!arr) return nullptr;

		for (size_t i = 0; i < rows; ++i)
		{
			arr[i] = new int[cols];
			if (!arr[i]) return nullptr;

			for (size_t j = 0; j < cols; ++j)
				std::cin >> arr[i][j];
		}
		return arr;
	}

	// 🔹 Освобождение 2D массива
	void delete2DArray(int** arr, size_t rows)
	{
		for (size_t i = 0; i < rows; ++i)
			delete[] arr[i];

		delete[] arr;
	}

	// 🔹 Транспонирование матрицы
	int** transposeMatrix(int** arr, size_t rows, size_t cols)
	{
		int** transposed = new int* [cols];
		if (!transposed) return nullptr;

		for (size_t i = 0; i < cols; ++i)
		{
			transposed[i] = new int[rows];
			if (!transposed[i]) return nullptr;

			for (size_t j = 0; j < rows; ++j)
				transposed[i][j] = arr[j][i];
		}
		return transposed;
	}

	// ======================= ДОП. ФУНКЦИИ =======================

	// вывод одномерного массива
	void printArray(int arr[], size_t size)
	{
		for (size_t i = 0; i < size; ++i)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}

	// вывод двумерного массива
	void print2DArray(int** arr, size_t rows, size_t cols)
	{
		for (size_t i = 0; i < rows; ++i)
		{
			for (size_t j = 0; j < cols; ++j)
				std::cout << arr[i][j] << " ";
			std::cout << std::endl;
		}
	}

	// ======================= МЕНЮ =======================

	void menu()
	{
		size_t size = 0;
		int* arr = nullptr;

		int** matrix = nullptr;
		size_t rows = 0, cols = 0;

		int choice;
		do
		{
			std::cout << "\n===== МЕНЮ ДИНАМИЧЕСКИХ МАССИВОВ =====\n";
			std::cout << "1. Добавить элемент (1D)\n";
			std::cout << "2. Удалить элемент (1D)\n";
			std::cout << "3. Изменить элемент (1D)\n";
			std::cout << "4. Вывести массив (1D)\n";
			std::cout << "5. Создать 2D массив\n";
			std::cout << "6. Транспонировать 2D массив\n";
			std::cout << "7. Вывести 2D массив\n";
			std::cout << "8. Удалить 2D массив\n";
			std::cout << "9. Выход\n";
			std::cout << "Введите выбор: ";
			std::cin >> choice;

			switch (choice)
			{
			case 1: {
				int value;
				std::cout << "Введите число: ";
				std::cin >> value;
				pushBack(arr, size, value);
				break;
			}
			case 2: {
				int index;
				std::cout << "Введите индекс: ";
				std::cin >> index;
				removeElement(arr, size, index);
				break;
			}
			case 3: {
				int index, value;
				std::cout << "Введите индекс: ";
				std::cin >> index;
				if (index >= 0 && index < size)
				{
					std::cout << "Введите новое значение: ";
					std::cin >> value;
					arr[index] = value;
				}
				else std::cout << "Неверный индекс!\n";
				break;
			}
			case 4:
				printArray(arr, size);
				break;

			case 5:
				std::cout << "Введите кол-во строк и столбцов: ";
				std::cin >> rows >> cols;
				matrix = create2DArray(rows, cols);
				break;

			case 6:
				if (matrix)
				{
					int** t = transposeMatrix(matrix, rows, cols);
					delete2DArray(matrix, rows);
					matrix = t;
					std::swap(rows, cols);
					std::cout << "Матрица транспонирована.\n";
				}
				else std::cout << "Матрица не создана!\n";
				break;

			case 7:
				if (matrix) print2DArray(matrix, rows, cols);
				else std::cout << "Матрица не создана!\n";
				break;

			case 8:
				if (matrix)
				{
					delete2DArray(matrix, rows);
					matrix = nullptr;
					std::cout << "Матрица удалена.\n";
				}
				break;

			case 9:
				std::cout << "Выход...\n";
				break;

			default:
				std::cout << "Неверный пункт меню!\n";
			}

		} while (choice != 9);

		delete[] arr;
		if (matrix) delete2DArray(matrix, rows);
	}

} // namespace dynamic
