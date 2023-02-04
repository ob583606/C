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

/* create_order(order_number, year, month, day, customer_name, price)
   Create and return an Order object which has been pre-filled with the
   provided parameters.
*/
Order create_order( int order_number, int year, int month, int day, char customer_name[], float price ){
    Order new_order; 
    strcpy(new_order.customer_name, customer_name);
    new_order.order_number = order_number;
    new_order.order_date.year = year;
    new_order.order_date.month = month;
    new_order.order_date.day = day;
    new_order.total_price = price;
    return new_order;
}

int main(){

    Order orderA = create_order(111, 2021, 11, 25, "Rebecca Raspberry", 6.10);
    Order orderB = create_order(116, 2021, 11, 29, "Fiona Framboise", 17.0);

    //Print each order
    print_order(orderA);
    print_order(orderB);

    //Now reassign orderB to have different details (notice that an initializer could not be used here)
    orderB = create_order(225, 2017, 10, 6, "Neal Naranja", 18.7);
    //Print the new order
    print_order(orderB);

    return 0;
}