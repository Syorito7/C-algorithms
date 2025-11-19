#ifndef STRING_TASKS_H
#define STRING_TASKS_H

#include <string>
#include <cstddef> // для size_t

namespace string_tasks {

    // Базовый уровень

    // длина строки без использования встроенных методов
    size_t length_of_string(const std::string& str);

    // подсчёт количество пробелов
    size_t count_spaces(const std::string& str);

    // подсчёт количества слов в строке
    size_t count_words(const std::string& str);

    // Подсчёт количества цифр в строке
    size_t count_digits(const std::string& str);

    // Перевод строки в верхний регистр
    std::string to_uppercase(const std::string& str);

    // Удалить все пробелы из строки
    std::string& remove_spaces(std::string& str);

    // Меню выбора действий
    void string_menu();

} // namespace string_tasks

#endif // STRING_TASKS_H
