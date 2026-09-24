#include <stdio.h>

int main(void) {
    unsigned int number;

    printf("Enter a non-negative integer: ");
    scanf("%u", &number);

    if (number == 0) {
        printf("Binary representation: 0\n");
        printf("Number of 1s: 0\n");
        printf("Number of 0s: 1\n");
        printf("Longest consecutive run of 1s: 0\n");
        return 0;
    }

    int ones = 0;
    int zeros = 0;
    int currentRun = 0;
    int longestRun = 0;

    printf("Binary representation: ");

    /* Print bits from most significant to least significant. */
    int started = 0;
    for (int bit = sizeof(number) * 8 - 1; bit >= 0; bit--) {
        int value = (number >> bit) & 1U;

        if (value == 1) {
            started = 1;
            printf("1");
            ones++;
            currentRun++;
            if (currentRun > longestRun) {
                longestRun = currentRun;
            }
        } else if (started) {
            printf("0");
            zeros++;
            currentRun = 0;
        }
    }

    printf("\nNumber of 1s: %d\n", ones);
    printf("Number of 0s: %d\n", zeros);
    printf("Longest consecutive run of 1s: %d\n", longestRun);

    return 0;
}