#include <stdio.h>

int main(void) {
    int a;
    if (scanf("%d", &a) != 1) {
        return 0;
    }
    for (int i = a; i > 0; i--) {
        printf("%d\n", i);
    }
    return 0;
}
