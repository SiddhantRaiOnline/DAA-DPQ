
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int main() {
    char s[1000], p[1000];
    char temp[1000], pattern[1000];
    int i, n, m;

    printf("Enter main string: ");
    scanf("%999s", s);

    printf("Enter pattern: ");
    scanf("%999s", p);

    n = strlen(s);
    m = strlen(p);

    if (m > n) {
        printf("No anagrams found");
        return 0;
    }

    strcpy(pattern, p);
    qsort(pattern, m, sizeof(char), compare);

    printf("Starting indices: ");

    for (i = 0; i <= n - m; i++) {
        strncpy(temp, s + i, m);
        temp[m] = '\0';

        qsort(temp, m, sizeof(char), compare);

        if (strcmp(temp, pattern) == 0) {
            printf("%d ", i);
        }
    }

    return 0;
}
