cmake_minimum_required(VERSION 3.10)

# Название проекта
project(MyProject)

# Стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Автоматически находим все .cpp файлы в корне проекта
file(GLOB SOURCES "*.cpp")

# Создаём исполняемый файл
add_executable(MyProject ${SOURCES})
