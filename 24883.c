#include <stdio.h>

int main(void) {
    char c;
    scanf("%c", &c);
    puts(c == 'N' || c == 'n' ? "Naver D2" : "Naver Whale");
    return 0;
}
