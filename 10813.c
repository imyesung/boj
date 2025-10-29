#include <stdio.h>

int main(void) {
    int N, M;                            // N = 바구니 개수(1..N), M = 교환 횟수
    if (scanf("%d %d", &N, &M) != 2)     // 첫 줄 입력 검증
        return 0;

    int basket[101];                     // 1-based 인덱스 사용
    for (int i = 1; i <= N; i++)         // off-by-one: i < N → i <= N
        basket[i] = i;                   // 초기 상태: basket[i] = i

    for (int k = 0; k < M; k++) {        // M회 교환
        int i, j;
        scanf("%d %d", &i, &j);
        int tmp = basket[i];             // 3-step swap
        basket[i] = basket[j];
        basket[j] = tmp;
    }

    for (int i = 1; i <= N; i++) {       // 결과 출력
        printf("%d", basket[i]);
        if (i < N) printf(" ");          // 마지막 뒤 공백 제거
    }
    printf("\n");
    return 0;
}
