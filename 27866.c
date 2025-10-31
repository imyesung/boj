#include <stdio.h>

int main(void){
    char S[1000];
    int i;
    scanf("%s %d", S, &i);
    printf("%c\n", S[i - 1]);
    return 0;
}