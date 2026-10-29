#include <stdio.h>

int main() {
    int nums[] = {3, 1, 2, 4};
    int n = 4;
    int left = 0;
    int right = n - 1;

    while (left < right) {
        if (nums[left] % 2 == 0) {
            left++;
        } else if (nums[right] % 2 != 0) {
            right--;
        } else {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }

    printf("Result: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}