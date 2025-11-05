#include <stdio.h>
#include <stdbool.h>

int main(void) {
    enum { N = 8 };
    int note[N];

    for (int i = 0; i < N; ++i) {
        if (scanf("%d", &note[i]) != 1)
        return 0;
    }

    bool asc = true, desc = true;                   // boolean flags
    for (int i = 0; i < N && (asc || desc); ++i) {  // early exit if both flags are false
        asc = asc && (note[i] == i + 1);            // logical AND with short-circuit (evaluate RHS only if needed)
        desc = desc && (note[i] == N - i);          // check strict descending pattern
    }

    puts(asc ? "ascending" : desc ? "descending" : "mixed");
    return 0;
}