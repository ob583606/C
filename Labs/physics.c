#include <stdio.h>

int main() {
    
    /* Introduction of all the variables used in this program. */
    double a = 2;
    double t = 2;
    double v = 3;
    double d = v*t + a*t*t/2;
    
    /* Print statements that display the aforementioned variables and the desired result from the physics calculation. */
    printf("Using a = %f, t = %f, and v = %f\n", a, t, v); 
    printf("d = %f\n", d);
        
    return(0);
}