#include <stdio.h>
#include <math.h>
int doSequence(int i, int n, float a, float b);

int main () {
    int i,n, restart;
    float a, b, seq;
    restart = 0;
    i = 0;

    while (restart == 0) {
        printf("Please input in respective order:\nHow many terms you would like\nStarting term\nHow much to add to each term\nInvalid inputs will be skipped or counted as 0.");
        scanf("%i %f %f", &n, &a, &b);
        printf("Printing %i terms: a = %f, b = %f\n", n, a, b);

        doSequence(i, n, a, b);

        printf("\nWould you like to restart? Any character besides 0 for no, default is yes.");
        scanf("%i", &restart);
    }

    return 0;
}
/*
int doSequence(int i, int n, float a, float b)
{

    while (i<n) {
        int i,n, restart;
        float a, b, seq;
        restart = 0;
        i = 0;
        seq = a + i*b;
        printf("%f ", seq);
        i += 1;
    }

    printf("\nWould you like to restart? 1 for no, default is yes.");
    scanf("%i", &restart);

    return seq;

}
*/