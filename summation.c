#include <stdio.h>

int main () {

    int twoLoop;
    double i, twoMult, total;
    twoLoop = 0;
    i = 0;
    twoMult = 2;

    while (i<=10) {
        twoMult = 2;
        twoLoop = 0;

        while (twoLoop<=i) {
            twoMult /= 2.0;
            twoLoop += 1;
        }

        total += twoMult;
        i += 1;
    }
    
    printf("Final sum: %.10lf ", total);

    return 0;
}