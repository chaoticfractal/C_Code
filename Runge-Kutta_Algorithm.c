/***********************************************************************************************
 This is a program that uses the Runge-Kutta algorithm to solve a nonlinear PDE
 In this case it's the potenial of an oscillator
 ***********************************************************************************************/

#include <stdio.h>
#include <math.h>

#define N 2					//number of equations
#define dx 0.01					//stepsize
#define MIN 0.0					//minimum x
#define MAX 5.0					// maximum x 
#define Pi 3.1415926535897932385E0		// Pi

int main() {
	void runge4(double x, double y[], double step);

	double x, y[N], v, k, yb, diff;
	int j, c;
	int p = 8;
	c = 0;
	k = 4.e0 * Pi * Pi;
	FILE *output;					//save data in rk4.txt
	output = fopen("rk4_a1.txt", "w");
	FILE *fo;
	fo = fopen("rk4_energy.txt", "a");

	double A = 1.0;					//Amplitude
	double w0 = 2.e0 * Pi;				 	//ang. velocity
	y[0] = A;						//initial position    
	y[1] = 0.0;						//initial velocity
	v = 1.0 / p * k * pow(A, p);
	for (x = MIN; x <= MAX; x += dx)
	{
		yb = y[0];
		runge4(x, y, dx);
		diff = y[0] - yb;
		if (fabs(y[0] - 1.0) < 0.01 & c == 0 & diff > 0) {
			fprintf(fo, "%d\t%f\t%f\n", p, x, v);
			c = 1;
		}
		fprintf(output, "%f\t%f\n", x, y[0]);	//position vs. time
	}
	printf("data stored in rk4_a1.txt\n");
	fclose(output);
	fclose(fo);
}

/* Runge-Kutta subroutine */
void runge4(double x, double y[], double step) {
	double f(double x, double y[], int i);
	double h = step / 2.0, 					//the midpoint
	t1[N], t2[N], t3[N], 				//temporary storage
	k1[N], k2[N], k3[N], k4[N]; 			//for Runge-Kutta
	int i;

	for (i = 0; i < N; i++)
		t1[i] = y[i] + 0.5 * (k1[i] = step * f(x, y, i));
	for (i = 0; i < N; i++)
		t2[i] = y[i] + 0.5 * (k2[i] = step * f(x + h, t1, i));
	for (i = 0; i < N; i++)
		t3[i] = y[i] + (k3[i] = step * f(x + h, t2, i));
	for (i = 0; i < N; i++)
		k4[i] = step * f(x + step, t3, i);

	for (i = 0; i < N; i++)
		y[i] += (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]) / 6.0;
}

double f(double x, double y[], int i) {

	double k_spring = 4.e0 * Pi * Pi, mass = 1.0, p = 8.0;
	double rhs;

	if (i == 0) {
		rhs = y[1];
	}
	if (i == 1) {
		rhs = -k_spring / mass * pow(fabs(y[0]), p - 1.0) * y[0] / fabs(y[0]);
	}

	return (rhs);					//RHS of ith equation
}
