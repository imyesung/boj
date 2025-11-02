#include <stdio.h>
/*
- Operator: A＠B = (A+B) × (A-B)  ==  A^2 − B^2
- Bounds:   1 ≤ A,B ≤ 100000  →  max |A＠B| ≈ 1e10  →  needs 64-bit
- I/O:      scanf("%lld %lld"), printf("%lld\n")
*/

int main(void) {
    long long A, B;                      // 64-bit inputs
    if (scanf("%lld %lld", &A, &B) != 2)
        return 0;

    long long sum    = A + B; 
    long long diff   = A - B; 
    long long result = sum * diff;       // (A+B)*(A-B) == A*A - B*B

    printf("%lld\n", result);
    return 0;
}