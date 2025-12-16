#include <stdio.h>

int main(void) {
    int A, B, C;

    while (1) {
        scanf("%d %d %d", &A, &B, &C);
        if (A == 0 && B == 0 && C == 0) break;
        
        int a2 = A * A;
        int b2 = B * B;
        int c2 = C * C;
        
        if (a2 + b2 == c2 || b2 + c2 == a2 || a2 + c2 == b2) {
            printf("right\n");
        } else {
            printf("wrong\n");
        }
    }
    
    return 0;
}
