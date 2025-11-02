#include <stdio.h>

int verification_digit(const int *vals, int cnt) { // param 'vals': pointer to read-only ints
    int sum_sq = 0;                  // accumulator for sum of squares

    for (int i = 0; i < cnt; i++) {  // i = 0 ... cnt-1
        sum_sq += vals[i] * vals[i]; // vals[i] == *(vals+i): type-scaled ptr arithmetic + dereference
    }
    return sum_sq % 10;              // return modulo 10
}

int main(void) {
    enum { NUM_INPUTS = 5};          // compile-time constant (fixed length)
    int vals[NUM_INPUTS];            // block-local array; created on entry, destroyed on exit

    for (int i = 0; i < NUM_INPUTS; i++) {
        /* '&vals[i]' calculates the 'actual address (int*)' of the i-th element for scanf */
        if (scanf("%d", &vals[i]) != 1) {
            return 0;
        }
    }

    /* 'vals' decays to a pointer (&vals[0]) when passed to a function */
    int checksum = verification_digit(vals, NUM_INPUTS);
    printf("%d\n", checksum); // print the calculated checksum (0-9) using %d specifier
    return 0;
}