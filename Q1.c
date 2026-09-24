#include <stdio.h>

int main(void) {
    int number;
    int seen[10] = {0};

    printf("Enter a positive integer with nine distinct digits: ");
    scanf("%d", &number);

    while (number > 0) {
        int digit = number % 10;
        seen[digit] = 1;
        number /= 10;
    }

    for (int digit = 0; digit <= 9; digit++) {
        if (seen[digit] == 0) {
            printf("Missing digit: %d\n", digit);
            return 0;
        }
    }

    printf("No digit is missing.\n");
    return 0;
}