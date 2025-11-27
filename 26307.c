#include <stdio.h>

int main(void) {
    int H, M;
    if (scanf("%d %d", &H, &M) != 2) return 0;

    int T = H * 60 + M - 540; // Total minutes from 00:00 minus 09:00
    printf("%d\n", T < 0 ? 0 : T);
    return 0;
}
