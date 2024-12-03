#include <stdio.h>
#include <string.h>


struct MenuItem 
{
    int id;
    char name[60];
    float price;
};


struct Order 
{
    int itemId;
    int quantity;
    float totalPrice;
};


void displayMenu(struct MenuItem menu[], int size);
void placeOrder(struct MenuItem menu[], int size, struct Order orders[], int *orderCount);
void displayOrders(struct Order orders[], int orderCount);

int main() 
{
    
    struct Menu Item menu[] = 
    {
        {1, "Pizza", 9.99},
        {2, "Burger", 5.99},
        {3, "Pasta", 7.99},
        {4, "Salad", 4.99}
    };
    int menuSize = sizeof(menu) / sizeof(menu[0])

    struct Order orders[10];
    int orderCount = 0;

    int choice;
    do 
    {
        printf("\n1. View Menu\n2. Place Order\n3. Display Orders\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                displayMenu(menu, menuSize);
                break;
            case 2:
                placeOrder(menu, menuSize, orders, &orderCount);
                break;
            case 3:
                displayOrders(orders, orderCount);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu(struct MenuItem menu[], int size) 
{
    printf("\nMenu:\n");
    for (int i = 0; i < size; i++) 
    {
        printf("%d. %s - $%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
}


void placeOrder(struct MenuItem menu[], int size, struct Order orders[], int *orderCount) 
{
    int itemId, quantity;
    printf("Enter the item ID to order: ");
    scanf("%d", &itemId);
    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    for (int i = 0; i < size; i++) 
    {
        if (menu[i].id == itemId) 
        {
            orders[*orderCount].itemId = itemId;
            orders[*orderCount].quantity = quantity;
            orders[*orderCount].totalPrice = menu[i].price * quantity;
            (*orderCount)++;
            printf("Order placed: %s x%d - $%.2f\n", menu[i].name, quantity, menu[i].price * quantity);
            return;
        }
    }
    printf("Invalid item ID.\n");
}

void displayOrders(struct Order orders[], int orderCount)
{
    printf("\nCurrent Orders:\n");
    for (int i = 0; i < orderCount; i++) {
        printf("Order %d: Item ID %d, Quantity %d, Total Price $%.2f\n", i + 1, orders[i].itemId, orders[i].quantity, orders[i].totalPrice);
    }

}