#include <stdio.h>
#include <limits.h>

double findMedianSortedArrays(int nums1[], int m, int nums2[], int n) {
    if (m > n) {
        return findMedianSortedArrays(nums2, n, nums1, m);
    }

    int left = 0;
    int right = m;
    int half = (m + n + 1) / 2;

    while (left <= right) {
        int i = left + (right - left) / 2;
        int j = half - i;

        long long left1 = (i == 0) ? LLONG_MIN : nums1[i - 1];
        long long right1 = (i == m) ? LLONG_MAX : nums1[i];
        long long left2 = (j == 0) ? LLONG_MIN : nums2[j - 1];
        long long right2 = (j == n) ? LLONG_MAX : nums2[j];

        if (left1 <= right2 && left2 <= right1) {
            long long maxLeft = (left1 > left2) ? left1 : left2;

            if ((m + n) % 2 == 1) {
                return (double)maxLeft;
            }

            long long minRight = (right1 < right2) ? right1 : right2;
            return (maxLeft + minRight) / 2.0;
        } else if (left1 > right2) {
            right = i - 1;
        } else {
            left = i + 1;
        }
    }

    return 0.0;
}

int main(void) {
    int m, n;

    scanf("%d %d", &m, &n);

    if (m < 0 || n < 0 || m + n == 0) {
        return 1;
    }

    int nums1[m > 0 ? m : 1];
    int nums2[n > 0 ? n : 1];

    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    printf("%.5f\n", findMedianSortedArrays(nums1, m, nums2, n));

    return 0;
}