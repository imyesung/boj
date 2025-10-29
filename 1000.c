#include <stdio.h>

int main(void) {
    int A, B;
    if (scanf("%d %d", &A, &B) != 2) return 0;
    printf("%d\n", A + B);
    return 0;
}