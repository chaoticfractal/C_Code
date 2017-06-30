/******************************************************
 Project Header File 
 Contains variables declarations and Macro definitions 
 ******************************************************/

#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <GL/glut.h>

#define POINTS     800
#define WINDOWSIZE 1000
#define SEED srandom
#define RANDNUM random
#define RANDMAX (1u<<31)-1 //Bit shifting Iu is unsigned value 

typedef GLfloat point[2];

point points[POINTS];
point points_1[POINTS];
int Arand, Nrand;
double GaussAdd, GaussFac, winLimit;
int Arand_1, Nrand_1;
double GaussAdd_1;
double GaussFac_1;
double winLimit_1;

void InitGauss(int seed);
double Gauss();
void gfxinit(void);
void display(void);
void gfxinit_1(void);
void display_1(void);
void InitGauss_1(int seed);
double Gauss_1();
