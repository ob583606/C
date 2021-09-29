#include <stdio.h>

void doSequence(int x, float y, float z);

int main () {
    int i, n, loops, restart;
    float a, b, seq;
    n = 10;
    a = 17;
    b = 1.87;

    doSequence(n, a, b);

    /* This is if we wanted user inputs to control the starting term, increment, and number of terms. Just for fun.

    restart = 1;
    loops = 0;
    while (restart != 0 & loops <10) {
        printf("Please input in respective order:\nHow many terms you would like;\nStarting term;\nHow much to add to each term;\nNull inputs will await a valid input, invalid inputs will be skipped or counted as 0.\n");
        scanf("%i %f %f", &n, &a, &b);

        printf("Printing %i terms: a = %f, b = %f\n", n, a, b);
        doSequence(i, n, a, b);

        printf("\nWould you like to restart? Type \"0\" for no, any other number is yes. Please type a number. Retype any null inputs.");
        scanf("%i", &restart);
        
        loops +=1;
    }
    */

    return 0;
}



void doSequence(int x, float y, float z) {
    float seq, w;
    w = 0;

    while (w<x) {
        seq = y + w*z;
        printf("%f ", seq);
        w += 1;
    }

}
