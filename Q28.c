
#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of stairs: ");
    scanf("%d", &n);

    int dp[n + 1];

    dp[0] = 1;
    dp[1] = 1;

    for (i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    printf("Total distinct ways: %d", dp[n]);

    return 0;
}
