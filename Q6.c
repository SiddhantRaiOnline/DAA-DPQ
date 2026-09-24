#include <stdio.h>

int main(void) {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            char letter = 'A' + (row + col) % 26;
            printf("%c", letter);

            if (col < n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}