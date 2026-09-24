#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    int m, n;

    scanf("%d %d", &m, &n);

    if (m <= 0 || n <= 0) {
        return 1;
    }

    int arr1[m];
    int arr2[n];

    for (int i = 0; i < m; i++) {
        scanf("%d", &arr1[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    int i = 0;
    int j = 0;
    long long smallestDifference = LLONG_MAX;

    while (i < m && j < n) {
        long long difference = (long long)arr1[i] - arr2[j];
        if (difference < 0) {
            difference = -difference;
        }

        if (difference < smallestDifference) {
            smallestDifference = difference;
        }

        if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }

    printf("%lld\n", smallestDifference);

    return 0;
}