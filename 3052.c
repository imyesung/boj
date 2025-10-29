#include <stdio.h>

int main(void) {
    int used[42] = {0};  // 42개 나머지 존재 여부 표시 배열
    int count = 0;      // 서로 다른 나머지 개수

    for (int i = 0; i < 10; i++) {
        int x;  // 입력 값
        scanf("%d", &x);  // 값 입력
        int remainder = x % 42;  // 42로 나눈 나머지
        if (used[remainder] == 0) {
            used[remainder] = 1;  // 나머지 존재 표시
            count++;  // 서로 다른 나머지 개수 증가
        }
    }

    printf("%d\n", count);
    return 0;
}