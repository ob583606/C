#include <stdio.h>
#include <math.h>

int main () {

    int n, a;
    float b, seq;
    n = 0;
    a = 17;
    b = 1.87;

    printf("Printing 10 terms: a = %i, b = %f\n", a, b);

    while (n<10) {

        seq = a + n*b;
        printf("%f ", seq);
        n += 1;
    }

    printf("\nDone");

    return 0;
}