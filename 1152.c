#include <stdio.h>
int main(void) {
    char text[1000002];
    if (!fgets(text, sizeof(text), stdin)) { // Read a line of input
        return 0;
    }
    int count = 0;    // word count
    int in_word = 0;  // in a word flag
    for (int i = 0; text[i] != '\0'; ++i) {
        char c = text[i]; // current character
        if (c == ' ' || c == '\n' || c == '\t') {
            in_word = 0; // outside a word
        } else {
            if (!in_word) { // entering a word
                ++count;    // word count increment
                in_word = 1;
            }
        }
    }
    printf("%d\n", count);
    return 0;
} 