#include <stdio.h>
#include <string.h>

int main() {
    char password[100];
    int length;
    int hasSpecial = 0;
    char specialChars[] = "!@#$%^&*()-_=+[]{};:'\",.<>/?|";

    printf("Enter password: ");
    scanf("%s", password);
    length = strlen(password);

    for (int i = 0; specialChars[i] != '\0'; i++) {
        if (strchr(password, specialChars[i]) != NULL) {
            hasSpecial = 1;
            break;
        }
    }
    if (length < 6) {
        printf("Password Strength: Weak\n");
    }
    else if (length >= 6 && length < 10 && hasSpecial == 0) {
        printf("Password Strength: Medium\n");
    }
    else if (length >= 10 && hasSpecial == 1) {
        printf("Password Strength: Strong\n");
    }
    else {
        printf("Password Strength: Medium\n");
    }

    return 0;
}
