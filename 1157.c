#include <stdio.h>

int main(void) {
    int freq[26] = {0};
    int c;

    while ((c = getchar()) != EOF && c != '\n') {
        if (c >= 'a' && c <= 'z') {
            c -= ('a' - 'A');       // normalize to uppercase
        }
        if (c >= 'A' && c <= 'Z') {
            ++freq[c - 'A'];
        }
    }

    int max_count = 0;
    int max_index = -1;
    int num_max = 0;

    for (int i = 0; i < 26; ++i) {
        if (freq[i] > max_count) {
            max_count = freq[i];
            max_index = i;
            num_max = 1;
        } else if (freq[i] == max_count) {
            if (freq[i] != 0) {
                ++num_max;
            }
        }
    }

    if (num_max >= 2) {
        printf("?\n");
    } else {
        printf("%c\n", 'A' + max_index);
    }
    
    return 0;
}
