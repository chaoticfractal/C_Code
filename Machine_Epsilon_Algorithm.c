/***********************************************************************************************
Homework 2
This program will calculate the machine precision (Machine Epsilon) of the machine it's ran on
Again you will change the number of interations on more modern machines
***********************************************************************************************/ 

#include <stdio.h>
int choose; 

//The program first lets you choose the level of percision you want to run
//With Float or Double and then will run the algorithm 

int main()
{
	printf ("Please enter 1 or 2. 1=float 2=double\n");
	scanf ("%d", &choose);
		if (choose==1)
		{
		float eps=1.0, one;
		int i;

		for(i=0; i<25; i++)
		  {
		   eps /=2;
		   one=1.0+eps;
		   printf ("%d %.18f\t %.16e \n" ,i,one, eps);
		  }  
		} 
		if (choose==2)
		{
		double eps=1.0, one;
		int j;

		for(j=0; j<60; j++)
		  {
		   eps /=2;
		   one=1.0+eps;
		   printf ("%d %.18lf\t %.16e \n" ,j,one, eps);
		  } 
		} 
return 0;
}
