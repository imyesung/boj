#include <stdio.h>

int main(void) {
    int r1, s;
    scanf("%d %d", &r1, &s);

    int r2 = 2 * s - r1;
    printf("%d\n", r2);
    return 0;
}