#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    for (int five = N / 5; five >= 0; five--) {
        int rest = N - five * 5;
        if (rest % 3 == 0) {
            printf("%d\n", five + rest / 3);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
