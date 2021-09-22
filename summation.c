#include <stdio.h>
#include <math.h>

int main () {

    double i, x, total;
    i = 0;
    
    while (i > -11) {
        
        total = total + pow(2, i);
        i -= 1;

    }
    
    printf("%.10lf ", total);

    return 0;
}