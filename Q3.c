#include <stdio.h>

int main(void) {
    int n;

    printf("Enter number of temperatures: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Longest increasing streak: 0\n");
        return 0;
    }

    int temperature;
    printf("Enter temperature 1: ");
    scanf("%d", &temperature);

    int currentStreak = 1;
    int longestStreak = 1;
    int previous = temperature;

    for (int i = 1; i < n; i++) {
        printf("Enter temperature %d: ", i + 1);
        scanf("%d", &temperature);

        if (temperature > previous) {
            currentStreak++;
        } else {
            currentStreak = 1;
        }

        if (currentStreak > longestStreak) {
            longestStreak = currentStreak;
        }

        previous = temperature;
    }

    printf("Longest increasing streak: %d\n", longestStreak);
    return 0;
}