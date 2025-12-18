#include <stdio.h>

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    if (100 * n - m >= 0){
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
