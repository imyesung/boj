#include <stdio.h>
#include <string.h>

int main(void) {
    char s[101];
    int pos[26];
    for (int i = 0; i < 26; i++) {
        pos[i] = -1;
    }

    if (scanf("%100s", s) != 1) return 0;
    
    for (int i = 0; s[i]; ++i) {
        int idx = s[i] - 'a';    // Convert character to index 0-25
        if (pos[idx] == -1) pos[idx] = i; // Store first occurrence
    }

    for(int i = 0; i < 26; i++) {
        printf("%d", pos[i]);
        if(i < 25) printf(" ");
    }
    return 0;
}