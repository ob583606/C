#include <stdio.h>

int main(){

	float add, total;
    add = 0;
    total = 0;

	printf("Enter as many numbers as you would like to add:\n");

	scanf("%f", &add);

    while (add != 0) {
        total += add;
        scanf("%f", &add);
    }

	printf("The sum of the values is %lf.\n", total);

	return 0;
}