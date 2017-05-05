/**********************************************************************************
Homework 1 
This program will calculate the overflow and under flow of the computer it's ran on
Keep in mind that the number of interations might have to be increased when ran on 
more modern machines
**********************************************************************************/

#include <stdio.h> 
int choose;

//The first part of the program will ask if you want to run the over/under algorithm
//with ints, double or float precision
//After the user chooses then the algorothim is ran and results are printed

int main() 
{ 
  printf ("Please enter 1,2 or 3. 1=int 2=double 3=float\n");
  scanf ("%d", &choose); 

   if (choose ==1)
      {
      int under=1, over=1;
      int i; 
      
       for (i=0; i<250; i++)
        {
         under /=2; 
         over *=2;
         printf("%d. under: %d over: %d \n",i+1,under,over);
        } 
       }


    if (choose ==2) 
      { 
      double under=1, over=1; 
      int j; 
      
       for (j=0; j<1080; j++)
        {
         under /=2;
         over *=2;
         printf ("%d. under: %e over %e \n", j+1,under,over);
        }
       }

    if (choose ==3) 
      { 
      float under=1, over=1; 
      int k; 
      
       for (k=0; k<200; k++)
        {
         under /=2;
         over *=2;
         printf ("%d. under: %e over %e \n", k+1,under,over);
        } 
       }
return 0; 
}

