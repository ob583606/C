/* tuition.c
   CSC 111 - Fall 2021 - Assignment 1

   B. Bird - 08/05/2021
   (Put your name/StudentID/date here when you implement your solution)
*/

#include <stdio.h>

int main(){
    /* INPUT DATA */
    /* You may modify the values of each variable below, but DO NOT rename the variables or move the declarations. */

    double specialized_engineering_units = 1.5;
    double normal_units = 7.5;

    double cost_per_specialized_engineering_unit = 437.18;
    double cost_per_normal_unit = 395.08;
    
    /* END OF INPUT DATA */
    /* Implement your solution below this line */

    /* Created two variables that calculate the total cost of either special or regular engineering to make my printf statement that displays the total cost of your entire first
    year tuition look cleaner. */
    double total_cost_special_engineering = specialized_engineering_units * cost_per_specialized_engineering_unit;
    double total_cost_normal_engineering = normal_units * cost_per_normal_unit;

    /* The printf statements that display all of the outputs required. */
    printf("Specialized Engineering units: %.1f, Cost per unit: $%.2f, Total cost: $%.2f\n", specialized_engineering_units, cost_per_specialized_engineering_unit, total_cost_special_engineering);
    printf("Normal units: %.1f, Cost per unit: $%.2f, Total cost: $%.2f\n", normal_units, cost_per_normal_unit, total_cost_normal_engineering);
    printf("Total units: %.1f, Total tuition: $%.2f", normal_units + specialized_engineering_units, total_cost_normal_engineering + total_cost_special_engineering);

    return 0;
}


