#include <stdio.h>

int read_vector(float* px, float* py, float* pz){
	if (scanf("%f %f %f", &*px, &*py, &*pz) != 3) {
        return 0;
    }
    
    return 1;
}

int main(){

	float x1, y1, z1;
	float x2, y2, z2;

	int success;

	printf("Enter a vector:\n");
	success = read_vector(&x1, &y1, &z1);
	if (success == 0){
		printf("Couldn't read the first vector, exiting...\n");
		return 0; //Returning from main() will exit the program.
	}
	printf("Enter another vector:\n");
	success = read_vector(&x2, &y2, &z2);
	if (success == 0){
		printf("Couldn't read the second vector, exiting...\n");
		return 0;
	}

	printf("The first vector is: %f %f %f\n", x1, y1, z1);
	printf("The second vector is: %f %f %f\n", x2, y2, z2);

	return 0;
}