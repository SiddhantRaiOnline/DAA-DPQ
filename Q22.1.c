#include <stdio.h>

int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int n = 5;
    int temp[n];
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            temp[j] = arr[i];
            j++;
        }
    }

    while (j < n) {
        temp[j] = 0;
        j++;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}