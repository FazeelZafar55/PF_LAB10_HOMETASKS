#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char city[50];
    float temp;

    file = fopen("temperature.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }
    printf("Enter names and temperatures of 5 cities:\n");
    for (int i = 0; i < 5; i++) {
        printf("\nCity %d name: ", i + 1);
        scanf("%s", city);
        printf("Average temperature: ");
        scanf("%f", &temp);
        fprintf(file, "%s %.2f\n", city, temp);
    }
    fclose(file);
    file = fopen("temperature.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    char maxCity[50];
    float maxTemp = 0;
    while (fscanf(file, "%s %f", city, &temp) != EOF) {
        if (temp > maxTemp) {
            maxTemp = temp;
            strcpy(maxCity, city);
        }
    }
    fclose(file);
    printf("\nCity with the highest temperature:\n");
    printf("%s with %.2f C\n", maxCity, maxTemp);

    return 0;
}
