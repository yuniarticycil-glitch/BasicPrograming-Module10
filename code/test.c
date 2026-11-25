
#include <stdio.h>

// PART 1: Farm Data Types

typedef enum {
    CROP,
    ANIMAL_PRODUCT
} ProductType;

typedef union {
    float weight;   // used when type == CROP
    int quantity;   // used when type == ANIMAL_PRODUCT
} Production;

typedef struct {
    char name[30];
    ProductType type;
    Production production;
} FarmProduct;


// PART 2: Product Registration
void registerProduct(FarmProduct *ptr) {
    int choice;

    printf("Product Name: ");
    scanf(" %29[^\n]", ptr->name);   // reads a name with spaces, max 29 chars

    printf("Choose Product Type:\n");
    printf("1. Crop\n");
    printf("2. Animal Product\n");
    printf("Choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            ptr->type = CROP;
            break;

        case 2:
            ptr->type = ANIMAL_PRODUCT;
            break;
    }

    switch (ptr->type) {
        case CROP:
            printf("Harvest Weight (kg): ");
            scanf("%f", &ptr->production.weight);
            break;

        case ANIMAL_PRODUCT:
            printf("Product Quantity: ");
            scanf("%d", &ptr->production.quantity);
            break;
    }
}


// PART 3: Calculate Revenue
float calculateRevenue(FarmProduct *ptr) {
    switch (ptr->type) {
        case CROP:
            return ptr->production.weight * 8;

        case ANIMAL_PRODUCT:
            return ptr->production.quantity * 10;
    }

    return 0;
}


// PART 4: Display Product
void displayProduct(FarmProduct *ptr) {

    printf("Name: %s\n", ptr->name);

    switch (ptr->type) {
        case CROP:
            printf("Type: Crop\n");
            printf("Harvest Weight: %.2f kg\n", ptr->production.weight);
            break;

        case ANIMAL_PRODUCT:
            printf("Type: Animal Product\n");
            printf("Product Quantity: %d items\n", ptr->production.quantity);
            break;
    }

    printf("Revenue: $%.2f\n", calculateRevenue(ptr));
}


int main() {
    int count;
    float totalRevenue = 0;

    FarmProduct products[5];

    printf("=== FARM MANAGEMENT SYSTEM ===\n");

    printf("\nNumber of Products: ");
    scanf("%d", &count);

    // Register farm products
    for (int i = 0; i < count; i++) {
        printf("\n--- Product %d ---\n", i + 1);

        registerProduct(&products[i]);
    }

    // Display farm inventory
    printf("\n=== FARM INVENTORY ===\n");

    for (int i = 0; i < count; i++) {
        printf("\nProduct %d\n", i + 1);

        displayProduct(&products[i]);
    }

    // PART 5: Farm Summary
    for (int i = 0; i < count; i++) {
        totalRevenue += calculateRevenue(&products[i]);
    }

    printf("\n=== FARM SUMMARY ===\n");

    printf("Total Products: %d\n", count);

    printf("Total Farm Revenue: $%.2f\n", totalRevenue);

    return 0;
}

