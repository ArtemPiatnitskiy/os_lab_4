cmake_minimum_required(VERSION 3.10)
project(os_lab_4 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

# Создание разделяемых библиотек
add_library(1 SHARED src/lib1.c)
add_library(2 SHARED src/lib2.c)

# Линковка математической библиотеки
target_link_libraries(1 m)
target_link_libraries(2 m)

# Указываем директорию с заголовочными файлами
target_include_directories(1 PUBLIC include)
target_include_directories(2 PUBLIC include)

# Program1 - линковка на этапе компиляции
add_executable(program1 src/program1.c)
target_include_directories(program1 PRIVATE include)
target_link_libraries(program1 1 m)

# Program2 - динамическая загрузка
add_executable(program2 src/program2.c)
target_include_directories(program2 PRIVATE include)
target_link_libraries(program2 dl)

# Создание директории include в build и копирование .so файлов
add_custom_command(TARGET program2 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/include
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:1> ${CMAKE_BINARY_DIR}/include/
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:2> ${CMAKE_BINARY_DIR}/include/
)
