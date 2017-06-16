/************************************************************************************************************
 This is the first part of a random walk program. This program generates random numbers and used the numbers 
 to generate a delta x and y. From there delta x and y are normalize to form a random walk.
 ************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max 10000
#define seed 78111

int main() {

	int i;
	double x_q;
	double y_q;
	double r_w; //Varibles for delta x and y along with r_w which is the Euclidian metric between points 
	double x;
	double y;
	FILE *Data;
	Data = fopen("Walk1.txt", "w");

	srand48(seed);

	x = 0;
	y = 0;
	x_q = 0;
	y_q = 0;
	r_w = 0;

	for (i = 1; i <= max; i++) {
		x = (drand48() - 0.5) * 2;
		y = (drand48() - 0.5) * 2;
		r_w = sqrt(x * x + y * y);
		x_q += x / r_w;
		y_q += y / r_w;
		fprintf(Data, "%f\t%f\n", x_q, y_q);
	}

	fclose(Data);

	return 0;

}
