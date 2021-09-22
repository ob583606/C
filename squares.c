/* squares.c

   B. Bird - 09/17/2021
*/

#include <stdio.h>
#include <math.h>

int main(){
    
    int x, y;
    float z;
    x = 5;
    y = 5;
    z = pow(x, y);

    printf("Start\n");
    printf("1 squared is 1\n");
    printf("2 squared is 4\n");
    printf("3 squared is 9\n");
    printf("4 squared is 16\n");
    printf("5 squared is %.0f\n", z);
    printf("End\n");
    
    
    return 0;
    
}