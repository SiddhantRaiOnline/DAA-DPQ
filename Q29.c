
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int n, i, left, right;
    int start = 0, maxLength = 1;

    printf("Enter a string: ");
    scanf("%99s", str);

    n = strlen(str);

    for (i = 0; i < n; i++) {

        left = i;
        right = i;

        while (left >= 0 && right < n && str[left] == str[right]) {
            if (right - left + 1 > maxLength) {
                maxLength = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }

        left = i;
        right = i + 1;

        while (left >= 0 && right < n && str[left] == str[right]) {
            if (right - left + 1 > maxLength) {
                maxLength = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }
    }

    printf("Longest Palindromic Substring: ");

    for (i = start; i < start + maxLength; i++) {
        printf("%c", str[i]);
    }

    printf("\nLength: %d", maxLength);

    return 0;
}
