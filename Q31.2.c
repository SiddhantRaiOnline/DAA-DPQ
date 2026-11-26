
#include <stdio.h>
#include <string.h>

int main() {
    char s[1000], p[1000];
    int count1[26] = {0};
    int count2[26] = {0};
    int n, m, i, j, flag;

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

    for (i = 0; i < m; i++) {
        count1[p[i] - 'a']++;
        count2[s[i] - 'a']++;
    }

    printf("Starting indices: ");

    for (i = 0; i <= n - m; i++) {
        flag = 1;

        for (j = 0; j < 26; j++) {
            if (count1[j] != count2[j]) {
                flag = 0;
                break;
            }
        }

        if (flag == 1) {
            printf("%d ", i);
        }

        if (i < n - m) {
            count2[s[i] - 'a']--;
            count2[s[i + m] - 'a']++;
        }
    }

    return 0;
}
