#include <stdio.h>

void print_arithmetic( double a, double b, int n ){

    printf("Sequence with a = %1.0lf, b = %lf and n = %i: ", a, b, n);

	int i;
	for(i = 0; i < n; i++){
		double sequence_term = a + i*b;
		printf("%.2f ", sequence_term); //The "%.2f" specifier prints values with 2 decimal places.
	}
	printf("\n");
}

int main() {

    print_arithmetic(6, 10, 17);
    print_arithmetic(1, 111, 5);
    print_arithmetic(0, 0.116, 3);


    return 0;
}