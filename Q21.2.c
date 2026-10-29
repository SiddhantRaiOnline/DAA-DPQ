#include <stdio.h>
#include <limits.h>

int main() {
    int arr[] = {3, 2, 1, 5, 6, 4};
    int n = 6, k = 2;
    int largest = 0, index;

    if (k < 1 || k > n) {
        printf("Invalid k");
        return 0;
    }

    for (int i = 0; i < k; i++) {
        largest = INT_MIN;
        index = -1;

        for (int j = 0; j < n; j++) {
            if (arr[j] > largest) {
                largest = arr[j];
                index = j;
            }
        }

        arr[index] = INT_MIN;
    }

    printf("Kth largest element = %d", largest);

    return 0;
}