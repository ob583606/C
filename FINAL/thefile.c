#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){

    int a = 7;
int b = 5;
int z = (--a)*(b++);

    printf("%i ", z);
    printf("%i ", a);
    printf("%i ", b);

    return 0;
}