
#include <stdio.h>

int main() {
    int arr[] = {3, 4, -1, 1};
    int n = 4;
    int i, j, found;

    for (i = 1; i <= n + 1; i++) {
        found = 0;

        for (j = 0; j < n; j++) {
            if (arr[j] == i) {
                found = 1;
                break;
            }
        }

        if (found == 0) {
            printf("First Missing Positive: %d", i);
            break;
        }
    }

    return 0;
}
