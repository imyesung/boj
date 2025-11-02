#include <stdio.h>

int main(void) {
    int N;
    if (scanf("%d", &N) != 1) {
        return 0;
    }

    int factorial = 1; // 0! and 1! are both 1
    for (int i = 2; i <= N; i++) {
        factorial *= i; // = factorial * i
    }
    printf("%d\n", factorial);
    return 0;
}