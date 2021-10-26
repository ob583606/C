#include <stdio.h>

int main(){

    int an_array[10] = {31, 41, 59, 2, 65, 3, 58, 9, 79, 3};

    /* Task A: Print every element of the array above, separated by commas
	     Do not print a comma after the last element. */

    printf("Task A: ");
    int n = 0;
    while(n<9) {
        printf("%i, ", an_array[n]);
        n += 1;
    }
    printf("%i", an_array[n]);
    printf("\n");

    /* Task B: Print every second element of the array above, separated by commas
	     Do not print a comma after the last element. */

    printf("Task B: ");
    n = 0;
    while(n<7) {
        printf("%i, ", an_array[n]);
        n += 2;
    }
    printf("%i", an_array[n]);
    printf("\n");

    /* Task C: Print every element of the array above, in reverse order, separated
	     by commas. Do not print a comma after the last element. */

    printf("Task C: ");
    n = 9;
    while(n>0) {
        printf("%i, ", an_array[n]);
        n -= 1;
    }
    printf("%i", an_array[n]);
    printf("\n");


    /* Task D: Print all elements of the array above which are greater than or 
	       equal to 10, separated by commas. Do not print a comma after
	       the last element. */

    printf("Task D: ");
    n = 0;
    int x = 0;
    while(n<10) {
        while(an_array[n]>=10){
            if (x == 0){
                printf("%i", an_array[n]);
                x = 1;
                n += 1;
            }
            if (x != 0) {
                printf(", %i", an_array[n]);
                n += 1;
            }
        }
        n += 1;
    }
    printf("\n");

    return 0;
}