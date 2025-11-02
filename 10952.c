#include <stdio.h>

int main(void) {
    int A, B;
    while (scanf("%d %d", &A, &B) == 2) {   // Read pairs until the terminating 0 0
        if (A == 0 && B == 0) { 
            break;
        }
        printf("%d\n", A + B);              // Output the sum of each pair
    }
    return 0;
}
