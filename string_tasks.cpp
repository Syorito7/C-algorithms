#include "string_tasks.h"
#include <iostream>

namespace string_tasks {

    // длина строки без использования встроенных методов
    size_t length_of_string(const std::string& str) {
        const char* ptr = str.c_str();
        size_t count = 0;
        while (*ptr != '\0') {
            ++count;
            ++ptr;
        }
        return count;
    }

    // подсчёт количество пробелов
    size_t count_spaces(const std::string& str) {
        size_t count = 0;
        for (char ch : str) {
            if (ch == ' ') ++count;
        }
        return count;
    }

    // подсчёт количества слов в строке
    size_t count_words(const std::string& str) {
        size_t count = 0;
        bool inWord = false;
        for (char ch : str) {
            if (ch != ' ' && !inWord) {
                inWord = true;
                ++count;
            }
            else if (ch == ' ') {
                inWord = false;
            }
        }
        return count;
    }

    // Подсчёт количества цифр в строке
    size_t count_digits(const std::string& str) {
        size_t count = 0;
        for (char s : str) {
            if (s >= '0' && s <= '9') ++count;
        }
        return count;
    }

    // Перевод строки в верхний регистр
    std::string to_uppercase(const std::string& str) {
        std::string result;
        for (char ch : str) {
            if (ch >= 'a' && ch <= 'z') result += ch - ('a' - 'A');
            else result += ch;
        }
        return result;
    }

    // Удалить все пробелы из строки
    std::string& remove_spaces(std::string& str) {
        size_t write = 0;
        for (size_t read = 0; read < str.size(); ++read) {
            if (str[read] != ' ') str[write++] = str[read];
        }
        str.resize(write);
        return str;
    }

    // --- Меню ---
    void string_menu() {
        std::string input;
        std::cout << "Введите строку: ";
        std::getline(std::cin, input);

        int choice;
        do {
            std::cout << "\nВыберите действие:\n";
            std::cout << "1. Длина строки\n";
            std::cout << "2. Подсчёт пробелов\n";
            std::cout << "3. Подсчёт слов\n";
            std::cout << "4. Подсчёт цифр\n";
            std::cout << "5. Перевод в верхний регистр\n";
            std::cout << "6. Удаление всех пробелов\n";
            std::cout << "0. Выход\n";
            std::cout << "Введите номер действия: ";
            std::cin >> choice;
            std::cin.ignore(); // очистка буфера

            switch (choice) {
            case 1:
                std::cout << "Длина строки: " << length_of_string(input) << "\n";
                break;
            case 2:
                std::cout << "Количество пробелов: " << count_spaces(input) << "\n";
                break;
            case 3:
                std::cout << "Количество слов: " << count_words(input) << "\n";
                break;
            case 4:
                std::cout << "Количество цифр: " << count_digits(input) << "\n";
                break;
            case 5:
                std::cout << "Строка в верхнем регистре: " << to_uppercase(input) << "\n";
                break;
            case 6:
                std::cout << "Строка без пробелов: " << remove_spaces(input) << "\n";
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
            }
        } while (choice != 0);
    }

} // namespace string_tasks
