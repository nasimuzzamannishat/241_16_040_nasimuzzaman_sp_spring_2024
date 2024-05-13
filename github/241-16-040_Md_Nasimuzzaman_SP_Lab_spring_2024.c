#include <stdio.h>
#include <string.h>

// Structure to store item details
struct Item {
    char name[50];
    int quantity;
    float price;
};

// Function to input item details
void inputItem(struct Item *item) {
    printf("Enter item name: ");
    scanf(" %[^\n]", item->name);
    printf("Enter quantity: ");
    scanf("%d", &item->quantity);
    printf("Enter price per unit: ");
    scanf("%f", &item->price);
}

// Function to calculate total cost
float calculateTotal(const struct Item *item) {
    return item->quantity * item->price;
}

int main() {
    int numItems;
    float totalAmount = 0.0;

    printf("Welcome to the Shopping Billing System!\n");
    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    struct Item items[numItems];

    for (int i = 0; i < numItems; i++) {
        printf("\nItem %d:\n", i + 1);
        inputItem(&items[i]);
        totalAmount += calculateTotal(&items[i]);
    }

    // Display invoice
    printf("\n        ===========Invoice:============\n");
    printf("------------------------------------------------------\n");
    printf("Item Name\tQuantity\tPrice\t\tTotal\n");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s\t\t%d\t\t%.2f\t\t%.2f\n", items[i].name, items[i].quantity, items[i].price, calculateTotal(&items[i]));
    }
    printf("--------------------------------------------------\n");
    printf("Total Amount: %.2f\n", totalAmount);

    return 0;
}
