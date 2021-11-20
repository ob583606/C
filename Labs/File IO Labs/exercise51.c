#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){

	FILE* input_file = fopen("numbers.txt", "r");

	if (input_file == NULL) {
        printf("File didn't open properly bozo");
        return 1;
    }

	double values = 0;
	double sum = 0; 
	double average = 0;
	double input = 0;

	while (fscanf(input_file, "%99lf", &input) == 1) {
		values += 1;
		sum += input;
	}
	
	fclose(input_file);

	average = sum/values;

	printf("Number of values: %.0lf, sum: %.2lf, average: %.2lf\n", values, sum, average);

    return 0;
}