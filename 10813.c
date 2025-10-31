#include <stdio.h>

int main(void) {
    int N, M;                            // N = numbers of baskets(1..N), M = number of swaps
    if (scanf("%d %d", &N, &M) != 2)     // validation
        return 0;

    int basket[101];                     // 1-based indexing, max N=100 
    for (int i = 1; i <= N; i++)         // off-by-one: i < N → i <= N
        basket[i] = i;                   // initialize baskets

    for (int k = 0; k < M; k++) {        // M swaps
        int i, j;
        scanf("%d %d", &i, &j);
        int tmp = basket[i];             // 3-step swap
        basket[i] = basket[j];
        basket[j] = tmp;
    }

    for (int i = 1; i <= N; i++) {       // print results
        printf("%d", basket[i]);
        if (i < N) printf(" ");          // remove trailing space
    }
    printf("\n");
    return 0;
}
