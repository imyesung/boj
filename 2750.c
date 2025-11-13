#include <stdio.h>
#define MIN_VAL    (-1000)
#define MAX_VAL    (1000)
#define RANGE      (MAX_VAL - MIN_VAL + 1)

int main(void) {
    int N;
    if (scanf("%d", &N) != 1)
        return 0;   

    int seen[RANGE] = {0};
    
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        seen[x - MIN_VAL] = 1;
    }

    for (int idx = 0; idx < RANGE; idx++) {
        if (seen[idx]) {
            int value = idx + MIN_VAL;
            printf("%d\n", value);
        }
    }
    
    return 0;
}