//Prime or not using Miller-Rabin primality test.(Topic:Cryptography)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to count how many times 2 divides n and store the remaining part
int countnof2andremaining(int *n)    
{
    int count = 0;
    while (*n % 2 == 0) 
    {
        count++;
        *n /= 2;  // Divide n by 2 until it's no longer divisible by 2
    }
    return count;
}

// Function to compute (base^exp) % mod using iterative squaring
int mod_pow(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;  // Reduce base if it's larger than mod
    while (exp > 0) {
        if (exp % 2 == 1) {  // If exp is odd
            result = (result * base) % mod;
        }
        base = (base * base) % mod;  // Square the base
        exp = exp / 2;  // Divide exp by 2
    }
    return result;
}

int main() {
    int n;

    // Ask the user for a number
    printf("Enter a number: ");
    scanf("%d", &n);

    // First part: Count the number of times 2 divides n and display the remaining factor
    int orin = n;  // Store the original value of n in orin (this is the modulus)
    int k = countnof2andremaining(&n);  // Get the count of 2s and the remaining number
    int m = n;  // The remaining part of n after removing all factors of 2

    // Print the results for counting factors of 2
    printf("k = %d\n", k);  // Number of times 2 divides the original n
    printf("m = %d\n", m);   // Remaining number after removing all factors of 2

    // Second part: Generate a random number between 2 and (orin - 1) inclusive
    if (orin <= 2) {
        printf("The number must be greater than 2 to create a valid random range.\n");
        return 1;
    }

    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 2 and (orin - 1) inclusive
    int rn = (rand() % (orin - 2 + 1)) + 2;  // (orin - 2 + 1) gives the correct size of the range

    printf("Random number between 2 and %d: %d\n", orin - 1, rn);

    // Calculate b = pow(rn, m) % orin (note that m is based on the number after removing factors of 2)
    int b = mod_pow(rn, m, orin);  // Efficient exponentiation modulo orin
    printf("%d^%d %% %d = %d\n", rn, m, orin, b);

    // Check if b == ±1 mod orin
    if (b == 1 || b == orin - 1) {
        printf("Found b = ±1 mod orin, stopping. b = %d\n", b);

        // Check if b == 1: If yes, number is composite
        if (b == 1) {
            printf("The entered number is composite.\n");
        }

        // Check if b == orin - 1 (equivalent to -1 mod orin): If yes, number is prime
        else if (b == orin - 1) {
            printf("The entered number is prime.\n");
        }

        return 0;
    }

    // Continue squaring b if b != ±1 mod orin
    int b1 = mod_pow(b, 2, orin);  // b1 = pow(b, 2) % orin
    printf("b1 = pow(b, 2) %% %d = %d\n", orin, b1);

    // Check if b1 == ±1 mod orin
    if (b1 == 1 || b1 == orin - 1) {
        printf("Found b1 = ±1 mod orin, stopping. b1 = %d\n", b1);

        // Check if b1 == 1: If yes, number is composite
        if (b1 == 1) {
            printf("The entered number is composite.\n");
        }

        // Check if b1 == orin - 1 (equivalent to -1 mod orin): If yes, number is prime
        else if (b1 == orin - 1) {
            printf("The entered number is prime.\n");
        }

        return 0;
    }

    // Loop to continue squaring until we find ±1 mod orin
    int x = 2;
    while (1) {
        int bx = mod_pow(b, (1 << x), orin);  // b^(2^n) % orin (squaring)
        printf("b^2^%d = %d\n", x, bx);

        // Check if bn == ±1 mod orin
        if (bx == 1 || bx == orin - 1) {
            printf("Found b^2^%d = ±1 mod orin, stopping. bx = %d\n", x, bx);

            // Check if bx == 1: If yes, number is composite
            if (bx == 1) {
                printf("The entered number is composite.\n");
            }

            // Check if bx == orin - 1 (equivalent to -1 mod orin): If yes, number is prime
            else if (bx == orin - 1) {
                printf("The entered number is prime.\n");
            }

            break;
        }

        // Square again
        x++;
    }

    return 0;
}
