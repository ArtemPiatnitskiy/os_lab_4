#include <stdio.h>
#include "../include/lib1.h"

int main() {
    int command;
    
    while (1) {
        printf("Введите команду (1 - PrimeCount, 2 - E, exit - выход): ");
        
        if (scanf("%d", &command) != 1) {
            break;
        }
        
        if (command == 1) {
            printf("Введите два целых числа A и B: ");
            int A, B;
            scanf("%d %d", &A, &B);
            int result = PrimeCount(A, B);
            printf("Количество простых чисел: %d\n", result);
        } 
        else if (command == 2) {
            printf("Введите целое число x: ");
            int x;
            scanf("%d", &x);
            float result = E(x);
            printf("E(%d) = %f\n", x, result);
        }
    }
    
    return 0;
}