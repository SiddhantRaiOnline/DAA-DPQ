#include <stdio.h>

int main() {
    int nums[] = {1, 2, 3, 1};
    int n = 4;
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[mid + 1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    printf("Peak element index: %d", left);

    return 0;
}