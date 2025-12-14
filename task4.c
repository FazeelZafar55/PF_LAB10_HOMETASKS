#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char guests[5][50];    
    int rooms[5];
    char searchName[50];
    int found = 0;

    file = fopen("hotel.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    printf("Enter booking details for 5 guests:\n");
    for (int i = 0; i < 5; i++) {
        printf("\nGuest %d name: ", i + 1);
        scanf("%s", guests[i]);
        printf("Room number: ");
        scanf("%d", &rooms[i]);

        fprintf(file, "%s %d\n", guests[i], rooms[i]);
    }
    fclose(file);
    printf("\nEnter guest name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < 5; i++) {
        if (strcmp(searchName, guests[i]) == 0) {
            printf("\nGuest found!\n");
            printf("Name: %s\nRoom Number: %d\n", guests[i], rooms[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nGuest not found in records.\n");
    }
    return 0;
}
