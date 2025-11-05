#include <stdio.h>

int main(void) {
    enum { N = 8 };
    int note[N];

    for (int i = 0; i < N; ++i) {
        if (scanf("%d", &note[i]) != 1)
        return 0;
    }

    int asc = 1, desc = 1;

    for (int i = 0; i < N; ++i) {
        if (note[i] != i + 1) {
            asc = 0;
        }
        if (note[i] != N - i) {
            desc = 0;
        }
    }

    if (asc) {
        printf("ascending\n");
    } else if (desc) {
        printf("descending\n");
    }
    else printf("mixed\n");
    return 0;
}