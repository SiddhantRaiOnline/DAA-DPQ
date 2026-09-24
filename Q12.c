#include <stdio.h>

int main(void) {
    int n;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (n == 0) {
        printf("New length: 0\n");
        return 0;
    }

    int uniqueCount = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[uniqueCount - 1]) {
            arr[uniqueCount] = arr[i];
            uniqueCount++;
        }
    }

    printf("New length: %d\n", uniqueCount);
    printf("Array without duplicates: ");

    for (int i = 0; i < uniqueCount; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}