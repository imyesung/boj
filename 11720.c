#include <stdio.h>

int main(void){
    int N;
    char s[101]; // +1 for null terminator
    if (scanf("%d%100s", &N, s) != 2) return 0; // read N and string s

    int sum = 0; // initialize sum
    for (int i = 0; i < N; i++) { // iterate over first N characters
        sum += s[i] - '0'; // convert char to int and add to sum
    }
    printf("%d\n", sum); // output the sum with newline
    return 0;
}
