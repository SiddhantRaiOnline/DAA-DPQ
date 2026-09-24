#include <stdio.h>

int main(void) {
    int n;

    printf("Enter number of bars: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Trapped water: 0\n");
        return 0;
    }

    int height[n];

    printf("Enter the heights: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
    }

    int left = 0;
    int right = n - 1;
    int leftMax = 0;
    int rightMax = 0;
    long long water = 0;

    while (left < right) {
        if (height[left] <= height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                water += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                water += rightMax - height[right];
            }
            right--;
        }
    }

    printf("Trapped water: %lld\n", water);

    return 0;
}