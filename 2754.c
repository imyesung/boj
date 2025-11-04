#include <stdio.h>

enum { A0_TENTHS = 40, STEP = 10, PLUS = 3, MINUS = -3 };  // scale: A0=4.0→40; step between letters=10; modifiers ±3

static inline int grade_to_tenths(char g, char m) {    // policy: letter g, modifier m → score in tenths
    if (g == 'F') return 0;                            // 'F' ignores modifier, always 0.0 → 0 tenths (early return)
    /*
     * ASCII/compatible assumption: 'A'..'D' are contiguous so (g - 'A') is a small offset 0..3.
     *
     * Char (hex)     Offset   base computation
     * 'A' (0x41)     0        40 - 0*10 = 40  → A0
     * 'B' (0x42)     1        40 - 1*10 = 30  → B0
     * 'C' (0x43)     2        40 - 2*10 = 20  → C0
     * 'D' (0x44)     3        40 - 3*10 = 10  → D0
     */
    if (g < 'A' || g > 'D') return -1;           // validate: only 'A'..'D' accepted here (F handled above)
    
    int base = A0_TENTHS - (g - 'A') * STEP;     // base score in tenths for letter grade
    int adj  = (m == '+') ? PLUS
              : (m == '-') ? MINUS
              : 0;                               // all other modifiers (including '0') → no adjustment
    return base + adj;
}

int main(void) {
    char s[3] = {0};                     // buffer: 1 letter + 1 modifier + NUL (3 bytes)
    if (scanf("%2s", s) != 1) return 0;  // %2s reads ≤2 bytes then appends NUL → safe to inspect s[1]

    char g = s[0];                       // extract grade letter ('A'..'D' or 'F')
    char m = s[1] ? s[1] : '0';          // normalize missing modifier to '0' (explicit no adjustment)

    int tenths = grade_to_tenths(g, m);  // apply policy to get tenths score (e.g., 37 = 3.7)
    if (tenths < 0) return 0;            // invalid letter -> quiet exit

    printf("%d.%d\n", tenths / 10, tenths % 10);  // print X.Y via integer split (avoid FP rounding edge cases)
    return 0;
}