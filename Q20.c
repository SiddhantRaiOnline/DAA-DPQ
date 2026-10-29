#include <stdio.h>
#include <string.h>

int main() {
    char s[100], result[100];
    int max = 0, start = 0;

    printf("Enter string: ");
    scanf("%99s", s);

    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        int seen[256] = {0};
        int count = 0;

        for (int j = i; j < n; j++) {
            if (seen[(unsigned char)s[j]] == 1) {
                break;
            }

            seen[(unsigned char)s[j]] = 1;
            count++;

            if (count > max) {
                max = count;
                start = i;
            }
        }
    }

    for (int i = 0; i < max; i++) {
        result[i] = s[start + i];
    }

    result[max] = '\0';

    printf("Longest substring: %s\n", result);
    printf("Length: %d", max);

    return 0;
}