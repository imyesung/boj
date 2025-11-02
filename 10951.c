#include <stdio.h>

int main(void) {
    int A, B;
    while (scanf("%d %d", &A, &B) == 2) { // read until EOF
        printf("%d\n", A + B);
    }
    return 0;
}