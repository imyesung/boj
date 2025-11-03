/*
Bit indices:        b7 b6 b5 b4 b3 b2 b1 b0      (b5 flips 1↔0)
Mask 0x20:           0  0  1  0  0  0  0  0      = 0x20 = 0b0010 0000
────────────────────────────────────────────────────────────────────────────
Input 'T' (0x54):    0  1  0  1  0  1  0  0      = 0x54 = 0b0101 0100
XOR   0x20:          0  0  1  0  0  0  0  0
= Out 't'  (0x74):   0  1  1  1  0  1  0  0      = 0x74 = 0b0111 0100

Input 'a' (0x61):    0  1  1  0  0  0  0  1      = 0x61 = 0b0110 0001
XOR   0x20:          0  0  1  0  0  0  0  0
= Out 'A'  (0x41):   0  1  0  0  0  0  0  1      = 0x41 = 0b0100 0001

Input 'c' (0x63):    0  1  1  0  0  0  1  1      = 0x63 = 0b0110 0011
XOR   0x20:          0  0  1  0  0  0  0  0
= Out 'C'  (0x43):   0  1  0  0  0  0  1  1      = 0x43 = 0b0100 0011

Input 'O' (0x4F):    0  1  0  0  1  1  1  1      = 0x4F = 0b0100 1111
XOR   0x20:          0  0  1  0  0  0  0  0
= Out 'o'  (0x6F):   0  1  1  0  1  1  1  1      = 0x6F = 0b0110 1111
────────────────────────────────────────────────────────────────────────────
Final output string: "tACo"
*/
#include <stdio.h>
int main(void){
    int ch;
    while ((ch = getchar()) != EOF    // end of input (or read error)
    && ch != '\n'                     // LF (0x0A) treat as EOL
    && ch != '\r'                     // CR (0x0D) treat as EOL (CLRF compatibility)
) {
        if (('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z'))
            ch ^= 0x20;      // ASCII letters only: flip bit 0x20 -> swap case
        putchar(ch);
    }
    putchar('\n');
    return 0;
}