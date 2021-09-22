#include <stdio.h>
#include <math.h>

int main () {

    double i, total;
    i = 0;
    
    while (i > -11) {
        
        total += pow(2, i);
        i -= 1;

    }
    
    printf("Final sum: %.10lf ", total);

    return 0;
}