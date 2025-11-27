#include <stdio.h>

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) return 0;        // 테스트케이스 수
    while (T--) {
        int H, W, N;
        scanf("%d %d %d", &H, &W, &N);         // 층수, 가로 방수, N번째 손님
        int floor = (N - 1) % H + 1;           // 세로 우선 배정 → 층 번호
        int room  = (N - 1) / H + 1;           // 가로 증가 → 호수 번호
        printf("%d\n", floor * 100 + room);    // YYXX 형태로 출력
    }
    return 0;
}
