#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main() {
    int command;
    int lib_choice = 1; // 1 - lib1, 2 - lib2

    void* handle = dlopen("./include/lib1.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Ошибка: %s\n", dlerror());
        return 1;
    }

    while(1) {
        printf("Введите команду (0 - сменить библиотеку(по умолчанию lib1), 1 - PrimeCount, 2 - E, exit - выход): ");
        if (scanf("%d", &command) != 1) {
            break;
        }

        if (command == 0) {
            dlclose(handle);
            lib_choice = (lib_choice == 1) ? 2 : 1;
            printf("Сменена библиотека на lib%d\n", lib_choice);
            handle = dlopen(lib_choice == 1 ? "./include/lib1.so" : "./include/lib2.so", RTLD_LAZY);
            if (!handle) {
                fprintf(stderr, "Ошибка при загрузке библиотеки: %s\n", dlerror());
                return 1;
            }
        }
        if (command == 1) {
            int (*PrimeCount)(int, int);
            PrimeCount = dlsym(handle, "PrimeCount");
            if (!PrimeCount) {
                fprintf(stderr, "Ошибка при загрузке функции: %s\n", dlerror());
                return 1;
            }

            printf("Введите два целых числа A и B: ");
            int A, B;
            scanf("%d %d", &A, &B);
            int result = PrimeCount(A, B);
            printf("Количество простых чисел: %d\n", result);
        } 
        else if (command == 2) {
            float (*E)(int);
            E = dlsym(handle, "E");
            if (!E) {
                fprintf(stderr, "Ошибка при загрузке функции: %s\n", dlerror());
                return 1;
            }
            printf("Введите целое число x: ");
            int x;
            scanf("%d", &x);
            float result = E(x);
            printf("E(%d) = %f\n", x, result);
        }
    }
    dlclose(handle);
    return 0;
}