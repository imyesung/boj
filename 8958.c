#include <stdio.h>

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) {
        return 0;
    }

    while (T--) {
        char s[85];
        if (scanf("%s", s) != 1) {
            return 0;
        }

        int streak = 0;
        int score = 0;

        for (int i = 0; s[i] != '\0'; i++) {    // until null terminator
            if (s[i] == 'O') {
                streak++;    // streak = streak + 1
                score += streak;
            } else {
                streak = 0;
            }
        }
        printf("%d\n", score);
    }

    return 0;
}
