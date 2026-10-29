#include <stdio.h>

int main() {
    int arr[] = {3, 2, 1, 5, 6, 4};
    int n = 6, k = 2, temp;

    if (k < 1 || k > n) {
        printf("Invalid k");
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Kth largest element = %d", arr[n - k]);

    return 0;
}