#include <stdio.h>

int main(){

    int an_array[10] = {31, 41, 59, 2, 65, 3, 58, 9, 79, 3};

    int a_table[5][5] = {
			    {3,  14,   15,   9,    2},
			    {65,  3,   58, 979,    3},
			    {2,  38,   46,  26,    4},
			    {3,   3,    8,   3,    2},
			    {795, 0, 2884,   1, 9716}
			};

    /* Task A: Find and print the smallest element of an_array. */

    printf("Task A: ");
    int smallest = an_array[1];
    int* ps = &smallest;
    int n = 0;
    while (n <= 9) {
        if(an_array[n] < smallest) {
            *ps = an_array[n];
        }
        n += 1;
    }
    printf("Smallest element of an_array: %i\n", smallest);

    /* Task B: Find and print the index of the largest element of an_array. */

    printf("Task B: ");
    int largest = an_array[1];
    int* pl = &largest;
    n = 0;
    while (n <= 9) {
        if(an_array[n] > largest) {
            *pl = n;
        }
        n += 1;
    }
    printf("Largest element of an_array: %i\n", largest);

    /* Task C: Find and print the sum of all elements of an_array. */

    printf("Task C: ");
    int sum = 0;
    int* psu = &sum;
    n = 0;
    while (n <= 9) {
        *psu += an_array[n];
        n += 1;
    }

    printf("Sum of an_array: %i\n", sum);

    /* Task D: Find and print the smallest element of a_table. */

    printf("Task D: ");
    int tSmallest = a_table[1][1];
    int* psm = &tSmallest;
    int r = 0;
    int c = 0;
    while (r <= 4) {
        while (c <=4){
            if(a_table[r][c] < *psm) {
                *psm = a_table[r][c];
            }
            c += 1;
        }
        r += 1;
    }
    printf("Smallest element of a_table: %i\n", tSmallest);

    /* Task E: Find and print the index (row and column) of the largest element of a_table. */

    printf("Task E: ");
    int tLargest = a_table[1][1];
    int* pla = &tLargest;
    int rAddress, cAddress;
    int* pRadd = &rAddress;
    int* pCadd = &cAddress;
    r = 0;
    c = 0;
    while (r <= 4) {
        while (c <= 4){
            if(a_table[r][c] > *pla) {
                *pla = a_table[r][c];
                *pRadd = r;
                *pCadd = c;
            }
            c += 1;
        }
        r += 1;
    }
    printf("Largest element of a_table: %i [%i][%i]\n", tLargest, rAddress, cAddress);

    /* Task F: Find and print the number of occurrences of the element 3 in a_table. */

    printf("Task F: ");
    int isThree = 0;
    int* pit = &isThree;
    r = 0;
    c = 0;
    while (r <= 4) {
        while (c <=4){
            if(a_table[r][c] == 3) {
                *pit += 1;
            }
            c += 1;
        }
        r += 1;
    }
    printf("Number of 3's in a_table: %i\n", isThree);

    /* Task G: Print the index of the row whose sum is the smallest among all rows
	       of a_table. */

    printf("Task G: ");
    /* Your code here */


    return 0;
}