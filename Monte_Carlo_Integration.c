/****************************************************************************************************
 This is a program that uses Monte Carlo integration to numerical integrate a simple 10-D function
 ****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define drand48 1.0/RAND_MAX*rand 
#define srand48 srand                    
#define max 8192			/* number of trials */

int main() {
	int i, j, program_mode;
	double n = 1.0, x, y = 0;
	printf("Please enter 1 to compute the integral as a function of the number of trials ");
	printf("or 2 to display the average value of the integral after 16 trials\n");
	scanf("%i", &program_mode);
	if (program_mode == 1) {
		FILE *output;
		output = fopen("Printed to 'HW12_Mode_1.txt'", "w");
		for (i = 1; i <= max; i++) {
		     x = 0;					 //reset x 
			for (j = 1; j <= 10; j++)
			     x += drand48();	                 //sum of 10 x values 
			     y += x * x;		         // square and sum up 
			if (i % (int) (pow(2.0, n)) == 0) {	 // save after 2, 4, 8, 16 ... 
			    n++;
		            fprintf(output, "%i\t\t%f\n", i, y / i);
			}
		}

		printf("HW12_Mode_1.txt\n");
		fclose(output);

	}

	if (program_mode == 2) {
		int trials = 16;
		for (i = 1; i <= trials; i++) {
		     x = 0;					//reset x 
			for (j = 1; j <= 10; j++)
			     x += drand48();	   //sum of 10 x values 
			     y += x * x;          // square and sum up 
			if (i == trials) {        // print at i=16 trials
			    printf("The average value after 16 trials is %f\n", y / i);

			}
		}
	}

	return 0;

}

