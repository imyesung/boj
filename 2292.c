#include <stdio.h>

int main(void) {
    long long N;
    if (scanf("%lld", &N) != 1) return 0;

    long long max = 1;   // last number in current ring
    long long ring = 1;  // current ring index (center is 1)
    while (max < N) {
        max += 6 * ring;
        ring++;
    }
    printf("%lld\n", ring); // rings passed incl. start/end
    return 0;
}
