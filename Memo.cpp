#include <iostream>

// Пространство имен для справочной информации о размерах типов данных

// Необходимо создать header-файл Memo.h и перенести туда объявления из этого файла.

namespace DataInfo {

    struct ExampleStruct { char c; int i; double d; };

    class ExampleClass {
        char c;
        int i;
        double d;
    };

    void printDataTypeSizes() {
        std::cout << "Размеры основных типов данных в C++:\n";
        std::cout << "-----------------------------------\n";
        std::cout << "Тип данных       | Размер (в байтах)\n";
        std::cout << "-----------------------------------\n";
        std::cout << "bool            | " << sizeof(bool) << "\n";
        std::cout << "char            | " << sizeof(char) << "\n";
        std::cout << "wchar_t         | " << sizeof(wchar_t) << "\n";
        std::cout << "char16_t        | " << sizeof(char16_t) << "\n";
        std::cout << "char32_t        | " << sizeof(char32_t) << "\n";
        std::cout << "short           | " << sizeof(short) << "\n";
        std::cout << "int             | " << sizeof(int) << "\n";
        std::cout << "long            | " << sizeof(long) << "\n";
        std::cout << "long long       | " << sizeof(long long) << "\n";
        std::cout << "float           | " << sizeof(float) << "\n";
        std::cout << "double          | " << sizeof(double) << "\n";
        std::cout << "long double     | " << sizeof(long double) << "\n";
        std::cout << "int*            | " << sizeof(int*) << "\n";
        std::cout << "struct Example  | " << sizeof(ExampleStruct) << "\n";
        std::cout << "class Example   | " << sizeof(ExampleClass) << "\n";
        std::cout << "-----------------------------------\n";
    }

} // namespace DataInfo

