/*****************************************************************************
 This is the main source file for a program that uses the OpenGL library to
 model 1-D Brownian motion of 2 particles
 *****************************************************************************/

#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <GL/glut.h>
#include "Brownian_Motion_Header.h"

void main(int argc, char** argv) {
	float motion;
	float motion_1;
	int i;

	printf("We will now generate 2 paths of Brownian Motion! \n");
	{
		InitGauss((int) time(NULL));
		motion = 0.0;
		points[0][0] = points[0][1] = 0.0;
		FILE* fp = NULL;
		fp = fopen("Project.txt", "w");
		fprintf(fp, "Index\tPoints \n\n");

		for (i = 1; i <= POINTS; i++) {
			motion += Gauss();
			points[i][0] = (float) i;
			points[i][1] = motion;
			fprintf(fp, "%.0f\t%f \n", points[i][0], points[i][1]);
		}
		fclose(fp);
		InitGauss_1((int) time(NULL));
		motion_1 = 0.0;
		points_1[0][0] = points_1[0][1] = 0.0;
		FILE* fp_1 = NULL;
		fp_1 = fopen("Project_1.txt", "w");
		fprintf(fp_1, "Index\tPoints_1 \n\n");
		for (i = 1; i < POINTS; i++) {
			motion_1 += Gauss_1();
			points_1[i][0] = (float) i;
			points_1[i][1] = motion_1;
			fprintf(fp_1, "%.0f\t%f \n", points_1[i][0], points_1[i][1]);
		}
		fclose(fp_1);
	}

	winLimit = 2.0 * sqrt((double) POINTS);

	/* Set graphics window parameters. */

	glutInit(&argc, argv);
	glutInitWindowSize(WINDOWSIZE, WINDOWSIZE);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Dual Brownian Motion Paths");
	glutDisplayFunc (display);
	gfxinit();
	glutMainLoop();
}

void InitGauss(int seed) { //Algorthim to generate Gaussian random numbers. First part. 

	Nrand = 4;
	Arand = RANDMAX;
	GaussAdd = sqrt(3.0 * (double) Nrand);
	GaussFac = 2.0 * GaussAdd / ((double) Nrand * (double) Arand);
	SEED(seed);
}

double Gauss() { //Second Part to Gaussian random number generator. 
	
	double sum;
	int i;

	sum = 0.0;
	for (i = 1; i <= Nrand; i++)
		sum += (double) RANDNUM();
	return (GaussFac * sum - GaussAdd);
}

void InitGauss_1(int seed_1) {
	Nrand_1 = 1;
	Arand_1 = RANDMAX;
	GaussAdd_1 = sqrt(2.3 * (double) Nrand_1);
	GaussFac_1 = 2.2 * GaussAdd_1 / ((double) Nrand_1 * (double) Arand_1);
	SEED(seed_1);
}

double Gauss_1() {
	
	double sum_1;
	int i;

	sum_1 = 0.0;
	for (i = 1; i <= Nrand_1; i++)
		sum_1 += (double) RANDNUM();
	return (GaussFac_1 * sum_1 - GaussAdd_1);
}

void gfxinit() {  //Creates the image

	int i, j;

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (double) (POINTS - 1), -winLimit, winLimit);
	glClearColor(0.0, 0.0, 0.0, 0.0); // Makes the background Black
	glColor3f(1.0, 0.0, 0.0); // Draws first line in Red
	glNewList(1, GL_COMPILE);
	glBegin (GL_LINE_STRIP); //Draws first line
	for (i = 0; i < POINTS; i++)
		glVertex2fv (points[i]);
	glEnd();
	glColor3f(255, 0.0, 255); //Draws second line in Magenta
	glNewList(1, GL_COMPILE);
	glBegin(GL_LINE_STRIP); //Draws second line
	for (j = 0; j < POINTS; j++)
		glVertex2fv (points_1[j]);
	glEnd();
	glEndList();
}

void display(void) { //Clears memory for image
	
	glClear (GL_COLOR_BUFFER_BIT);
	glCallList(1);
	glFlush();
}
