#include <stdio.h>

int main(void) {
    char buf[102]; // max 100 characters + newline + null terminator
    while (fgets(buf, sizeof buf, stdin)) { // stream until EOF
        fputs(buf, stdout);
    }
    return 0;
}