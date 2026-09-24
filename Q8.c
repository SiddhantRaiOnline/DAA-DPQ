#include <stdio.h>

int main(void) {
    int rows, cols;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    if (rows <= 0 || cols <= 0) {
        printf("Matrix dimensions must be positive.\n");
        return 1;
    }

    int matrix[rows][cols];

    printf("Enter the matrix elements row by row:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    int first = 1;

    printf("Spiral order: [");

    while (top <= bottom && left <= right) {
        for (int col = left; col <= right; col++) {
            printf("%s%d", first ? "" : ", ", matrix[top][col]);
            first = 0;
        }
        top++;

        for (int row = top; row <= bottom; row++) {
            printf("%s%d", first ? "" : ", ", matrix[row][right]);
            first = 0;
        }
        right--;

        if (top <= bottom) {
            for (int col = right; col >= left; col--) {
                printf("%s%d", first ? "" : ", ", matrix[bottom][col]);
                first = 0;
            }
            bottom--;
        }

        if (left <= right) {
            for (int row = bottom; row >= top; row--) {
                printf("%s%d", first ? "" : ", ", matrix[row][left]);
                first = 0;
            }
            left++;
        }
    }

    printf("]\n");
    return 0;
}