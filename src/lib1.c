#include <stdio.h>
#include "../include/lib1.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>


int PrimeCount(int A, int B) {
    int count_primes = 0;
    for (int i = A; i <= B; ++i) {
        if (i < 2) {
            continue;
        }
        bool is_prime = true;

        for (int d = 2; d < i; d++) {
            if (i % d == 0) {
                is_prime = false;
                break;
            }
        }
        
        if (is_prime) {
            ++count_primes;
        }
    }
    return count_primes;
}

float E(int x) {
    return pow((1.0f + 1.0f / x), x);
}