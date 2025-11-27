#include <stdio.h>

int main(void) {
    const int N = 1000;
    int mark[1001] = {1, 1};

    for (int p = 2; p * p <= N; p++) {
        if (!mark[p]) {
            for (int k = p * p; k <= N; k += p) {
                mark[k] = 1;
            }
        }
    }

    int n, v, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v);
        if (!mark[v]) cnt++;
    }

    printf("%d\n", cnt);
    return 0;
}
