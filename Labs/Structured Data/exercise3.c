#include <stdio.h>
#include <string.h>

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    char customer_name[1000]; //Name of the customer placing the order
    int order_number; //The order number
    Date order_date; //The date on which the order was placed
    float total_price;
} Order;

/* print_order(the_order)
   Given an Order object, print the order's details in the same format
   described in the section above.
*/

void print_order(Order the_order){
    printf("Order %d: Placed by %s on %d/%d/%d (price: $%.2f)\n", 
		the_order.order_number, the_order.customer_name,
		the_order.order_date.month, the_order.order_date.day, the_order.order_date.year,
		the_order.total_price);
}

int main(){

    //Create an order with order number 111, placed on November 25, 2021
    Order orderA;
    strcpy(orderA.customer_name, "Rebecca Raspberry");
    orderA.order_number = 111;
    orderA.order_date.year = 2021;
    orderA.order_date.month = 11;
    orderA.order_date.day = 25;
    orderA.total_price = 6.10;

    //Make a second order, this time with order number 116, placed on November 29, 2021
    //This order is created using the { } initializer syntax. Notice the nested initializer
    //for the date.
    Order orderB = { "Fiona Framboise", 116, { 29, 11, 2021 }, 17.0 };

    print_order(orderA);
    print_order(orderB);

    return 0;
}