#include <stdio.h>

int main(void) {
    int used[42] = {0};  // array for tracking remainders
    int count = 0;      // count of distinct remainders

    for (int i = 0; i < 10; i++) {
        int x;  // input value
        scanf("%d", &x);  // read value
        int remainder = x % 42;  // remainder when divided by 42
        if (used[remainder] == 0) {
            used[remainder] = 1;  // mark remainder as seen
            count++;  // increment count of distinct remainders
        }
    }

    printf("%d\n", count);
    return 0;
}