// First c program, which is now my testing ground for functions.
#include <stdio.h>

void staircase(int n){
    int x = 0;
    printf("X");
    while (x < n) {
        while(0 < x);
        printf("-");
    }
    printf("x");
        x -= 1;
}

int equidistant(int a, int b, int c) {
    if (a == (b+c)/2 || b == (a+c)/2 || c == (a+b)/2) {
        return 1;
    }
    return 0;
}

int main() {

    equidistant(1, 1, 1);
    printf("1, 13, 8: %i\n3, 4, 5: %i", equidistant(1, 13, 8), equidistant(3, 4, 5));
    return 0;
    
}