#include <stdio.h>
#include <math.h>
#include "vector3.h"

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