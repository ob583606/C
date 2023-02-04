#include <stdio.h>

int main(){

	float add, total, x;
    add = 0;
    total = 0;

	printf("Enter as many numbers as you would like to add:\n");

	x = scanf("%f", &add);

    while (x != 0) {
        total += add;
        x = scanf("%f", &add);
    }

	printf("The sum of the values is %lf.\n", total);

	return 0;
}