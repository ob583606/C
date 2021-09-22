#include <stdio.h>
#include <math.h>

int main () {

    float i, x, toAdd, total;
    i = 0;
    total = 1;
    toAdd = 1;
    while (i < 11) {

        toAdd = total - toAdd;
        total = toAdd + total;
        i += 1;
        printf("%.0f\n", toAdd, total);
    }

    return 0;
}

/* For the second portion of this exercise: NEEDS FIXING!

int main () {

    float x, toAdd, total;
    total = 1;
    toAdd = 1;
    while (total < 1000) {

        toAdd = total - toAdd;
        total = toAdd + total;
        printf("%.0f\n", toAdd, total);
    }

    return 0;
}
*/