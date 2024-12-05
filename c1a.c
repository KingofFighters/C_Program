#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to perform modular exponentiation
unsigned long mod_pow(unsigned long base, unsigned long exp, unsigned long mod) {
    unsigned long result = 1;
    base = base % mod;  // In case base is larger than mod
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

// Miller-Rabin primality test
int miller_rabin(unsigned long n, int k) {
    if (n <= 1) return 0;
    if (n == 2) return 1;  // 2 is prime
    if (n % 2 == 0) return 0;  // Even number greater than 2 is not prime

    // Write n - 1 as d * 2^r
    unsigned long d = n - 1;
    int r = 0;
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }

    // Test k random bases
    srand(time(NULL)); // Random seed for generating random numbers
    for (int i = 0; i < k; i++) {
        unsigned long a = 2 + rand() % (n - 3);  // Random number between 2 and n-2

        unsigned long x = mod_pow(a, d, n);
        if (x == 1 || x == n - 1) continue;

        int is_composite = 1;
        for (int j = 0; j < r - 1; j++) {
            x = mod_pow(x, 2, n);
            if (x == n - 1) {
                is_composite = 0;
                break;
            }
        }

        if (is_composite) return 0;  // n is composite
    }

    return 1;  // n is probably prime
}

int main() {
    unsigned long n;
    int k;

    printf("Enter a number to test primality: ");
    scanf("%lu", &n);
    printf("Enter number of iterations (k): ");
    scanf("%d", &k);

    if (miller_rabin(n, k))
        printf("%lu is probably prime.\n", n);
    else
        printf("%lu is composite.\n", n);

    return 0;
}
