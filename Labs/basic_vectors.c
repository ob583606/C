#include <stdio.h>
#include <math.h>

//dot_product(x1, y1, z1, x2, y2, z2)
//Compute and return the dot product of the vectors (x1, y1, z1) and (x2, y2, z2)
float dot_product( float x1, float y1, float z1,   float x2, float y2, float z2 ){
	return (x1*x2 + y1*y2 + z1*z2);
}


//cross_product(x1, y1, z1, x2, y2, z2, result_x, result_y, result_z)
//Compute the cross product of the vectors (x1, y1, z1) and (x2, y2, z2)
//and store the result using the pointers result_x, result_y and result_z
void cross_product( float x1, float y1, float z1,
		    float x2, float y2, float z2,
		    float* result_x, float* result_y, float* result_z){
	*result_x = (y1*z2 - z1*y2);
    *result_y = (z1*x2 - x1*z2);
    *result_z = (x1*y2 - y1*x2);
}

//norm(x, y, z)
//Compute and return the norm of the vector (x,y,z)
//You may want to use the sqrt() function from math.h (notice that it is included above).
float norm( float x, float y, float z ){
	return (sqrt(x*x + y*y + z*z));
}

int main(){

	float x1, y1, z1;
	float x2, y2, z2;
	float x3, y3, z3;

	x1 = 1;
	y1 = 2;
	z1 = 3;

	x2 = 4;
	y2 = 5;
	z2 = 6;

	float d = dot_product(x1,y1,z1, x2,y2,z2);

	cross_product(x1,y1,z1, x2,y2,z2, &x3,&y3,&z3);

	float n1 = norm(x1,y1,z1);
	float n2 = norm(x2,y2,z2);

	printf("v1 = (%f %f %f)\n", x1, y1, z1);
	printf("v2 = (%f %f %f)\n", x2, y2, z2);

	printf("v1 (dot) v2 = %f\n", d);
	printf("v3 = v1 x v2 = (%f %f %f)\n", x3, y3, z3);
	printf("norm(v1) = %f\n", n1);
	printf("norm(v2) = %f\n", n2);

	//Since (x3, y3, z3) is the cross product of v1 and v2, it should be
	//orthogonal to both v1 and v2 (so the dot product should be zero).
	float d13 = dot_product(x1,y1,z1, x3,y3,z3);
	float d23 = dot_product(x2,y2,z2, x3,y3,z3);

	printf("v1 (dot) v3 = %f\n", d13);
	printf("v2 (dot) v3 = %f\n", d23);

	return 0;
}