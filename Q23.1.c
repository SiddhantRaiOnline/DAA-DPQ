#include <stdio.h>

void bucketSort(int arr[], int n) {
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int bucket[10][100];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int index = (arr[i] * 10) / (max + 1);
        bucket[index][count[index]] = arr[i];
        count[index]++;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < count[i] - 1; j++) {
            for (int k = 0; k < count[i] - j - 1; k++) {
                if (bucket[i][k] > bucket[i][k + 1]) {
                    int temp = bucket[i][k];
                    bucket[i][k] = bucket[i][k + 1];
                    bucket[i][k + 1] = temp;
                }
            }
        }
    }

    int k = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[k] = bucket[i][j];
            k++;
        }
    }
}

int main() {
    int arr[] = {42, 32, 33, 52, 37, 47, 51};
    int n = 7;

    bucketSort(arr, n);

    printf("Sorted array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}