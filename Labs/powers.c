#include <stdio.h>

void compute_power (double base, int exponent) {
    int counter;
    double result;
    counter = 0;
    result = base;

    if(counter == 1) {

        printf("%lf to the power of 0 is 1.");
        return;
    }

    while(counter < exponent) {
        result *= base;
        counter += 1;
    }

    while(counter > exponent) {
        result /= base;
        counter += -1;
    }

    printf("%lf to the power of %i is %lf\n", base, exponent, result);
}

int main() {
    int exponent, restart, loops;
    double base;
    restart = 1;
    loops = 0;

    while (restart != 0 & loops <50) {
         printf("Please input an integer as a base and as an exponent, respectively.\n");
        scanf("%lf%i", &base, &exponent);

        compute_power(base, exponent);

        printf("Would you like to restart? Type \"0\" for no, any other number is yes. Please type a number. Retype any null inputs.");
        scanf("%i", &restart);
        
        loops +=1;
    }
   
    return 0;
}