#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%999s", s);

    int n = strlen(s);
    int max = 0;

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
            }
        }
    }

    printf("%d\n", max);

    return 0;
}