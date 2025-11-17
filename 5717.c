#include <stdio.h>

int main(void) {
    int M, F;

    while (1) {
        if (scanf("%d %d", &M, &F) != 2) {
            return 0;
        }

        if (M == 0 && F == 0) {
            break;
        }

        printf("%d\n", M + F);
    }

    return 0;
}