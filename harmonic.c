#include <stdio.h>
#include <math.h>

int main () {

    float i;
    i = 1;
    
    while (i < 11) {
        
        printf("i = %f: Sequence value is %f\n", i, 1/i);
        i += 1;

    }
    
    return 0;
}