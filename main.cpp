#include <iostream>
#include <locale>
#include <windows.h>
#include <ctime>           // Добавлено для работы с датой
#include "arrays_tasks.h"
#include "string_tasks.h"


void print_info() {
    std::cout << "Доступные команды:\n";
    std::cout << "0: help      - Показать это сообщение\n";
    std::cout << "1: arrays    - Работа с задачами по массивам\n";
    std::cout << "2: strings   - Работа со строками\n";
    std::cout << "3: matrix    - Работа с двухмерными массивами\n";
    std::cout << "4: sort      - Сортировки\n";
    std::cout << "5: files     - Работа с файлами\n";
    std::cout << "6: pointers  - Работа с указателями\n";
    std::cout << "7: dynamic   - Работа с динамической памятью\n";
    std::cout << "8: lists     - Задачи на односвязные списки\n";
    std::cout << "-1: exit     - Выйти из программы\n";
}

int main() {
    // Устанавливаем русскую локаль
    std::setlocale(LC_ALL, "RUS");

    while (true) {
        std::cout << "\nЭта программа создана для изучения различных возможностей C++ на примере задач разного уровня сложности.\n";
        print_info();

        int command;
        std::cout << "Введите команду: ";
        std::cin >> command;

        switch (command) {
        case 0:
            print_info();
            break;
        case 1:
            arrays::arraysMenu();
            break;
        case 2:
            // работа со строками
            string_tasks::string_menu();
            break;
        case 3:
            // работа с двухмерными массивами
            break;
        case 4:
            // сортировки
            break;
        case 5:
            // работа с файлами
            break;
        case 6:
            // работа с указателями
            break;
        case 7:
            // работа с динамической памятью
            break;
        case 8:
            // задачи на односвязные списки
            break;
        case 9:
			// работа с двусвязными списками
			break;
        case 10:
			// работа с деревьями
			break;
        case 11:
			// работа с хеш-таблицами
            break;
        case 12:
            // работа с графами
			break;
        case 13:
            // множествами
            break;
        case -1: {
            // Получаем текущую дату безопасно
            std::time_t t = std::time(nullptr);
            std::tm now;
            localtime_s(&now, &t);  // безопасная версия

            std::cout << "\nВыход из программы. До свидания!\n";
            std::cout << "Автор программы: Индюченко Никита\n";
            std::cout << "Ревизия: 1.0\n";
            std::cout << "Дата завершения: "
                << now.tm_mday << "."
                << (now.tm_mon + 1) << "."
                << (now.tm_year + 1900) << "\n";
            return 0;
        }
        default:
            std::cout << "Неверная команда!\n";
            break;
        }
    }

    return 0;
}
