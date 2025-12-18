#include <stdio.h>

int eq(char *a, char *b) {
    for (int i = 0; i < 8; i++)
        if (a[i] != b[i]) return 0;
    return 1;
}

int main() {
    char s[10];
    scanf("%s", s);
    
    if (eq(s, "fdsajkl;") || eq(s, "jkl;fdsa")) {
        printf("in-out\n");
    } else if (eq(s, "asdf;lkj") || eq(s, ";lkjasdf")) {
        printf("out-in\n");
    } else if (eq(s, "asdfjkl;")) {
        printf("stairs\n");
    } else if (eq(s, ";lkjfdsa")) {
        printf("reverse\n");
    } else {
        printf("molu\n");
    }
    
    return 0;
}
