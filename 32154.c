#include <stdio.h>

const int solved[10] = { 11, 9, 9, 9, 8, 8, 8, 8, 8, 8 };
const char *problems[10] = {
    "A B C D E F G H J L M",
    "A C E F G H I L M",
    "A C E F G H I L M",
    "A B C E F G H L M",
    "A C E F G H L M",
    "A C E F G H L M",
    "A C E F G H L M",
    "A C E F G H L M",
    "A C E F G H L M",
    "A B C F G H L M"
};

int main() {
    int N;
scanf("%d", &N);
printf("%d\n", solved[N - 1]);
puts(problems[N - 1]);
    return 0;
}
