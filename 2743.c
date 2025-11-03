#include <stdio.h>
#include <string.h>

int main(void) {
    enum { MAX_LEN = 100 } ;
    char s[MAX_LEN + 1]; // +1 for null terminator

    if (scanf("%100s", s) != 1) return 0;

    int len = (int)strlen(s);
    printf("%d\n", len);
    return 0;
}