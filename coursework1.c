#include <stdio.h>
#include <string.h>

#define VAT_RATE 0.07
#define MAX_ORDER_ITEMS 50

// Structure to represent a menu item
typedef struct {
    int itemCode;
    char itemName[50];
    float itemPrice;
} FoodItem;

// Structure to represent an order
typedef struct {
    int itemCode;
    int quantity;
} CustomerOrder;

// Function prototypes
void showMenu(FoodItem menu[], int menuSize);
float computeBill(CustomerOrder orders[], int orderCount, FoodItem menu[], int menuSize, float *subtotal, float *vat);
void processOrder(FoodItem menu[], int menuSize);

int main() {
    // Define the menu
    FoodItem menu[] = {
        {201, "pillawwo", 7000},
        {202, "matooke", 5000},
        {203, "katoogo", 4500},
        {204, "meat", 3000},
        {205, "Soft Drink", 2500},
        {206, "chicken", 15000},
        {207, "beans", 4000}
    };
    int menuSize = sizeof(menu) / sizeof(menu[0]);

    // Start the ordering process
    processOrder(menu, menuSize);

    return 0;
}

// Function to display the menu
void showMenu(FoodItem menu[], int menuSize) {
    printf("Available Menu Items:\n");
    printf("Code\tItem Name\t\tPrice\n");
    printf("--------------------------------------\n");
    for (int i = 0; i < menuSize; i++) {
        printf("%d\t%-15s\tUGX.%.2f\n", menu[i].itemCode, menu[i].itemName, menu[i].itemPrice);
    }
    printf("\n");
}

// Function to calculate the total bill
float computeBill(CustomerOrder orders[], int orderCount, FoodItem menu[], int menuSize, float *subtotal, float *vat) {
    *subtotal = 0;

    for (int i = 0; i < orderCount; i++) {
        for (int j = 0; j < menuSize; j++) {
            if (orders[i].itemCode == menu[j].itemCode) {
                *subtotal += menu[j].itemPrice * orders[i].quantity;
                break;
            }
        }
    }

    *vat = *subtotal * VAT_RATE;
    return *subtotal + *vat;
}

// Function to handle the order process
void processOrder(FoodItem menu[], int menuSize) {
    CustomerOrder orders[MAX_ORDER_ITEMS];
    int orderCount = 0;
    char continueOrdering;

    printf("Welcome to Habibu Online Food Ordering System!\n");
    do {
        showMenu(menu, menuSize);

        printf("Enter the item code you want to order: ");
        scanf("%d", &orders[orderCount].itemCode);

        printf("Enter the quantity: ");
        scanf("%d", &orders[orderCount].quantity);

        orderCount++;

        printf("Would you like to order another item? (y/n): ");
        scanf(" %c", &continueOrdering);
    } while (continueOrdering == 'y' || continueOrdering == 'Y');

    // Calculate the bill
    float subtotal, vat, totalAmount;
    totalAmount = computeBill(orders, orderCount, menu, menuSize, &subtotal, &vat);

    // Display the receipt
    printf("\nYour Receipt:\n");
    printf("Code\tItem Name\t\tQuantity\tPrice\n");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < orderCount; i++) {
        for (int j = 0; j < menuSize; j++) {
            if (orders[i].itemCode == menu[j].itemCode) {
                printf("%d\t%-15s\t%d\t\t$%.2f\n", menu[j].itemCode, menu[j].itemName, orders[i].quantity, menu[j].itemPrice * orders[i].quantity);
                break;
            }
        }
    }
    printf("-------------------------------------------------------\n");
    printf("Subtotal:\t\t\t\t\t$%.2f\n", subtotal);
    printf("VAT (7%%):\t\t\t\t\t$%.2f\n", vat);
    printf("Total Amount:\t\t\t\t\t$%.2f\n", totalAmount);
    printf("Thank you for ordering with us!\n");
}