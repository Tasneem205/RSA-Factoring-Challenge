#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef unsigned long long int ulli; // Define `ulli` as unsigned long long int

// Function to find factors of the number
bool find_factors(ulli number, ulli *p, ulli *q) {
    for (ulli i = 2; i <= (ulli)sqrt((double)number); i++) {
        if (number % i == 0) {
            *p = i;          // First factor
            *q = number / i; // Second factor
            return true;     // Factorization successful
        }
    }
    return false; // No factors found (prime number)
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    ulli number;
    while (fscanf(file, "%llu", &number) == 1) { // Use %llu for ulli
        printf("the number is %llu\n", number);
        ulli p = 0, q = 0;

        // Find factors of the number
        if (find_factors(number, &p, &q)) {
            printf("%llu=%llu*%llu\n", number, p, q); // Use %llu for ulli
        } else {
            fprintf(stderr, "Error: Could not factorize %llu\n", number);
        }
    }

    fclose(file);
    return 0;
}

