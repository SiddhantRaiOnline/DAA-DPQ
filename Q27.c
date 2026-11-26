
#include <stdio.h>

int main() {
    int parking[3][3] = {
        {1, 0, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int i, j, found = 0;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {

            if (parking[i][j] == 0) {
                parking[i][j] = 1;

                printf("Parking spot allocated!\n");
                printf("Row: %d\n", i + 1);
                printf("Column: %d\n", j + 1);

                found = 1;
                break;
            }
        }

        if (found == 1) {
            break;
        }
    }

    if (found == 0) {
        printf("Parking Full!\n");
    }

    printf("\nUpdated Parking Layout:\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", parking[i][j]);
        }
        printf("\n");
    }

    return 0;
}
