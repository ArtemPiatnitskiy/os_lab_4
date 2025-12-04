#include <stdio.h>
#include <math.h>
#include "../include/lib2.h"
#include <stdbool.h>
#include <stdlib.h>

int PrimeCount(int A, int B) {
    int count_primes = 0;
    bool* is_prime = (bool*)malloc((B + 1) * sizeof(bool));
    for (int i = 0; i <= B; ++i) {
        is_prime[i] = true;
    }

    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i * i <= B; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= B; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = A; i <= B; ++i) {
        if (is_prime[i]) {
            ++count_primes;
        }
    }
    free(is_prime);
    return count_primes;
}

float E(int x) {
    float sum = 0.0f;
    float fact = 1.0f;
    for (int n = 0; n < x; ++n) {
        sum += 1.0f / fact;
        fact *= (n + 1);
    }
    return sum;
}