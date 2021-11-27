#include <stdio.h>
#include <string.h>


typedef struct {
    char name[100];
    float price;
} Product;

typedef struct {
    char customer_name[1000]; //Name of the customer placing the order
    int order_number; //The order number
    int num_contents; //Number of products present in the order
    Product contents[100]; //Array of products in the order (the first num_contents elements are valid)
} Order;

/* create_empty_order( customer_name, order_number)
   Create and return an Order object containing the provided
   name and order number, with the number of contents set to
   zero.
*/
Order create_empty_order( char customer_name[], int order_number ){
    Order new_order;
    strcpy(new_order.customer_name,customer_name);
    new_order.order_number = order_number;
    new_order.num_contents = 0;
    return new_order;
}

/* print_order( order_ptr )
   Given a pointer to an order, print the order in the format shown in the previous section.
*/
void print_order(Order* order_ptr){
    printf("Order %d: Placed by %s\n", 
		order_ptr->order_number, 
        order_ptr->customer_name);

    for (int i = 0; i < order_ptr->num_contents; i++){
	printf("    Product %s: $%.2f\n", order_ptr->contents[i].name, order_ptr->contents[i].price);
    }
}

/* get_order_cost( order_ptr )
   Given a pointer to an order, return the total cost of the order (by adding up the cost
   of each product in the order)
*/
float get_order_cost(Order* order_ptr){
    float total = 0;
    for (int i = 0; i < order_ptr->num_contents; i++){
	total += order_ptr->contents[i].price;
    }
    return total;
}

int main(){

    //Create an order with order number 111, containing two products.
    Order orderA = create_empty_order("Fiona Framboise", 111);
    orderA.num_contents = 2;

    strcpy(orderA.contents[0].name, "Pear");
    orderA.contents[0].price = 1.50;

    strcpy(orderA.contents[1].name, "Raspberries");
    orderA.contents[1].price = 6.10;


    //Create an order with order number 116, containing three products.
    Order orderB = create_empty_order("Hannah Hindbaer", 116);
    orderB.num_contents = 3;

    strcpy(orderB.contents[0].name, "Pineapple");
    orderB.contents[0].price = 0.60;

    strcpy(orderB.contents[1].name, "Grapefruit");
    orderB.contents[1].price = 1.06;

    strcpy(orderB.contents[2].name, "Pear");
    orderB.contents[2].price = 1.25;



    //Print orderA (including all of its contents)
    print_order(&orderA);


    //Print orderB (including all of its contents)
    print_order(&orderB);


    printf("Cost of order %d: $%.2f\n", orderA.order_number, get_order_cost(&orderA));
    printf("Cost of order %d: $%.2f\n", orderB.order_number, get_order_cost(&orderB));


    return 0;
}