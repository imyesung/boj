#include <stdio.h>

int multiply(int a, int b, int c){
    return a * b * c;
}

int main(void){
    int A, B, C;
    int result;
    int count[10] = {0,}; // initialize count array to 0

    if (scanf("%d", &A) != 1) {
        return 0;
    }
    if (scanf("%d", &B) != 1) {
        return 0;
    }
    if (scanf("%d", &C) != 1) {
        return 0;
    }

    result = multiply(A, B, C);
    while (result > 0) {
        int digit = result % 10;
        count[digit]++;
        result /= 10;    // Move to the next digit
    }
    for (int i = 0; i < 10; i++) {
        printf("%d\n", count[i]);
    }
    return 0;
}