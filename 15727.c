#include <stdio.h>
// #include <math.h>

int main(void) {
    int L;
    scanf("%d", &L);

    printf("%d\n", (L + 4) / 5);
    // using ceil version
    // printf("%d\n", (int)ceil(L / 5.0));
    
    return 0;
}
