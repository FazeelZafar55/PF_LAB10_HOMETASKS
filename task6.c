#include <stdio.h>
#include <string.h>

int main() {
    char books[10][50];
    char search[50];
    int found = 0;

    printf("Enter 10 book titles:\n");
    for (int i = 0; i < 10; i++) {
        printf("Book %d: ", i + 1);
        scanf("%s", books[i]);   
    }
    printf("\nEnter a book title to search: ");
    scanf("%s", search);
    for (int i = 0; i < 10; i++) {
        if (strcmp(search, books[i]) == 0) {
            found = 1;
            break;
        }
    }
    if (found)
        printf("\nBook Found!\n");
    else
        printf("\nBook Not Found.\n");

    return 0;
}
