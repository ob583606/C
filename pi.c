/* pi.c
   CSC 111 - Fall 2021 - Assignment 2

   O. Brown - 22/09/2021 V00988269
*/

#include <stdio.h>

int main(){
    /* INPUT DATA */
    /* You may modify the values of each variable below, but DO NOT
       rename the variables, change their type or move the declarations. */

    int n = 1; //Number of terms in summation
    
    /* END OF INPUT DATA */
    /* Implement your solution below this line */

   int OTLoop, OSLoop, NLoop;
   double i, negOne, oneThird, oneSeventh, pi;
   i = 1;
   pi = 0;

   /* Oh god. I am so sorry for anyone who has to look at this clusterfuck. */

   /* Initial while loop. Main purpose is adding pi into itself, or the summation to equal pi. */
   while (i <= n) {

      /* Disgusting amount of declaration of variables. Each labeled XLoop is for a different while loop,
      which is used for exponents without the pow() function. oneThird and oneSeventh are those gross decimal 
      approximations because for whatever reason, oneThird = 1/3; returns oneThird as 0.00000. */
      NLoop = 1;
      OTLoop = 1;
      OSLoop = 1;
      negOne = -1;
      oneThird = 1/3.0;
      oneSeventh = 1/7.0;

      /* First loop. They're all the same and I was debating making a user-defined function for this but didn't feel like it :) */
      while (OTLoop<(2*i-1)) {
         oneThird *= 1/3.0;
         OTLoop += 1;
      }
      while (OSLoop<(2*i-1)) {
         oneSeventh *= 1/7.0;
         OSLoop += 1;
      }
      while (NLoop<(i+1)) {
         negOne *= -1;
         NLoop += 1;
      }
      pi += (negOne/(2*i-1))*((8*oneThird)+(4*oneSeventh));
      i += 1;
   }

   /* Final print statements. */
   
   if (n < 1) {
      printf("Not enough terms to determine a value for pi.\n");
   }
   else {
      printf("With %i terms: pi = %.15f\n", n, pi);
   }
    return 0;
}