#include <stdio.h>

/* find_minimum_element( rows, cols, T )
   Given a table T with the provided number of rows and columns, 
   find and return the minimum element of T.
*/
int find_minimum_element( int rows, int cols, int T[rows][cols] );

/* print_table( rows, cols, T )
   Given a table T with the provided number of rows and columns, 
   print each element of T, with one row per line.
*/
void print_table( int rows, int cols, int T[rows][cols] );