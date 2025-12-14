#include <stdio.h>

int main() {
    FILE *file;
    char name[50];
    float price;
    int quantity;

    file = fopen("products.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    printf("Enter product name: ");
    scanf("%s", name);
    printf("Enter product price: ");
    scanf("%f", &price);
    printf("Enter product quantity: ");
    scanf("%d", &quantity);

    fprintf(file, "Product: %s | Price: %.2f | Quantity: %d\n", name, price, quantity);
    fclose(file);
    printf("Product data saved successfully to products.txt!\n");

    return 0;
}
