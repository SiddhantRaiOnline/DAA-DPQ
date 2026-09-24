#include <stdio.h>
#include <string.h>

int main(void) {
    char password[100];
    char correctPassword[] = "hello123";

    while (1) {
        printf("Enter password: ");
        scanf("%99s", password);

        if (strcmp(password, correctPassword) == 0) {
            break;
        }

        printf("Incorrect password. Try again.\n");
    }

    printf("Login successful!\n");
    return 0;
}