#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isSpecial(char ch) {
    return ch == '@' || ch == '#' || ch == '%' ||
           ch == '&' || ch == '?';
}

int isSecure(char password[]) {
    int length = strlen(password);
    int hasLower = 0;
    int hasUpperInside = 0;
    int hasDigitInside = 0;
    int hasSpecialInside = 0;

    if (length < 10) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (islower((unsigned char)password[i])) {
            hasLower = 1;
        }

        if (i > 0 && i < length - 1) {
            if (isupper((unsigned char)password[i])) {
                hasUpperInside = 1;
            }
            if (isdigit((unsigned char)password[i])) {
                hasDigitInside = 1;
            }
            if (isSpecial(password[i])) {
                hasSpecialInside = 1;
            }
        }
    }

    return hasLower && hasUpperInside && hasDigitInside && hasSpecialInside;
}

int main(void) {
    int count;
    char password[1000];

    printf("Enter number of passwords: ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        printf("Enter password %d: ", i + 1);
        scanf("%999s", password);

        if (isSecure(password)) {
            printf("Secure\n");
        } else {
            printf("Not secure\n");
        }
    }

    return 0;
}