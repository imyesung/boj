#include <stdio.h>

int main(void){
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) { // process t test cases
        int r;    // repeat count
        char s[21];
        if (scanf("%d %20s", &r, s) != 2) return 0;
        
        for (int i = 0; s[i] != '\0'; i++) { // iterate over each character in s
            for (int j = 0; j < r; j++) {    // repeat r times
                putchar (s[i]);              // output character
            }
        }
        putchar('\n'); // newline after each test case
    }
    return 0;
}