#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];
    int freq[256] = {0};
    int i, flag = 1;

    printf("Enter main string: ");
    scanf("%99s", s1);

    printf("Enter substring: ");
    scanf("%99s", s2);

    if (strlen(s1) != strlen(s2)) {
        printf("Not Anagram");
        return 0;
    }

    for (i = 0; s1[i] != '\0'; i++) {
        freq[(unsigned char)s1[i]]++;
        freq[(unsigned char)s2[i]]--;
    }

    for (i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("Anagram");
    else
        printf("Not Anagram");

    return 0;
}