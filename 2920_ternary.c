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
        asc &= (note[i] == i + 1);
        desc &= (note[i] == N - i);
        if (!asc && !desc) break;
    }

    puts(asc ? "ascending" : desc ? "descending" : "mixed");
    return 0;
}