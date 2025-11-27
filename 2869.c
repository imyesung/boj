#include <stdio.h>

int main(void) {
    int A, B, V;
    scanf("%d %d %d", &A, &B, &V);
    int day = (V - B + (A - B) - 1) / (A - B);
    printf ("%d\n", day);
    return 0;
}
