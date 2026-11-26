
#include <stdio.h>

int main() {
    int arr[] = {2, 0, 3, -2, -1, 0, 1};
    int n = 7;
    int i, j, k, sum;
    int a, b, c, temp;

    printf("Unique triplets:\n");

    for (i = 0; i < n - 2; i++) {
        for (j = i + 1; j < n - 1; j++) {
            for (k = j + 1; k < n; k++) {

                if (arr[i] + arr[j] + arr[k] == 0) {
                    a = arr[i];
                    b = arr[j];
                    c = arr[k];

                    if (a > b) {
                        temp = a;
                        a = b;
                        b = temp;
                    }

                    if (b > c) {
                        temp = b;
                        b = c;
                        c = temp;
                    }

                    if (a > b) {
                        temp = a;
                        a = b;
                        b = temp;
                    }

                    printf("%d %d %d\n", a, b, c);
                }
            }
        }
    }

    return 0;
}
