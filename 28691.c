#include <stdio.h>

int main(void) {
    char ch;
    if (scanf(" %c", &ch) != 1) {
        return 1;
    }

    switch (ch) {
        case 'M': puts("MatKor"); break;
        case 'W': puts("WiCys"); break;
        case 'C': puts("CyKor"); break;
        case 'A': puts("AlKor"); break;
        case '$': puts("$clear"); break;
        default: break;
    }
    return 0;
}
