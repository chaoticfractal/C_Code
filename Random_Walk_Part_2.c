/**********************************************************************************************************
This is the second part of the random walk program. In this part the program is used to simulate the 
distance covered by the "walker" to the theoretical distance traveled.
**********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define drand48 1.0/RAND_MAX*rand 
#define srand48 srand                 
#define max 10000
#define seed 78111

int main()
{
   
   double y; double r_t; 
   double x,nax,k,j,trials,i;
   FILE *Data1;			
   Data1 = fopen("Walk2.txt","w");
   nax=9000; 
   srand48(seed);                       
   x=0; y=0; r_t=0;     
   
   for (j=4; j<= nax; j=j+10) 
    {
     trials=0; 
      for (k=1;k<=floor(sqrt(j));++k) 
       {
        r_t=0; 
	 for (i=1; i<=j; i++) 
          {
           x = (drand48()-0.5)*2;     
           y = (drand48()-0.5)*2;      
           r_t += (x*x + y*y);       
          }
	trials+=r_t;
        if (k == floor(sqrt(j))) 
         {
	  fprintf(Data1, "%f\t%f\n", k,sqrt(trials/k));
         }
       }
     } 

   fclose(Data1);

return 0;

}
