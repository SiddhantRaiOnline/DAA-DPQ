#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Array size cannot be negative.\n");
        return 1;
    }

    int nums[n];
    int result[n];

    printf("Enter %d sorted integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int left = 0;
    int right = n - 1;

    for (int pos = n - 1; pos >= 0; pos--) {
        if (abs(nums[left]) > abs(nums[right])) {
            result[pos] = nums[left] * nums[left];
            left++;
        } else {
            result[pos] = nums[right] * nums[right];
            right--;
        }
    }

    printf("Sorted squares: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}