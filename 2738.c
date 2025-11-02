#include <stdio.h>

int main(void) {
    int n, m;
    int a[100][100], b[100][100];

    scanf("%d %d", &n, &m); // read first line for dimensions

    for(int i = 0; i < n; ++i) { // next n lines for first matrix
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]); // read first matrix
        }
    }
    for(int i = 0; i < n; ++i) { // next n lines for second matrix
        for (int j = 0; j < m; ++j) {
            scanf("%d", &b[i][j]); // read second matrix
        }
    }
    
    // output the sum of the two matrices
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d", a[i][j] + b[i][j]);
            if (j + 1 < m) {
                printf(" "); // space between row elements
            }
        }
        printf ("\n"); // new line after each row
    }
    return 0;
}