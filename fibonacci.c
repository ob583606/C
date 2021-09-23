#include <stdio.h>

int main () {

    float i, x, toAdd, total;
    i = 0;
    total = 1;
    toAdd = 0;
    while (i < 10) {

        toAdd = total - toAdd;
        total = toAdd + total;
        i += 1;
        printf("%.0f ", toAdd);
    }

    return 0;
}
/*
  For the second portion of this exercise:

int main () {

    float x, toAdd, total;
    total = 1;
    toAdd = 0;
    while (total - toAdd < 1000) {
        toAdd = total - toAdd;
        total = toAdd + total;
        printf("%.0f ", toAdd);
    }

    return 0;
}
*/