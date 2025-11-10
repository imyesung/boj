#include <stdio.h>
#define MAX_N 15000

void insertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        int key = arr[i];
        /* Move all elements greater than key to one position */
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        /* Find a correct position for key */
        arr[j + 1] = key;
    }
}

int main(void) {
    int N, M;
    int values[MAX_N];

    if (scanf("%d", &N) != 1) {
        return 0;
    }
    if (scanf("%d", &M) != 1) {
        return 0;
    }
    
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &values[i]) != 1) {
            return 0;
        };
    }

    insertionSort(values, N); 

    // Two-pointer technique to find pairs summing to M
    int left = 0;
    int right = N - 1;
    int count = 0;
    while (left < right) {
        int sum = values[left] + values[right];
        if (sum == M) {
            count++;
            left++;
            right--;
        } else if (sum < M) {
            left++;
        } else {
            right--;
        }
    }
    printf("%d\n", count);
    return 0;
}