/* pi.c
   CSC 111 - Fall 2021 - Assignment 2

   O. Brown - 21/09/2021 V00988269
   (Put your name/StudentID/date here when you implement your solution)
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

   float firstBit, secondBit, thirdBit, pi;
   n = 1;
   printf("%f, %f, %f, %f\n", firstBit, secondBit, thirdBit, pi);
   
   while (n < 21) {
      firstBit = (pow(-1, n+1)/(2*n-1));
      secondBit = (8*(pow(pow(3, -1), 2*n-1)));
      thirdBit = 4*pow(pow(7, -1), 2*n-1);
      pi += (pow(-1, n+1)/(2*n-1))*((8*(pow(pow(3, -1), 2*n-1)))+(4*pow(pow(7, -1), 2*n-1)));
      printf("%i. pi = %.15f\n", n, pi);
      n += 1;

   }


   if (n == 1) {

      printf("With 1 term: pi = %f", pi);

   }
   else {

      printf("With %i terms: pi = %.15f", n-1, pi);
      
   }

    return 0;
}


