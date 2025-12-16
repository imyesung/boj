#include <unistd.h>

static int scan_rev3(void) {
    char c;
    int v = 0;
    int p = 1;
    int d = 0;

    for (;;) {
        if (read(0, &c, 1) != 1) return v;
        if (c >= '0' && c <= '9') break;
    }

    for (;;) {
        v += (c - '0') * p;
        p *= 10;
        if (++d == 3) break;
        if (read(0, &c, 1) != 1) break;
        if (c < '0' || c > '9') continue;
    }

    return v;
}

int main(void) {
    int a   = scan_rev3();
    int b   = scan_rev3();
    int max = (a > b) ? a : b;
    char out[4];

    out[2] = '0' + (max % 10);
    max /= 10;
    out[1] = '0' + (max % 10);
    max /= 10;
    out[0] = '0' + max;
    out[3] = '\n';

    write(1, out, 4);
    return 0;
}
