/* weekday.c
   CSC 111 - Fall 2021 - Assignment 3

   O. Brown - V00988269 - 03/10/2021
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
   int restart, loops, year, month, day;
   restart = 1;
   loops = 0;

   while (restart != 0 & loops < 25) {
      //input the shit that you want to loop here
      
      printf("Please input a day, month, and year, in respective order, numerical value only.");
      scanf("%i", &day);
      scanf("%i", &month);
      scanf("%i", &year);

      // Declaring variables
      int isLeapYear, numDays, addMonth, total;

      // Checks if it is a leap year
      if (year%4 == 0) {
         if (year%100 == 0 && year%400 != 0){ 
            isLeapYear = 0;
         }
         else {
            isLeapYear = 1;
         }
      }

      // Checks how many days are in the month
      numDays = 31;
      if ( month == 4 || month == 6 || month == 9 || month == 11 ) {
         numDays = 30;
      }
      if (month == 2) {
         numDays = 28;
         if (isLeapYear == 1) {
            numDays = 29;
         }
      }

      // Checks to make sure date is valid
      if (year < 1 || year > 100000) {
         printf("Error: Invalid year");
         exit(0);
      }
      if (month < 1 || month > 12) {
         printf("Error: Invalid month");
         exit(0);
      }
      if (day > numDays || day < 1) {
         printf("Error: Invalid day");
         exit(0);
      }

      // Assigning variables
      addMonth = 4;
      
      /* Month table 🤢🤮 */
      if (month == 1 || month == 10) {
         addMonth = 1;
      }
      if (month == 4 || month == 7) {
         addMonth = 0;
      }
      if (month == 5) {
         addMonth = 2;
      }
      if (month == 6) {
         addMonth = 5;
      }
      if (month == 8) {
         addMonth = 3;
      }
      if (month == 9 || month == 12) {
         addMonth = 6;
      }
      if (month < 3 && isLeapYear == 1) {
         addMonth -= 1;
      }

      // Calculation
      total = (((year%100)/4) + day + addMonth - ((year/100)%4)*2 + year%100 + 12)%7;
      
      // Number to day of the week
      if (total == 0) {
         printf("%i-%i-%i: Sunday\n", year, month, day);
      }
      if (total == 1) {
         printf("%i-%i-%i: Monday\n", year, month, day);
      }
      if (total == 2) {
         printf("%i-%i-%i: Tuesday\n", year, month, day);
      }
      if (total == 3) {
         printf("%i-%i-%i: Wednesday\n", year, month, day);
      }
      if (total == 4) {
         printf("%i-%i-%i: Thursday\n", year, month, day);
      }
      if (total == 5) {
         printf("%i-%i-%i: Friday\n", year, month, day);
      }
      if (total == 6) {
         printf("%i-%i-%i: Saturday\n", year, month, day);
      }
      
      printf("Would you like to restart? Type \"0\" for no, any other number is yes. Please type a number. Retype any null inputs.\n");
      scanf("%i", &restart);
         
      loops +=1;
   }
   return(0);
}