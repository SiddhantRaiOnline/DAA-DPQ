#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);
    return i;
}

int quickSelect(int arr[], int low, int high, int target) {
    while (low <= high) {
        int p = partition(arr, low, high);

        if (p == target)
            return arr[p];

        if (p < target)
            low = p + 1;
        else
            high = p - 1;
    }

    return -1;
}

int main() {
    int arr[] = {3, 2, 1, 5, 6, 4};
    int n = 6, k = 2;

    if (k < 1 || k > n) {
        printf("Invalid k");
        return 0;
    }

    printf("Kth largest element = %d",
           quickSelect(arr, 0, n - 1, n - k));

    return 0;
}