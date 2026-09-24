#include <stdio.h>

int main(void) {
    int n;

    printf("Enter the array size (odd number): ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        /* Align mid with the first index of a pair. */
        if (mid % 2 == 1) {
            mid--;
        }

        if (nums[mid] == nums[mid + 1]) {
            left = mid + 2;
        } else {
            right = mid;
        }
    }

    printf("Single element: %d\n", nums[left]);

    return 0;
}