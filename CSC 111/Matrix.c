#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(16);
    int x = rand();

    printf("%i\n", x);
    printf("%i", x + 5);
    scanf("%i", &x);
    
    return 0;
    
}