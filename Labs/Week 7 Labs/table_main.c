#include <stdio.h>
#include "table_library.h"

int main(){

    //Create a 4 x 3 table T1
    int T1[4][3] = { {1,2,3},
		     {4,5,6},
		     {7,8,9},
		     {-6,1,0}
		   };

    //Create a 2 x 5 table T2
    int T2[2][5] = { {10, 20, 111, 116, 225},
		     {-370, -230, 0, 6, 10}
		   };

    printf("Minimum element in T1: %d\n", find_minimum_element(4, 3, T1) );
    printf("Minimum element in T2: %d\n", find_minimum_element(2, 5, T2) );

    printf("Printing T1:\n");
    print_table(4, 3, T1);

    printf("Printing T2:\n");
    print_table(2, 5, T2);

    return 0;
}