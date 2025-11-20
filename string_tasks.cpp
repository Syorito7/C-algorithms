#include "string_tasks.h"
#include <iostream>

namespace string_tasks {

    // длина строки без использования встроенных методов
    // Время: O(n), Память: O(1)
    size_t length_of_string(const std::string& str) {
        const char* ptr = str.c_str();
        size_t count = 0;
        while (*ptr != '\0') {
            ++count;
            ++ptr;
        }
        return count;
    }

    // подсчёт количества пробелов
    // Время: O(n), Память: O(1)
    size_t count_spaces(const std::string& str) {
        size_t count = 0;
        for (char ch : str) {
            if (ch == ' ') ++count;
        }
        return count;
    }

    // подсчёт количества слов в строке (простой вариант, разделитель — пробел)
    // Время: O(n), Память: O(1)
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
    // Время: O(n), Память: O(1)
    size_t count_digits(const std::string& str) {
        size_t count = 0;
        for (char s : str) {
            if (s >= '0' && s <= '9') ++count;
        }
        return count;
    }

    // Перевод строки в верхний регистр
    // Время: O(n), Память: O(n) — создаётся новая строка
    std::string to_uppercase(const std::string& str) {
        std::string result;
        result.reserve(str.size()); // оптимизация
        for (char ch : str) {
            if (ch >= 'a' && ch <= 'z') result += ch - ('a' - 'A');
            else result += ch;
        }
        return result;
    }

    // Удалить все пробелы из строки
    // Время: O(n), Память: O(1) — изменяем строку на месте
    std::string& remove_spaces(std::string& str) {
        size_t write = 0;
        for (size_t read = 0; read < str.size(); ++read) {
            if (str[read] != ' ') str[write++] = str[read];
        }
        str.resize(write);
        return str;
    }

    // Подсчёт слов с множественными разделителями (через substr)
    // Время: O(n), Память: O(k*n) — хранит список слов (k — количество слов)
    size_t count_words(std::string& str) {

        const std::string separators{ " ,.!?;:\n\t" }; // разделители слов
        std::vector<std::string> words; // хранит слова
        size_t start = str.find_first_not_of(separators); // начало первого слова

        // Время работы — линейное — O(n)
        while (start != std::string::npos)
        {
            size_t end = str.find_first_of(separators, start); // конец слова
            if (end == std::string::npos) end = str.length();

            words.push_back(str.substr(start, end - start)); // O(length of word)

            start = str.find_first_not_of(separators, end); // начало следующего слова
        }
        return words.size();
    }
    
    // Проверка строки на палиндром
	// без учёта регистра
    bool isPalindrome(std::string& str)
    {
        // создам строку без пробелов и так далее
        std::string result;
        for (char s : str)
        {
            if (s != ' ')
                result += s;
        }
        // теперь проверим на палиндром
        for (size_t i = 0, j = result.size() - 1; i < j; ++i, --j)
        {
            if (result[i] != result[j]) return false;
        }
        return true;
    }

    // Замена символов
    void replace_char(std::string& str, char oldChar, char newChar) {
        for (size_t i = 0; i < str.size(); ++i) {
            if (str[i] == oldChar) {
                str[i] = newChar;
            }
        }
	}

    // Удаление повторяющихся символов без дополнительных структур
    // Время: O(n^2), Память: O(n) — создаётся новая строка
    std::string remove_duplicates_no_extra(const std::string& str)
    {
        std::string result;

        for (char ch : str) {
            bool found = false;
            for (char r : result) {
                if (r == ch) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result += ch;
            }
        }
        return result;
    }

    // --- Меню ---
    void string_menu() {
        std::string input;
        std::cout << "Введите строку: ";
        std::getline(std::cin, input);

        int choice;
        do {
            std::cout << "\n=== Меню работы со строкой ===\n";
            std::cout << "1. Длина строки\n";
            std::cout << "2. Подсчёт пробелов\n";
            std::cout << "3. Подсчёт слов (простой вариант)\n";
            std::cout << "4. Подсчёт цифр\n";
            std::cout << "5. Перевод в верхний регистр\n";
            std::cout << "6. Удаление всех пробелов\n";
            std::cout << "7. Проверка на палиндром\n";
            std::cout << "8. Замена символов\n";
            std::cout << "0. Выход\n";
            std::cout << "Выберите действие: ";
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
            case 7: {
                bool palindrome = isPalindrome(input);
                std::cout << "Строка " << (palindrome ? "" : "не ") << "является палиндромом\n";
                break;
            }
            case 8: {
                char oldChar, newChar;
                std::cout << "Введите символ для замены: ";
                std::cin >> oldChar;
                std::cout << "Введите новый символ: ";
                std::cin >> newChar;
                std::cin.ignore();
                replace_char(input, oldChar, newChar);
                std::cout << "Строка после замены: " << input << "\n";
                break;
            }
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
            }
        } while (choice != 0);
    }


} // namespace string_tasks
