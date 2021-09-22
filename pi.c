/* pi.c
   CSC 111 - Fall 2021 - Assignment 2

   O. Brown - 22/09/2021 V00988269
*/

#include <stdio.h>
#include <math.h>

int main(){
    /* INPUT DATA */
    /* You may modify the values of each variable below, but DO NOT
       rename the variables, change their type or move the declarations. */

    int n = 20; //Number of terms in summation
    
    /* END OF INPUT DATA */
    /* Implement your solution below this line */

   double i, pi;
   i = 1;

   while (i <= n) {
      pi += (pow(-1, i+1)/(2*i-1))*((8*(pow(pow(3, -1), (2*i-1))))+(4*pow(pow(7, -1), (2*i)-1)));
      i += 1;
   }

   if (n == 1) {
      printf("With 1 term: pi = %lf", pi);
   }
   if (n < 1) {
      printf("Not enough terms to determine a value for pi.");
   }
   else {
      printf("With %i terms: pi = %.15f", n, pi);
   }

    return 0;
}