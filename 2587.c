#include <stdio.h>

int main(void) {
    int arr[5];
    int sum = 0;

    for (int i = 0; i < 5; ++i) {
        if (scanf("%d", &arr[i]) != 1) {
            return 0;
        }
        sum += arr[i];
    }

    // Selection sort to find the median
    for (int i = 0; i < 3; i++) {
        int min_idx = i;
        for (int j = i + 1; j < 5; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int tmp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = tmp;
        }
    }

    printf("%d\n", sum / 5);
    printf("%d\n", arr[2]);
    return 0;
}