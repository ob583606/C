#include <stdio.h>
#include <math.h>
#include "vector3.h"

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