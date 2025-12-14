#include <stdio.h>

int main() {
    FILE *file;
    char category[50];
    float amount;
    char line[100];

    file = fopen("expenses.txt", "a");  // append mode

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    printf("Enter expense category: ");
    scanf("%s", category);
    printf("Enter amount: ");
    scanf("%f", &amount);

    fprintf(file, "%s %.2f\n", category, amount);
    fclose(file);
    printf("\nExpense added successfully!\n\n");
    file = fopen("expenses.txt", "r");

    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    printf("----- All Expenses (expenses.txt) -----\n");

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);

    return 0;
}
